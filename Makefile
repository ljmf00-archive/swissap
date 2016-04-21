# -*- Makefile -*- 
#  ___  _  ___  _____ _______  _____ ___.__.______   | Swiss Army Project
# / _/_| |_\_ \ \__  \\_  __ \/     <   |  |\____ \  | Project in C/C++ Language
# || |_   _| ||  / __ \|  | \/  Y Y  \___  ||  |_> > |
# ||_  |_|  _|| (____  /__|  |__|_|  / ____||   __/  | @author Luís Ferreira
# \__\     /__/      \/            \/\/     |__|     | @license GNU Public License v3
#
# Copyright (c) 2016 - Luís Ferreira. All right reserved
# More information in: https://github.com/ljmf00/ (Github Page)

NAME = bss
CC = gcc
CXX = g++
CXX11 = -std=gnu++11
CFLAGS = -Wall -Wextra
RM = rm -rf
MKDIR = mkdir -p
LIBEXT = .so
EXECFILE = swissap


all: debug cleanobj

debug: clean mkdirstep build

debug_script: mkdirstep build_lib build_script

debug_windows: win32_build win64_build

windows: LIBEXT = .dll
windows: EXECFILE = swissap.exe
windows: win32_build win64_build cleanobj

win32_build: CC = i686-w64-mingw32-gcc
win32_build: CXX = i686-w64-mingw32-g++
win32_build: debug

win64_build: CC = x86_64-w64-mingw32-gcc
win64_build: CXX = x86_64-w64-mingw32-g++
win64_build: debug

mkdirstep: mkdirstep_master mkdirstep_lib

mkdirstep_master:
	$(MKDIR) bin
	$(MKDIR) bin/obj

mkdirstep_lib:
	$(MKDIR) bin/obj/crypto
	$(MKDIR) bin/obj/convert
	$(MKDIR) bin/obj/math
	$(MKDIR) bin/obj/win32
	$(MKDIR) bin/obj/win32/netsocket

build: build_lib build_script

build_lib:
	$(CXX) $(CFLAGS) -c -fpic src/lib/crypto/sha1/sha1.cpp -o bin/obj/crypto/sha1.o
	$(CXX) $(CFLAGS) -c -fpic src/lib/crypto/sha2/sha2.cpp -o bin/obj/crypto/sha2.o
	$(CXX) $(CFLAGS) -c -fpic src/lib/crypto/sha3/sha3.cpp -o bin/obj/crypto/sha3.o
	$(CXX) $(CFLAGS) -c -fpic src/lib/crypto/md5/md5.cpp -o bin/obj/crypto/md5.o
	$(CXX) $(CFLAGS) $(CXX11) -c -fpic src/lib/crypto/aes/aes.cpp -o bin/obj/crypto/aes.o
	$(CXX) $(CFLAGS) -c -fpic src/lib/win32/netsocket/client.cpp -o bin/obj/win32/netsocket/client.o
	$(CXX) $(CFLAGS) -c -fpic src/lib/win32/netsocket/server.cpp -o bin/obj/win32/netsocket/server.o
	$(CXX) $(CFLAGS) -c -fpic src/lib/math/pi/pi.cpp -o bin/obj/math/pi.o
	$(CXX) $(CFLAGS) -shared -o bin/saplib$(LIBEXT) bin/obj/crypto/sha1.o bin/obj/crypto/sha2.o bin/obj/crypto/sha3.o bin/obj/crypto/md5.o bin/obj/crypto/aes.o bin/obj/win32/netsocket/client.o bin/obj/win32/netsocket/server.o bin/obj/math/pi.o

build_script:
	$(CXX) $(CFLAGS) $(CXX11) -c src/core/main.cpp -o bin/obj/main.o
	$(CXX) $(CFLAGS) -o bin/$(EXECFILE) bin/obj/main.o bin/saplib$(LIBEXT)

cleanobj:
	$(RM) bin/obj

clean:
	$(RM) bin
