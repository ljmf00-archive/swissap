//Include libraries
#include "libs.h"
#include "pilib.h"
#include "stdutils.h"

// ...

//Function to print sourcescript logo
void logo(void) {
  printf("                                              _       _   \n"
  "                                             (_)     | |  \n"
  "  ___  ___  _   _ _ __ ___ ___  ___  ___ _ __ _ _ __ | |_ \n"
  " / __|/ _ \\| | | | '__/ __/ _ \\/ __|/ __| '__| | '_ \\| __|\n"
  " \\__ \\ (_) | |_| | | | (_|  __/\\__ \\ (__| |  | | |_) | |_ \n"
  " |___/\\___/ \\__,_|_|  \\___\\___||___/\\___|_|  |_| .__/ \\__|\n"
  "                                               | |        \n"
  "                                               |_|        \n\n");
}

//Function to print help menu
void help(void) {
  printf("Usage: sourcescript (--argv) [argv] ...\n\n");
  printf("  --pi <num_cases>             CALCULATE PI\n"); // pilib
  printf("  --download <url> <output>    DOWNLOAD A FILE (REQUIRE PYTHON)\n"); //Download python script
  printf("  --speedtest                  DO SPEEDTEST ON YOUR NETWORK (REQUIRE PYTHON)\n"); //Speedtest python script
  printf("  -c                        	 CLEAR UNIX SCREEN (ONLY UNIX SUPPORT)\n"); //System command for unix stdutils
  printf("  -l                       	 SHOW SOURCESCRIPT LOGO\n"); 					//Show logo
  printf("  --os                       	 SHOW OPERATION SYSTEM INFORMATIONS (REQUIRE PYTHON)\n"); //OS python script
}

//Main Function
void main(int argc, char *argv[]) {/*Variables*/ int choise;
  logo(); //Print logo
  if(argc > 1) { //If arguments is more than one
    if(strcmp(argv[1], "--pi")==0) {
      int i=atoi(argv[2]);
      printf("[+] Calculating pi number with %d cases\n",i);
      printf("==============================\n\n");
      i=i;
      pi(i);
      printf("\n[-] Done.\n");
    }
    else if (strcmp(argv[1], "--download")==0) {
      printf("[+] Downloading file from, \n");
      printf("[-]URL: %s\n",argv[2]);
      printf("[-]OUTPUT: %s\n",argv[3]);
      printf("==============================\n\n");
      #if !(_WIN32) //If dont support Windows :: Do Def. Inst.
      char cmd[] = "python wget.py --output "; //Add "python" word
      #else //If support, then...
      char cmd[] = "wget.py --output ";
      #endif //end if !(_WIN32)
      strcat(cmd, argv[3]);
      strcat(cmd, " ");
      strcat(cmd, argv[2]);
      system(cmd);
      printf("\n[-] Done.\n");
	  exit(0);
    }
    else if (strcmp(argv[1], "--speedtest")==0) {
      printf("[+] Doing a speedtest... \n");
      printf("==============================\n\n");
      #if !(_WIN32) //If dont support Windows :: Do Def. Inst.
      system("python speedtest.py"); // ...
      #else //If support, then...
      system("speedtest.py");
      #endif //end if !(_WIN32)
      printf("\n[-] Done.\n");
	  exit(0);
    }
    else if (strcmp(argv[1], "-c")==0) unix_sysclear();
    else if (strcmp(argv[1], "-l")==0) exit(0);
    else if (strcmp(argv[1], "--gisocket")==0) {

    }
    else if (strcmp(argv[1], "--os")==0) {
      printf("[+] Operation System Information... \n");
      printf("==============================\n\n");
      #if !(_WIN32) //If dont support Windows :: Do Def. Inst.
      system("python os.py"); // ...
      #else //If support, then...
      system("os.py");
      #endif //end if !(_WIN32)
      printf("\n[-] Done.\n");
    }
  }
  else { //If arguments is one, show help menu
    help();
  }
  exit(0);
}
