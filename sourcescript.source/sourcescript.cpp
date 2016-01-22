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


//Include libraries

//General libraries
#include "lib/libs.hpp"
#include "lib/pilib.hpp"
#include "lib/stdutils.hpp"
#include "lib/stdfile.hpp"
#include "lib/stdprint.hpp"
#include "lib/printdef.hpp"

//Gui libraries
#include "lib/gui.hpp"

//Apps libraries
#include "apps/tperiodic.hpp"
#include "apps/ptable_elements.hpp"
#include "apps/ptable_graphics.hpp"
#include "apps/mcalc.hpp"

//Cryptography libraries
#include "crypto/hex.h"
#include "crypto/md5.h"
#include "crypto/sha1.h"
#include "crypto/sha2.h"
#include "crypto/base64.h"

//Used namespaces
using namespace std;

//Predeclaration functions
void logo(void);
void help(void);
void helpwinlib(void);

//Objects
utils utils; //utils by utils
printing printing; //printing by printing
picalc picalc; //picalc by picalc
file file; //file by file
wincolor wincolor; //wincolor by wincolor
ptable ptable; //ptable by ptable
base64 base64; //base64 by base64
pelements pelements; //pelements by pelements
pgraphics pgraphics; //pgraphics by pgraphics
ssgui ssgui; //gui by gui

// ...

