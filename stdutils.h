/*lsferreira programming */
#ifndef LSCLIBSTDUTILS_H_INCLUDED
#define LSCLIBSTDUTILS_H_INCLUDED

#if !(WIN32) //If dont support Windows :: Do Def. Inst.

#endif
#if !(WIN64) //! win64

#endif

#include "libs.h"

// ...

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
  system(cmd); }



#endif // LSCLIBSTDUTILS_H_INCLUDED
