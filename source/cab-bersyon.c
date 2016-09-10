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

#ifndef clapt
#include "clapt.h"
#endif

void clapt_version()
{
        /* Simply print the program version on the screen, then Exit */

        printf("GNU %s %s\n\n", PROG_NAME, VERSION);
	printf("Copyright (C) 2016. %s\n", AUTHOR);
	printf("License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>\n");
	printf("This is free software: you are free to change and redistribute it.\n");
	printf("There is NO WARRANTY, to the extent permitted by law.\n");
	exit(1);
}
