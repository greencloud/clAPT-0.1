/*
 * Copyright (C) 2016 Rasmus van Guido <goldenfinch.net@zoho.com>
 *
 * This file is part of SCapt.
 *
 * SCapt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SCapt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SCapt. If not, see <http://www.gnu.org/licenses/>.
 */

#define VERSION		        "0.1.9"
#define PROG_NAME	        "APT-ClamAV Binder Utility (clAPT)"
#define PROG_NAME_SHORT	        "clAPT"
#define CMD_NAME	        "clapt"
#define AUTHOR		        "Rasmus van Guido <goldenfinch.net@zoho.com>"

#define CMDBUF		        32
#define CMDBUF_L                128
#define APT_LOCK	        "/var/lib/apt/lists/lock"
#define VIR_DIR		        "SCQuarantine"
#define SCAN_SKIP_DIR	        "$HOME/SCQuarantine"
#define QUAR_DIR_PERM           0755
#define NEED_ROOT_MSG	        "E: You need to be root to run this utility."
#define CMD_ERROR               "Command failed to execute due to error(s)."
#define _OPT_YS		        'y'
#define _OPT_NO		        'n'

#define T_COMPLETE	        "--complete"
#define T_UPDATE_ONLY	        "--update"
#define T_UPGRADE_ONLY	        "--upgrade"
#define T_UPD_SMARTSCAN	        "--upscan"
#define T_FULL_SYS_SCAN	        "--fullscan"
#define T_CLEAN		        "--clean"
#define T_HELPER	        "--help"
#define T_VERSION	        "--version"
#define T_HELPER_SHORT	        "-h"
#define T_VERSION_SHORT	        "-V"
