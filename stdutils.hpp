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
*/

#ifndef LSCLIBSTDUTILS_H_INCLUDED
#define LSCLIBSTDUTILS_H_INCLUDED

#if !(WIN32) //If dont support Windows :: Do Def. Inst.

#endif
#if !(WIN64) //! win64

#endif

#include "libs.hpp"

using namespace std;
// ...

class utils {
public: 
	void win_sysmode(char x[], char y[]){
  		char charxy[] = "mode ";
  		strcat(charxy, x);
  		strcat(charxy, ",");
  		strcat(charxy, y);
  		system(charxy);
	}

	void win_syscolor(char x[]){
  		char charx[] = "color ";
  		strcat(charx, x);
  		system(charx);
	}

	void win_sysclear(void){ system("cls"); }
	void unix_sysclear(void){ system("tput reset"); system("clear");}
	void unix_wget(char url[]) {char cmd[]="";
  		strcpy(cmd, "wget "); strcat(cmd, url);
  		system(cmd); 
	}

	string getOsName()
	{
    	#ifdef _WIN32
    	return "Windows 32-bit";
    	#elif _WIN64
    	return "Windows 64-bit";
    	#elif __unix || __unix__
    	return "Unix";
    	#elif __APPLE__ || __MACH__
    	return "Mac OSX";
    	#elif __linux__
    	return "Linux";
    	#elif __FreeBSD__
    	return "FreeBSD";
    	#else
    	return "Other";
    	#endif
	}
};


#endif // LSCLIBSTDUTILS_H_INCLUDED
