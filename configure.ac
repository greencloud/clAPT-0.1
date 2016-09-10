# ****************
# Autoconf
# ****************
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT([clapt], [0.1], [goldenfinch.net@zoho.com])
AM_INIT_AUTOMAKE
AM_SILENT_RULES([yes])
AC_CONFIG_SRCDIR([source/cab-main.c])
AC_CONFIG_HEADERS([clapt.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_ISC_POSIX
AC_PROG_CC
AM_PROG_CC_STDC
AM_PROG_CC_C_O
AC_HEADER_STDC
AC_PROG_CXX

CAB_WARNINGS=-Wall
AC_SUBST(CAB_WARNINGS)

# ****************
# Translation
# ****************
IT_PROG_INTLTOOL([0.35.0])

GETTEXT_PACKAGE=AC_PACKAGE_NAME
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE", [Gettext package.])
AM_GLIB_GNU_GETTEXT

# ****************
# CFLAGS
# ****************
AC_SUBST(CAB_CFLAGS)

AC_CONFIG_FILES([Makefile
                 source/Makefile
                 po/Makefile.in
                 man/Makefile])
AC_OUTPUT

echo "
    clAPT .............. : Version $VERSION
    Location ........... : $prefix/bin
    CFLAGS ............. : $CFLAGS
"

echo "
    To compile and install, type:
    'sudo make install'
"
