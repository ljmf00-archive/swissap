/*lsferreira programming */

/*
                                              _       _
                                             (_)     | |
  ___  ___  _   _ _ __ ___ ___  ___  ___ _ __ _ _ __ | |_
 / __|/ _ \| | | | '__/ __/ _ \/ __|/ __| '__| | '_ \| __|
 \__ \ (_) | |_| | | | (_|  __/\__ \ (__| |  | | |_) | |_
 |___/\___/ \__,_|_|  \___\___||___/\___|_|  |_| .__/ \\__|
                                               | |
                                               |_|
			Copyright  (c) lsferreira programming - 2015
*/



#ifndef LSCLIBLIBS_H_INCLUDED
#define LSCLIBLIBS_H_INCLUDED
// Multiplataform optimization
//OPERATION SYSTEM DETECTION

//Win32
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#include <tchar.h>
//Apple / OSX
#elif __APPLE__
#include "TargetConditionals.h"
// Iphone Simulator
#if TARGET_IPHONE_SIMULATOR
//IOS
#elif TARGET_OS_IPHONE
// OSMACX
#elif TARGET_OS_MAC
#else
#endif
//LINUX and UNIX
#elif __linux
#elif __unix__
#elif __posix
#endif


//GENERAL LIBRARY

//Stream Libraries
#include <iostream>
#include <fstream>
#include <sstream>

//General Libraries
#include <string>
#include <iomanip>
#include <vector>

//C++ Import C Libraries
#include <cstdlib>
#include <ciso646>
#include <cassert>
#include <cmath>
#include <clocale>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>

//System Libraries
#include <sys/types.h>
#include <sys/stat.h>

//C Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Other Libraries
#include <fcntl.h>

//Visual Studio don't support this library
//#include <unistd.h>

#endif // LSCLIBLIBS_H_INCLUDED
