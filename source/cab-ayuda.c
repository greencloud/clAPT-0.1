/*
 * Copyright (C) 2016 Rasmus van Guido <goldenfinch.net@zoho.com>
 *
 * This file is part of clAPT.
 *
 * clAPT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * clAPT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with clAPT. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef scapt
#include "clapt.h"
#endif

void clapt_help()
{
	/* Simply prints the help information on the screen, then Exit */

	printf("Usage: %s | [OPTION]\n", CMD_NAME);
	printf("Update and upgrade installed packages via APT. Also update ClamAV virus\n");
	printf("database before performing a thorough scanning on either the Home or\n");
	printf("root directory.\n\n");

	printf("You can run %s without using any of the options below for a complete\n", CMD_NAME);
	printf("routine. However if you want to target specific tasks, please refer to\n");
	printf("the available options below:\n");
	printf("      --complete\tperform a full system update and smart scan\n");
	printf("      --update\t\tupdate packages only (ie. apt-get update)\n");
	printf("      --upgrade\t\tupgrade packages only (ie. apt-get upgrade)\n");
	printf("      --upscan\t\tupdate ClamAV and perform smart scan\n");
	printf("      --fullscan\tperform a full system scan(might take hours)\n");
	printf("      --clean\t\tclean/remove old packages to free space\n");
	printf("  -h, --help\t\tdisplay this help and exit\n");
	printf("  -V, --version\t\toutput version information and exit\n\n");

	printf("You need to be root to run this utility. All infected files will\n");
	printf("be moved automatically to a folder called '%s' inside the client's home\n", VIR_DIR);
	printf("directory.\n");
	exit(1);
}
