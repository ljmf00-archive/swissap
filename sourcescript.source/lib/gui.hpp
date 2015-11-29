#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

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

using namespace std;

//Include libraries

#include "libs.hpp"
#include "pilib.hpp"
#include "stdutils.hpp"
#include "stdfile.hpp"
#include "stdprint.hpp"
#include "printdef.hpp"

#include "../apps/tperiodic.hpp"
#include "../apps/ptable_elements.hpp"
#include "../apps/ptable_graphics.hpp"

#include "../crypto/hex.h"
#include "../crypto/md5.h"
#include "../crypto/sha1.h"
#include "../crypto/sha2.h"
#include "../crypto/base64.h"

//Objects
utils utilsgui; //utils by utils
printing printinggui; //printing by printing
picalc picalcgui; //picalc by picalc
file filegui; //file by file
wincolor wincolorgui; //wincolor by wincolor
ptable ptablegui; //ptable by ptable
base64 base64gui; //base64 by base64
pelements pelementsgui; //pelements by pelements
pgraphics pgraphicsgui; //pgraphics by pgraphics


class ssgui
{
public:
    void main()
    {
        while(1)
        {
            logo();
            cout << "   1. CALCULATE PI" << endl;
            cout << "   2. DOWNLOAD FILE (PYTHON REQUIRE)" << endl;
            cout << "   3. SPEEDTEST TEST (PYTHON REQUIRE)" << endl;
            cout << "   4. CLEAR UNIX SCREEN (ONLY UNIX SUPPORT)" << endl;
            cout << "   5. SHOW SOURCESCRIPT LOGO" << endl;
            cout << "   0. EXIT" << endl;
            cout << endl <<" CHOISE:";
            int choise;
            cin >> choise;
            switch(choise)
            {
            case 1 :
            {
                cout << "NUM?: ";
                int num;
                cin >> num;
                printf("[+] Calculating pi number with %d cases\n",num);
                printf("==============================\n\n");
                picalcgui.pi(num);
                printf("\n[-] Done.\n");
                pause();
                break;
            }
            case 2 :
            {
                string choise1;
                string choise2;
                cout << "URL?:";
                cin >> choise1;
                cout << "OUTPUT?:";
                cin >> choise2;
                logo(); //Print logo
                cout << "[+] Downloading file from, \n";
                cout << "[-]URL: " << choise1 << endl;
                cout << "[-]OUTPUT: " << choise2 << endl;
                printf("==============================\n\n");
                #if !(_WIN32) //If dont support Windows :: Do Def. Inst.
                char cmd[] = "python wget.py --output "; //Add "python" word
                #else //If support, then...
                char cmd[] = "wget.py --output ";
                #endif //end if !(_WIN32)
                strcat(cmd, choise2.c_str());
                strcat(cmd, " ");
                strcat(cmd, choise1.c_str());
                cout << cmd << endl;
                system(cmd);
                printf("\n[-] Done.\n");
                exit(0);
            }
            case 0 :
            {
                exit(0);
                break;
            }
            default  :
                main();
                break;
            }
        }
    }
    void pause()
    {
        int choise;
        cout << "EXIT?(0/1): ";
        cin >> choise;
        if (choise==0)
        {
            main();
        }
        if (choise==1)
        {
            exit(0);
        }

    }
    void logo(void)
    {
        cout << "                                              _       _   \n"
             << "                                             (_)     | |  \n"
             << "  ___  ___  _   _ _ __ ___ ___  ___  ___ _ __ _ _ __ | |_ \n"
             << " / __|/ _ \\| | | | '__/ __/ _ \\/ __|/ __| '__| | '_ \\| __|\n"
             << " \\__ \\ (_) | |_| | | | (_|  __/\\__ \\ (__| |  | | |_) | |_ \n"
             << " |___/\\___/ \\__,_|_|  \\___\\___||___/\\___|_|  |_| .__/ \\__| GUI\n"
             << "                                               | |        \n"
             << "                                               |_|        \n\n";
    }
};

#endif // GUI_HPP_INCLUDED
