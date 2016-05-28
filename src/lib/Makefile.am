# Process this file with automake to create Makefile.in
#  ___  _  ___  _____ _______  _____ ___.__.______   | Swiss Army Project
# / _/_| |_\_ \ \__  \\_  __ \/     <   |  |\____ \  | Project in C/C++ Language
# || |_   _| ||  / __ \|  | \/  Y Y  \___  ||  |_> > |
# ||_  |_|  _|| (____  /__|  |__|_|  / ____||   __/  | @author Luís Ferreira
# \__\     /__/      \/            \/\/     |__|     | @license GNU Public License v3
#
# Copyright (c) 2016 - Luís Ferreira. All right reserved
# More information in: https://github.com/ljmf00/ (Github Page)

AM_CPPFLAGS = -shared -Wall -Wextra -std=gnu++11 -fpic

lib_LTLIBRARIES = libswissap.la
libswissap_la_LDFLAGS= -shared -fPIC
libswissap_la_CFLAGS=-fPIC
libswissap_la_CPPFLAGS=-fPIC
libswissap_la_CXXFLAGS=-fPIC
libswissap_la_SOURCES = crypto/aes/aes.cpp		\
					crypto/md5/md5.cpp		\
					crypto/sha1/sha1.cpp		\
					crypto/sha2/sha2.cpp		\
					crypto/sha3/sha3.cpp		\
					convert/string/string.cpp	\
					math/pi/pi.cpp			\
					misc/file/file.cpp		\
					win32/netsocket/client.cpp	\
					win32/netsocket/server.cpp