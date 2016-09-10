#!/bin/sh
# Run this to generate all the initial makefiles, etc.

srcdir=`dirname $0`
test -z "$srcdir" && srcdir=.

PKG_NAME="clapt"

(test -f $srcdir/source/cab-main.c) || {
    echo -n "**Error**: Directory "\`$srcdir\'" does not look like the"
    echo " top-level $PKG_NAME directory"
    exit 1
}

which clamscan || {
    echo "This program requires ClamAV 0.9+. You can install it by typing:"
    echo "sudo apt install clamav"
    exit 1
}

which gnome-autogen.sh || {
    echo "This installation requires gnome-common. You can install it by typing:"
    echo "sudo apt install gnome-common"
    exit 1
}

REQUIRED_AUTOMAKE_VERSION=1.7
REQUIRED_INTLTOOL_VERSION=0.35.0
NOCONFIGURE=1 . gnome-autogen.sh
