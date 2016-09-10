/*
 * Copyright (C) 2016 Rasmus van Guido <goldenfinch.net@zoho.com>
 *
 * This file is part of clapt.
 *
 * clapt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * clapt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with clapt. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>
#include <wctype.h>

#ifndef clapt
#include "clapt.h"
#endif

void clapt_init( void );
void clapt_confirm( char *prog );
void clapt_lock_apt( char *prog );
void infc_files_dir( char *dirname, char *prog );

void clapt_complete( char *prog );
void apt_update( char *prog );
void apt_fullupgrade( char *prog );
void apt_clean( char *prog );
void clam_scan_util( char *prog, int targ );

void clapt_help( void );
void clapt_version( void );

int main( int argc, char *argv[] )
{
	int c;
	char cmd[CMDBUF], prog[CMDBUF];

	strcpy(prog, PROG_NAME_SHORT);

	if ( argc < 2 ) {
		clapt_confirm(prog);
		clapt_init();
		clapt_lock_apt(prog);

		/* Executing commands */
		apt_update( prog );
		apt_fullupgrade( prog );
		clam_scan_util( prog, 0 );
		apt_clean( prog );

	} else {
		strcpy( cmd, argv[1] ); /* store arguments in buffer */

		/*malloc( strlen(cmd) + 1 );*/

		if ( (strcmp(cmd, T_COMPLETE) == 0)
			|| (strcmp(cmd, T_UPDATE_ONLY) == 0)
			|| (strcmp(cmd, T_UPGRADE_ONLY) == 0)
			|| (strcmp(cmd, T_UPD_SMARTSCAN) == 0)
			|| (strcmp(cmd, T_FULL_SYS_SCAN) == 0)
			|| (strcmp(cmd, T_CLEAN) == 0) )
			clapt_init();

		if ( (c = strcmp(cmd, T_VERSION_SHORT)) == 0
			|| (c = strcmp(cmd, T_VERSION)) == 0 ) {
			clapt_version();

		} else if ( (c = strcmp(cmd, T_UPDATE_ONLY)) == 0 ) {
			clapt_lock_apt(prog);
			apt_update( prog );

		} else if ( (c = strcmp(cmd, T_UPGRADE_ONLY)) == 0 ) {
			clapt_lock_apt(prog);
			apt_fullupgrade( prog );

		} else if ( (c = strcmp(cmd, T_HELPER_SHORT)) == 0
			|| (c = strcmp(cmd, T_HELPER)) == 0 )
			clapt_help();

		else if ( (c = strcmp(cmd, T_UPD_SMARTSCAN)) == 0 )
			clam_scan_util( prog, 0 );

		else if ( (c = strcmp(cmd, T_COMPLETE)) == 0 )
			clapt_complete( prog );

		else if ( (c = strcmp(cmd, T_FULL_SYS_SCAN)) == 0 )
			clam_scan_util( prog, 1 );

		else if ( (c = strcmp(cmd, T_CLEAN)) == 0 )
			apt_clean( prog );

		else {
			printf("%s: The option selected is not valid. Please see '--help'.\n", prog);
			exit(1);
		}
	}

	printf("Thank you for using %s :)\n", prog);

	exit(1);

	return 0;
}

void clapt_init()
{
	/* Create a temporary file in /tmp/ containing the $USER name.
	   Check if program is being run as a sudoer, if not, Exit */

	/*system("touch /tmp/ssupdtusrfile");
	system("echo $HOME > /tmp/ssupdtusrfile");*/
}

void clapt_confirm( char *prog )
{
	/* Just a simple confirmatory statement whether to continue running the
	   program's entire routine or not */
        long s;
	char cnf;

	printf("%s: Running updates, upgrade, virus scan and cleaning. Continue? (Y/n) ", prog);
	cnf = getchar();

        if ( (s = strlen(&cnf)) > 0 ) {
                if ( tolower(cnf) == _OPT_NO && tolower(cnf) != _OPT_YS ) {
                        printf("%s: Exiting...\n", prog);
		        exit(1);
                }
        }
        
        printf("%c\n", cnf);
        exit(1);
}

void clapt_lock_apt( char *prog )
{
	/* Simply lock the APT directory for updates and upgrades */
	FILE *lf;
	int sc;
	char rm_cmd[CMDBUF];

	printf("%s: Locking apt list directory...\n", prog);

	if ( (lf = fopen(APT_LOCK, "r")) != NULL ) {
		strcpy(rm_cmd, "sleep 1 && rm -f ");
		strcat(rm_cmd, APT_LOCK);
		
		if ( (sc = system(rm_cmd)) == 0 )
		        printf("Done\n");
                else
		        printf("%s: %s", prog, CMD_ERROR);
	}
	putchar('\n');
}