//Main Function
int main(int argc, char *argv[])
{
    /*Variables*/ int choise;

    if(argc > 1)   //If arguments is more than one
    {
        if(string(argv[1]) == "--pi")
        {
            /* Summary: This argument run a pi() function and it will calculate
             * a specific number of pi cases.
             * Used for: PI CALCULATION;
             *           */

            logo();
            int i=atoi(argv[2]);
            printf("[+] Calculating pi number with %d cases\n",i);
            printf("==============================\n\n");
            i=i;
            picalc.pi(i);
            printf("\n[-] Done.\n");
        }
        else if (string(argv[1]) == "--download")
        {
            /* Summary: This argument execute a python script and it
             * will download a specific file from an weblink (URL)
             * Used for: DOWNLOAD A CONTENT FORM URL;
                         USE WGET FUNCTION IN PYTHON FOR OTHER PROPOSE;
						 DISPLAY SOURCECODE FROM AN URL;
             *           */

            logo(); //Print logo
            printf("[+] Downloading file from, \n");
            printf("[-]URL: %s\n",argv[2]);
            printf("[-]OUTPUT: %s\n",argv[3]);
            printf("==============================\n\n");

            /* Multiplataform python executation */

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
        else if (string(argv[1]) == "--speedtest")
        {
            /* Summary:  This argument is used to do a
             * speedtest test from speedtest.net website
             * using python script.
             * Used for: SPEEDTEST TEST WITH PYTHON SCRIPT;
             *           */

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
        else if (string(argv[1]) == "-c")
        {
            /* This short argument is used for clear
             * unix terminal with easy command script */
            if(string(argv[2]) == "-ww")
            {
                // Without print logo() function;

                // ...

            }
            else logo(); //Print logo

            utils.unix_sysclear();
        }
        else if (string(argv[1]) == "-l")
        {
            logo(); //Print logo
            exit(0);
        }
        else if (string(argv[1]) == "--gisocket")
        {
			// Unnamed arguments ??? 12-12-2015
			/* Summary: 
			 * Used for: 
						*/
            logo();

        }
        else if (string(argv[1]) == "--os")
        {

			/* Summary: This argument display Operation System Informations 
			 * from a python script
			 * Used for: DISPLAY OS INFO;
			 *			 */


            logo(); //Print logo
            printf("[+] Operation System Information... \n");
            printf("==============================\n\n");

			//Multiplataform python exec optimization
#if !(_WIN32) //If dont support Windows :: Do Def. Inst.
            system("python os.py"); // ...
#else //If support, then...
            system("os.py");
#endif //end if !(_WIN32)
            printf("\n[-] Done.\n");

        }
        else if (string(argv[1]) == "--readfile")
        {
			/* Summary: This argument run a readfile() function and display a
			 * content of an file
			 * Used for: READ AN FILE 
			 *			 */

            if(strcmp(argv[3], "-ww")==0)
            {

            }
            else logo();
            printf("==============================\n\n");

			//Run readfile() function on file object
            file.readfile(argv[2]);
        }
        else if (string(argv[1]) == "--delfile")
        {
			/* Summary: this argument run a delfile() function and delete a file
			* from system path 
			* Used for:  DELETE AN FILE;
			*			 */
            logo();
            printf("==============================\n\n");

            file.delfile(argv[2]);
        }
        else if (string(argv[1]) == "--copyfile")
        {
			/* Summary: This function run copyfile() function and copy a file by an
			* patch and write in specific system path 
			* Used for: COPY AN FILE; 
			*			*/
            logo();
            printf("==============================\n\n");
			// Run copyfile() function on file object, with 2 arguments
			/* argv2 = path1
			 * argv3 = path2 
			 *				 */

            file.copyfile(argv[2], argv[3]);
        }
        else if (string(argv[1]) == "--sourcecode")
        {
			/* This argument run wget python script to display
			 * a sourcecode from an URL */

            logo(); //Print logo
            printf("[+] Downloading file from, \n");
            printf("[-]URL: %s\n",argv[2]);
            printf("[-]OUTPUT: temp.text\n");
            printf("==============================\n\n");

			//Multiplataform python exec optimization
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
			//Function readfile() to read file in stream on file object
            file.readfile("temp.text");
            printf("\n[-] Done.\n\n");
            file.delfile("temp.text");
            exit(0);
        }
        else if (string(argv[1]) == "--whosts")
        {
			/* This function use hosts system file path to write/append
			 * an ip address and dns record for block/redirection proposes 
			 * REQUIREMENTS: Need Administrator Permissions */


            logo(); //print logo
            printf("[+] Changing windows hosts file...\n");
            printf("[-] IP: %s\n", argv[2]);
            printf("[-] HOST: %s\n", argv[3]);
            printf("\n==============================\n\n");
			//Read function whostfile() on file object
			/* argument 1: IP Address
			 * argument 2: Host/DNS name */
            file.whostfile(argv[2],argv[3]);
            exit(0);

        }
        else if (string(argv[1]) == "--sckt")
        {
			/* Summary: This argument run socket script in python and communicate with
			 * any server with sourcescript socket client script, running --mksckt 
			 * argument */

            logo(); //print logo
            printf("[+] Connect to a socket with...\n");
            if (strcmp(argv[2], "--this")==0) printf("[-] IP: socket localhost\n");
            else printf("[-] IP: %s\n", argv[2]);
            printf("[-] Port: %s\n", argv[3]);
            printf("[-] Length: %s\n", argv[4]);
            printf("\n==============================\n\n");
#if !(_WIN32) //If dont support Windows :: Do Def. Inst.
            char cmd[] = "python client.py "; //Add "python" word
#else //If support, then...
            char cmd[] = "client.py ";
#endif //end if !(_WIN32)
            strcat(cmd, argv[2]);
            strcat(cmd, " ");
            strcat(cmd, argv[3]);
            strcat(cmd, " ");
            strcat(cmd, argv[4]);
            system(cmd);
        }
        else if (string(argv[1]) == "--mksckt")
        {
			/* Summary: This argument run a server socket python script 
			 * Used for: Communicate with client --sckt sourcescript argument */

            logo(); //print logo
            cout << "[+] Creating a socket with...\n";
            cout << "[-] Port: " << argv[2] << endl;
            cout << "[-] Message: " << argv[3] << endl;
            cout << "\n==============================\n\n";
#if !(_WIN32) //If dont support Windows :: Do Def. Inst.
            char cmd[] = "python server.py "; //Add "python" word
#else //If support, then...
            char cmd[] = "server.py ";
#endif //end if !(_WIN32)
            strcat(cmd, argv[2]);
            strcat(cmd, " ");
            strcat(cmd, argv[3]);
            system(cmd);
        }
        else if (string(argv[1]) == "--slprint")
        {
			/* Summary: This short argument run a slprint() function and
			 * display/print in console the text in slow motion animation 
			 * This function used only for fun :D */

            printing.slprint(argv[2]);
        }
        else if (string(argv[1]) == "--hourconvert")
        {
			/* Summary: This argument run hourconvert() function and 
			* display/print in console the convertion of hour number */

            utils.hourconvert(string(argv[2]));
        }
        else if (string(argv[1]) == "--md5")
        {
			/* Summary: this argument ecrypt any string in md5 hash
			 * generator */

            cout << md5(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--base64e")
        {
			/* Summary: this argument encrypt any string in base64 phrase */
            cout << base64.encode(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--base64d")
        {
			/* Summary: this argument decrypt any phrase in base64 string*/
            cout << base64.decode(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--sha256")
        {
			/* Summary: this argument ecrypt any string in sha hash
			* generator */
            cout << sha256(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--sha224")
        {
			/* Summary: this argument ecrypt any string in sha hash
			* generator */
            cout << sha224(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--sha384")
        {
			/* Summary: this argument ecrypt any string in sha hash
			* generator */
            cout << sha384(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--sha512")
        {
			/* Summary: this argument ecrypt any string in sha hash
			* generator */
            cout << sha512(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--choise")
        {
			//Unnamed argument ??? 12-12-2015
			/* Summary: 
			 *		    */

        }
        else if (string(argv[1]) == "--gui")
        {
			/* Summary: This argument run a gui mode for 
			 * sourcescript script */

			//Using ssgui object !

            ssgui.main();
        }
        else if (string(argv[1]) == "--getpath")
        {
			/* This short argument print in console the
			* sourcescript executation path */

            cout << utils.win_correntdirectory() << endl;
        }
        else if (string(argv[1])== "--winlib")
        {
			/* Summary:  This argument use windows.h library 
			 * Used for: WINDOWS.H INCLUDE LIB FUNCTIONS PROPOSE; 
			 *			 */

            logo(); //Print logo

			//--help argument 
            if(string(argv[2])=="--help")
            {
                helpwinlib();
            }

			// systemprop argument
            else if (string(argv[2])=="systemprop")
            {
				/* This use bath command and open various system shell's*/

                cout << "[+] Loading..." << endl;
                system("sysdm.cpl");
                cout << "[+] Done." << endl;
            }
        }
		/* Summary: This function run the apps of sourcescript script, this
		 * include: periodictable
		 *			mcalc */


        else if (string(argv[1])== "--app")
        {
			/* Summary: This argument run periodic-table app with others 
			 * sub-arguments 
			 * NOTE: Don't do this argument without another argument/sub-argument 
			 *		*/

            logo();
            if(string(argv[2])=="periodic-table")
            {
				/* Summary: This sub-argument show the normal periodic table
				 * in graphical mode */
                if(string(argv[3])=="--show-n")
                {
                    pgraphics.normal_pt();
                }

				/* Summary: This sub-argument show the extended periodic table
				 * in graphical mode */

                else if(string(argv[3])=="--show-e")
                {
                    pgraphics.extended_pt();
                }

				/* Summary: This sub-argument show the normal and extended periodic
				 * table in graphical mode */

                else if(string(argv[3])=="--show-all")
                {
                    pgraphics.normal_pt();
                    cout << endl;
                    pgraphics.extended_pt();
                }

				/* Summary:  This sub-argument show the help menu for periodic-table 
				 * app */

                else if(string(argv[3])=="--help")
                {
                    ptable.help();
                }

				// This sub-argument show a list menu for periodic-table app
                else if(string(argv[3])=="--list")
                {
                    pelements.list_pt();
                }

				//This sub-argument show a determinate element of periodic table
                else if(string(argv[3])=="-s")
                {
                    ptable.variables(argv[4]);
                }
            }
			
			/* Summary: This argument run mcalc app and is used with another sub-argument
			 * NOTE: Don't do this argument without another argument/sub-argument
			 *		*/
            else if(string(argv[2])=="mcalc")
            {
				mcalc();
            }
            else if(string(argv[2])=="--help")
            {
				/* Summary: This argument show list of apps */

                cout << "List of Applications: \n" << endl;
                cout << "periodic-table" << endl;
				cout << "mcalc" << endl;
            }
        }
    }
    else   //If arguments is one, show help menu
    {
        logo();
        help();
    }
    exit(0);
}

//Function to print sourcescript logo
void logo(void)
{
    cout << "                                              _       _   \n"
         << "                                             (_)     | |  \n"
         << "  ___  ___  _   _ _ __ ___ ___  ___  ___ _ __ _ _ __ | |_ \n"
         << " / __|/ _ \\| | | | '__/ __/ _ \\/ __|/ __| '__| | '_ \\| __|\n"
         << " \\__ \\ (_) | |_| | | | (_|  __/\\__ \\ (__| |  | | |_) | |_ \n"
         << " |___/\\___/ \\__,_|_|  \\___\\___||___/\\___|_|  |_| .__/ \\__|\n"
         << "                                               | |        \n"
         << "                                               |_|        \n\n";
}

/* Summary:  This function is used to print help menu for
 * main app, sourcescript*/

void help(void)
{
    cout << "Usage: sourcescript (--argv) [argv] ...\n\n";
    cout << "  --pi <num_cases>                 CALCULATE PI\n"; // Calculate a pi : pilib.h
    cout << "  --download <url> <output>        DOWNLOAD A FILE (REQUIRE PYTHON)\n"; //Download python script : wget.py
    cout << "  --speedtest                      DO SPEEDTEST ON YOUR NETWORK (REQUIRE PYTHON)\n"; //Speedtest python script : speedtest.py
    cout << "  -c -w                       	    CLEAR UNIX SCREEN (ONLY UNIX SUPPORT)\n"; //System command for unix : stdutils.h
    cout << "  -l                       	    SHOW SOURCESCRIPT LOGO\n"; 					//Show logo
    cout << "  --os                       	    SHOW OPERATION SYSTEM INFORMATIONS (REQUIRE PYTHON)\n"; //OS python script : os.py
    cout << "  --readfile <patch> -w            READ AN FILE\n"; //Read a file : stdfile.h
    cout << "  --delfile <patch>                DELETE AN FILE\n"; //Delete a file : stdfile.h
    cout << "  --copyfile <patch> <destination> COPY AN FILE TO ANY DESTINATION\n"; //Copy a file : stdfile.h
    cout << "  --sourcecode <url>               VIEW THE SOURCECODE OF ANY URL (REQUIRE PYTHON)\n"; //View sourcecode of any url
    cout << "  --whosts <ip> <host>             CHANGE WINDOWS HOSTS FILE (REQUIRE ADMIN)\n"; //Change windows hosts
    cout << "  --sckt <ip; --this> <port> <len> CONNECT TO A SIMPLE SOCKET (REQUIRE PYTHON)\n"; //Connect to a socket
    cout << "  --mksckt <port> <msg>            CREATE A SIMPLE SOCKET (REQUIRE PYTHON)\n"; //create/make a socket
    cout << "  --slprint <msg>                  PRINT AN TEXT WITH SLOW EFFECT (ONLY WINDOWS)\n"; //Slow print function
    cout << "  --hourconvert <hour>             CONVERT HOUR TO MINUTE, DAY, SECOND...\n";//Hour convert function
    cout << "  --winlib (--help) [argv]...      ACCESS TO WINDOWS LIBRARY SUBARGUMENT (WINDOWS ONLY)\n";//windows lib subargument
    cout << "  --app (name-of-app)              RUN AN INTEGRATE SOURCE SCRIPT APPLICATION\n";// run an sourcescript app || created
    cout << "        periodic-table --help      \n";
    cout << "        mcalc --help               \n";
    cout << endl;
    cout << "  --md5 (phrase)                   ENCRYPT/HASH AN PHRASE IN MD5\n";//MD5
    cout << "  --base64e (phrase)               ENCRYPT AN PHRASE IN BASE64\n";//base64
    cout << "  --base64d (byte)                 DECRYPT A BASE64 BYTE\n";//base64
    cout << "  --sha224 (phrase)                ENCRYPT/HASH AN PHRASE IN SHA224\n";//sha
    cout << "  --sha256 (phrase)                ENCRYPT/HASH AN PHRASE IN SHA256\n";//sha
    cout << "  --sha384 (phrase)                ENCRYPT/HASH AN PHRASE IN SHA384\n";//sha
    cout << "  --sha512 (phrase)                ENCRYPT/HASH AN PHRASE IN SHA512\n";//sha
}

/* Summary:  This function is used for show/display in console the 
 * help menu for windows.h header library */

void helpwinlib(void)
{
    cout << "Usage: sourcescript --winlib (--argv) [argv] ...\n\n";
    cout << "  systemprop                       SHOW SYSTEM PROPS WINDOW\n"; // Calculate a pi : pilib.h
}
