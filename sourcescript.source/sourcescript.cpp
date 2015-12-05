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

//Include libraries
#include "lib/libs.hpp"
#include "lib/pilib.hpp"
#include "lib/stdutils.hpp"
#include "lib/stdfile.hpp"
#include "lib/stdprint.hpp"
#include "lib/printdef.hpp"

#include "lib/gui.hpp"

#include "apps/tperiodic.hpp"
#include "apps/ptable_elements.hpp"
#include "apps/ptable_graphics.hpp"
#include "apps/mcalc.hpp"

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
        else if (string(argv[1]) == "--speedtest")
        {
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
            if(string(argv[2]) == "-ww")
            {
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
            logo();

        }
        else if (string(argv[1]) == "--os")
        {
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
        else if (string(argv[1]) == "--readfile")
        {
            if(strcmp(argv[3], "-ww")==0)
            {

            }
            else logo();
            printf("==============================\n\n");

            file.readfile(argv[2]);
        }
        else if (string(argv[1]) == "--delfile")
        {
            logo();
            printf("==============================\n\n");

            file.delfile(argv[2]);
        }
        else if (string(argv[1]) == "--copyfile")
        {
            logo();
            printf("==============================\n\n");
            file.copyfile(argv[2], argv[3]);
        }
        else if (string(argv[1]) == "--sourcecode")
        {
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
            file.readfile("temp.text");
            printf("\n[-] Done.\n\n");
            file.delfile("temp.text");
            exit(0);
        }
        else if (string(argv[1]) == "--whosts")
        {
            logo(); //print logo
            printf("[+] Changing windows hosts file...\n");
            printf("[-] IP: %s\n", argv[2]);
            printf("[-] HOST: %s\n", argv[3]);
            printf("\n==============================\n\n");
            file.whostfile(argv[2],argv[3]);
            exit(0);
        }
        else if (string(argv[1]) == "--sckt")
        {
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
            printing.slprint(argv[2]);
        }
        else if (string(argv[1]) == "--hourconvert")
        {
            utils.hourconvert(string(argv[2]));
        }
        else if (string(argv[1]) == "--md5")
        {
            cout << md5(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--base64e")
        {
            cout << base64.encode(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--base64d")
        {
            cout << base64.decode(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--sha256")
        {
            cout << sha256(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--sha224")
        {
            cout << sha224(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--sha384")
        {
            cout << sha384(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--sha512")
        {
            cout << sha512(argv[2]) << endl;
        }
        else if (string(argv[1]) == "--choise")
        {
        }
        else if (string(argv[1]) == "--gui")
        {
            ssgui.main();
        }
        else if (string(argv[1]) == "--getpath")
        {
            cout << utils.win_correntdirectory() << endl;
        }
        else if (string(argv[1])== "--winlib")
        {
            logo(); //Print logo
            if(string(argv[2])=="--help")
            {
                helpwinlib();
            }
            else if (string(argv[2])=="systemprop")
            {
                cout << "[+] Loading..." << endl;
                system("sysdm.cpl");
                cout << "[+] Done." << endl;
            }
        }
        else if (string(argv[1])== "--app")
        {
            logo();
            if(string(argv[2])=="periodic-table")
            {
                if(string(argv[3])=="--show-n")
                {
                    pgraphics.normal_pt();
                }
                else if(string(argv[3])=="--show-e")
                {
                    pgraphics.extended_pt();
                }
                else if(string(argv[3])=="--show-all")
                {
                    pgraphics.normal_pt();
                    cout << endl;
                    pgraphics.extended_pt();
                }
                else if(string(argv[3])=="--help")
                {
                    ptable.help();
                }
                else if(string(argv[3])=="--list")
                {
                    pelements.list_pt();
                }
                else if(string(argv[3])=="-s")
                {
                    ptable.variables(argv[4]);
                }
            }
            else if(string(argv[2])=="mcalc")
            {
				mcalc();
            }
            else if(string(argv[2])=="--help")
            {
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

//Function to print help menu
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
    cout << "  --md5 (phrase)                   ENCRYPT/HASH AN PHRASE IN MD5\n";//MD5
    cout << "  --base64e (phrase)               ENCRYPT AN PHRASE IN BASE64\n";//base64
    cout << "  --base64d (byte)                 DECRYPT A BASE64 BYTE\n";//base64
    cout << "  --sha224 (phrase)                ENCRYPT/HASH AN PHRASE IN SHA224\n";//sha
    cout << "  --sha256 (phrase)                ENCRYPT/HASH AN PHRASE IN SHA256\n";//sha
    cout << "  --sha384 (phrase)                ENCRYPT/HASH AN PHRASE IN SHA384\n";//sha
    cout << "  --sha512 (phrase)                ENCRYPT/HASH AN PHRASE IN SHA512\n";//sha
}
void helpwinlib(void)
{
    cout << "Usage: sourcescript --winlib (--argv) [argv] ...\n\n";
    cout << "  systemprop                       SHOW SYSTEM PROPS WINDOW\n"; // Calculate a pi : pilib.h
}
