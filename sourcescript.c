/*lsferreira programming*/

//Include libraries
#include "libs.h"
#include "pilib.h"
#include "stdutils.h"
#include "stdfile.h"


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
  printf("  --pi <num_cases>                 CALCULATE PI\n"); // Calculate a pi : pilib.h
  printf("  --download <url> <output>        DOWNLOAD A FILE (REQUIRE PYTHON)\n"); //Download python script : wget.py
  printf("  --speedtest                      DO SPEEDTEST ON YOUR NETWORK (REQUIRE PYTHON)\n"); //Speedtest python script : speedtest.py
  printf("  -c -w                       	 CLEAR UNIX SCREEN (ONLY UNIX SUPPORT)\n"); //System command for unix : stdutils.h
  printf("  -l                       	     SHOW SOURCESCRIPT LOGO\n"); 					//Show logo
  printf("  --os                       	     SHOW OPERATION SYSTEM INFORMATIONS (REQUIRE PYTHON)\n"); //OS python script : os.py
  printf("  --readfile <patch> -w            READ AN FILE\n"); //Read a file : stdfile.h
  printf("  --delfile <patch>                DELETE AN FILE\n"); //Delete a file : stdfile.h
  printf("  --copyfile <patch> <destination> COPY AN FILE TO ANY DESTINATION\n"); //Copy a file : stdfile.h
  printf("  --sourcecode <url>               VIEW THE SOURCECODE OF ANY URL (REQUIRE PYTHON)\n"); //View sourcecode of any url
}

//Main Function
void main(int argc, char *argv[]) {/*Variables*/ int choise;
  if(argc > 1) { //If arguments is more than one
    if(strcmp(argv[1], "--pi")==0) {
      logo();
      int i=atoi(argv[2]);
      printf("[+] Calculating pi number with %d cases\n",i);
      printf("==============================\n\n");
      i=i;
      pi(i);
      printf("\n[-] Done.\n");
    }
    else if (strcmp(argv[1], "--download")==0) {
      logo(); //Print logo
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
      logo(); //Print logo
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
    else if (strcmp(argv[1], "-c")==0) {
      if(strcmp(argv[2], "-ww")==0) {
	  }
	  else logo(); //Print logo
	  
	  unix_sysclear();
	}
    else if (strcmp(argv[1], "-l")==0) {
      logo(); //Print logo
	  exit(0);
	}
    else if (strcmp(argv[1], "--gisocket")==0) {
      logo();
	  
	  
    }
    else if (strcmp(argv[1], "--os")==0) {
      logo(); //Print logo
      printf("[+] Operation System Information... \n");
      printf("==============================\n\n");
      #if !(_WIN32) //If dont support Windows :: Do Def. Inst.
      system("python os.py"); // ...
      #else //If support, then...
      system("os.py");
      #endif //end if !(_WIN32)
      printf("\n[-] Done.\n");
    }
    else if (strcmp(argv[1], "--readfile")==0) {
      if(strcmp(argv[3], "-ww")==0) {
      	
	  }
	  else logo(); printf("==============================\n\n");
	  
      readfile(argv[2]);
	}
	else if (strcmp(argv[1], "--delfile")==0) {
      logo(); printf("==============================\n\n");
	  
      delfile(argv[2]);
	}
	else if (strcmp(argv[1], "--copyfile")==0) {
      logo(); printf("==============================\n\n");
      copyfile(argv[2], argv[3]);
	}
	else if (strcmp(argv[1], "--sourcecode")==0) {
      logo(); //Print logo
      printf("[+] Downloading file from, \n");
      printf("[-]URL: %s\n",argv[2]);
      printf("[-]OUTPUT: temp.text\n");
      printf("==============================\n\n");
      #if !(_WIN32) //If dont support Windows :: Do Def. Inst.
      char cmd[] = "python wget.py --output "; //Add "python" word
      #else //If support, then...
      char cmd[] = "wget.py --output ";
      #endif //end if !(_WIN32)
      strcat(cmd, "temp.text");
      strcat(cmd, " ");
      strcat(cmd, argv[2]);
      system(cmd);
      printf("\n==============================\n\n");
      readfile("temp.text");
      printf("\n[-] Done.\n");
	  exit(0);
    }
  }
  else { //If arguments is one, show help menu
    logo();
    help();
  }
  exit(0);
}