void clapt_complete( char *prog )
{
	/* Run if --complete option is selected */
	clapt_confirm(prog);
	clapt_init();
	clapt_lock_apt(prog);

	apt_update( prog );
	apt_fullupgrade( prog );
	clam_scan_util( prog, 0 );
	apt_clean( prog );
}

void apt_update( char *prog )
{
	/* Run APT packages update  */
        int sc;

	printf("%s: Performing APT update...\n", prog);
	
	if ( (sc = system("sleep 1 && apt update")) == 0 )
	        printf("Done\n");
        else
                printf("%s: %s", prog, CMD_ERROR);
	
	putchar('\n');
}

void apt_fullupgrade( char *prog )
{
	/* Run upgrade to get newer version of installed packages */
        int sc;

	printf("%s: Performing APT full upgrade...\n", prog);

	if ( (sc = system("sleep 1 && apt full-upgrade")) == 0 )
        	printf("Done\n");
	else
	        printf("%s: %s", prog, CMD_ERROR);

	putchar('\n');
}

void clam_scan_util( char *prog, int targ )
{
	/* Updates ClamAV's virus database before performing a scan */
	int u, sc;
	char command[CMDBUF_L];

	infc_files_dir(VIR_DIR, prog);

	/* The whole scan command used for scanning HOME:
	   clamscan -vir --bell --move=$HOME/SCQuarantine --log=$HOME/SCQuarantine/Report.txt $HOME/\*
	   The whole scan command used for scanning Sys:
	   clamscan -vir --bell --move=$HOME/SCQuarantine --log=$HOME/SCQuarantine/Report.txt / */

	strcpy( command, "sleep 1 && clamscan -vir --bell --move=$HOME/" );
	strcat( command, VIR_DIR );
	strcat( command, " --log=$HOME/" );
	strcat( command, VIR_DIR );
	strcat( command, "/" );
	strcat( command, "SCReport-0" );
	/* CONCATINATE SOME RANDOM CODE HERE */
	strcat( command, ".txt " );

	printf("%s: Updating ClamAV virus database. Please wait...\n", prog);
	
	if ( (u = system("sleep 1 && freshclam --quiet ")) == 0 )
	        printf("Done\n");
	else
	        printf("%s: %s", prog, CMD_ERROR);
	
	putchar('\n');

	if ( targ > 0 ) { /* Target 0 = Home Dir, Target 1 = Root Dir */
		strcat( command, "/*" );
		printf("%s: Initiating full scan (might take a while). Please wait...\n", prog);
	} else {
		strcat( command, "$HOME/*" );
		printf("%s: Scanning home directory (recursively). Please wait...\n", prog);
	}

	/*malloc( strlen(command)+1 );*/

	if ( (sc = system(command)) == 0 )
		printf("%s: Please check the %s folder for any infected files.\n", prog, VIR_DIR);
	else
		printf("%s: Virus scanning failed due to error(s).\n", prog);

	/*free(command);*/
	putchar('\n');
}

void apt_clean( char *prog )
{
	/* Just a simple clean-up utility using apt */
        int sc;

	printf("%s: Cleaning and removing old packages...\n", prog);

	if ( (sc = system("sleep 1 && apt-get autoclean && apt autoremove")) == 0 )
	        printf("Done\n");
	else
	        printf("%s: %s", prog, CMD_ERROR);

	putchar('\n');
}

void infc_files_dir( char *dirname, char *prog )
{
	/* Check of the folder for infected files exists, if not create one */
	int cd, mk;

	if ( (cd = open(dirname, O_RDONLY, 0)) == -1 )
		if ( (mk = mkdir(dirname, QUAR_DIR_PERM)) != 0 ) {
			printf("%s: Unable to create quarantine folder: %s\n", prog, VIR_DIR);
			printf("%s: Please create one manually in your home directory. Thank you.\n", prog);
			exit(1);
		}
}

/* NOTES: Running this utility like so: $ sudo clapt
   is like running:

   $ sudo apt-get update --fix-missing && sudo apt-get upgrade && sudo freshclam --quiet \
   && mkdir ~/InfectedFilesDir && chmod -R 0644 ~/InfectedFilesDir \
   && sudo clamscan -vir --bell --move=$HOME/InfectedFilesDir --log=$HOME/InfectedFilesDir/Report.txt $HOME/ \
   && sudo apt-get autoclean && sudo apt-get autoremove

   in your terminal all at the same time. Just trying to make life a little easier, that's all. */
