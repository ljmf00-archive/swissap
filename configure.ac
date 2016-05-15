# -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
#  ___  _  ___  _____ _______  _____ ___.__.______   | Swiss Army Project
# / _/_| |_\_ \ \__  \\_  __ \/     <   |  |\____ \  | Project in C/C++ Language
# || |_   _| ||  / __ \|  | \/  Y Y  \___  ||  |_> > |
# ||_  |_|  _|| (____  /__|  |__|_|  / ____||   __/  | @author Luís Ferreira
# \__\     /__/      \/            \/\/     |__|     | @license GNU Public License v3
#
# Copyright (c) 2016 - Luís Ferreira. All right reserved
# More information in: https://github.com/ljmf00/ (Github Page)

AC_PREREQ([2.68])
AC_INIT([swissap], [0.01], [lsferreira169@gmail.com],
	[swissap], [http://github.com/ljmf00/swissap/])

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_PROG_LIBTOOL

AC_HEADER_STDBOOL
AC_C_CONST

AC_CONFIG_SRCDIR([src/core/main.c])
AC_CONFIG_HEADERS([src/core/errors.h])
AC_CONFIG_FILES([
	Makefile
	src/Makefile
	src/core/Makefile
	src/lib/Makefile
])

AC_OUTPUT
