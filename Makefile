# -*- Makefile -*- 
# __________  _________ _________
# \______   \/   _____//   _____/  | BigSource Script
#  |    |  _/\_____  \ \_____  \   | Project in C/C++ Language
#  |    |   \/        \/        \  |
#  |______  /_______  /_______  /  | @author Luís Ferreira
#         \/        \/        \/   | @license GNU Public License v3
# Copyright (C) 2016 - Luís Ferreira. All right reserved
#   
# More information in: https://github.com/ljmf00/ (Github Page)

NAME = bss
CC = gcc
CXX = g++
CXX11 = -std=gnu++11
CFLAGS = -Wall -Wextra
RM = rm -rf
MKDIR = mkdir -p
GDB = gdb

all: mkdirstep build cleanobj

debug: mkdirstep build debugstep

debugstep:
	$(GDB) bin/bss

debug_windows: win32_build win64_build

windows: win32_build win64_build cleanobj

win32_build: CC = gcc-mingw-w64-i686
win32_build: CXX = g++-mingw-w64-i686
win32_build: mkdirstep build

win64_build: CC = gcc-mingw-w64-x86-64
win64_build: CXX = g++-mingw-w64-x86-64

mkdirstep:
	$(MKDIR) bin
	$(MKDIR) bin/obj
	$(MKDIR) bin/obj/crypto
	$(MKDIR) bin/obj/convert
	$(MKDIR) bin/obj/win32
	$(MKDIR) bin/obj/win32/netsocket

build:
	$(CXX) $(CFLAGS) $(CXX11) -c src/core/main.cpp -o bin/obj/main.o
	$(CXX) $(CFLAGS) -c -fpic src/lib/crypto/sha1/sha1.cpp -o bin/obj/crypto/sha1.o
	$(CXX) $(CFLAGS) -c -fpic src/lib/crypto/sha2/sha2.cpp -o bin/obj/crypto/sha2.o
	$(CXX) $(CFLAGS) -c -fpic src/lib/crypto/sha3/sha3.cpp -o bin/obj/crypto/sha3.o
	$(CXX) $(CFLAGS) -c -fpic src/lib/crypto/md5/md5.cpp -o bin/obj/crypto/md5.o
	$(CXX) $(CFLAGS) $(CXX11) -c -fpic src/lib/crypto/aes/aes.cpp -o bin/obj/crypto/aes.o
	$(CXX) $(CFLAGS) -c -fpic src/lib/win32/netsocket/client.cpp -o bin/obj/win32/netsocket/client.o
	$(CXX) $(CFLAGS) -c -fpic src/lib/win32/netsocket/server.cpp -o bin/obj/win32/netsocket/server.o
	$(CXX) $(CFLAGS) -shared -o bin/bslib.so bin/obj/crypto/sha1.o bin/obj/crypto/sha2.o bin/obj/crypto/sha3.o bin/obj/crypto/md5.o bin/obj/crypto/aes.o bin/obj/win32/netsocket/client.o bin/obj/win32/netsocket/server.o
	$(CXX) $(CFLAGS) -o bin/bss bin/obj/main.o bin/bslib.so

cleanobj:
	$(RM) bin/obj

clean:
	$(RM) bin
