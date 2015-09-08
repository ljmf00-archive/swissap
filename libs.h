/*lsferreira programming */
#ifndef LSCLIBLIBS_H_INCLUDED
#define LSCLIBLIBS_H_INCLUDED
//OPERATION SYSTEM DETECTION
#ifdef _WIN32
  #include <windows.h>
  #include <conio.h>
  #include <tchar.h>
   #ifdef _WIN64
      #include <windows.h>
      #include <conio.h>
      #include <tchar.h>
   #endif
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_IPHONE_SIMULATOR
    #elif TARGET_OS_IPHONE
    #elif TARGET_OS_MAC
    #else
    #endif
#elif __linux
#elif __unix
#elif __posix
#endif
//GENERAL LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>
#include <assert.h>
#include <math.h>
#include <locale.h>
#include <unistd.h>


#endif // LSCLIBLIBS_H_INCLUDED
