/*
 *  ___  _  ___  _____ _______  _____ ___.__.______   | Swiss Army Project
 * / _/_| |_\_ \ \__  \\_  __ \/     <   |  |\____ \  | Project in C/C++ Language
 * || |_   _| ||  / __ \|  | \/  Y Y  \___  ||  |_> > |
 * ||_  |_|  _|| (____  /__|  |__|_|  / ____||   __/  | @author Luís Ferreira
 * \__\     /__/      \/            \/\/     |__|     | @license GNU Public License v3
 *
 * Copyright (c) 2016 - Luís Ferreira. All right reserved
 * More information in: https://github.com/ljmf00/ (Github Page)
 */

/* NOTE: This file is only dedicated for
 * main function and their content.
 */

///Processor Directives
#define SWISSAPVERSION "V0.1BUILDundefinned"

///Libraries
#include <iostream>

//Core Library
#include "help.h"
#include "errors.h"
#include "asciiart.h"
#include "debug.h"

//Cryptography Library
#include "../lib/crypto/sha1/sha1.h"
#include "../lib/crypto/sha2/sha2.h"
#include "../lib/crypto/sha3/sha3.h"
#include "../lib/crypto/md5/md5.h"
#include "../lib/crypto/aes/aes.h"

//Convert Library
#include "../lib/convert/string/string.h"

//Math Library
#include "../lib/math/pi/pi.h"

//Misc Library
#include "../lib/misc/file/file.h"

//Convert Libraries

///Used namespaces
using namespace std;

///Objects
SHA1 sha1;
SHA3 sha3;
MD5 md5;
AES aes;
swissapLib::pi pi;
swissapLib::File file;

/// Main Function
int main(int argc, char* argv[])
{
    if(argc >=2)
    {
        if(string(argv[1])=="--debug" || string(argv[1])=="-d")
        {
            if(argc==2)
            {
                swissapCore::debug();
            }
            else if(string(argv[2])=="-e" || string(argv[2])=="--error")
            {
                if(argv[3]) swissapCore::exitCode(atoi(argv[3]));
                if(argc>4) swissapCore::exitCode(0x12E);
            }
            else
            {
                swissapCore::exitCode(0x12F);
            }
        }
        else if(string(argv[1])=="--version" || string(argv[1])=="-v")
        {
            if(argc==2)
            {
                cout << SWISSAPVERSION << endl;
            }
            else
            {
                swissapCore::exitCode(0x12E);
            }
        }
        else if(string(argv[1])=="--help" || string(argv[1])=="-h")
        {
            if(argc==2)
            {
                swissapCore::logo();
                swissapCore::help();
            }
            if(argc==3)
            {
                swissapCore::logo();
                swissapCore::helpSpecific((string)argv[2]);
            }
        }
        else if(string(argv[1])=="--convert" || string(argv[1])=="-C")
        {
            if(argc==2)
            {
                swissapCore::exitCode(0x12D);
            }
            else if(string(argv[2])=="string2hex")
            {
                if(argc==4)
                {
                    cout << swissapLib::string2hex((string)argv[3]) << endl;
                }
                else if(argc>4)
                {
                    swissapCore::exitCode(0x12E);
                }
                else
                {
                    swissapCore::exitCode(0x12D);
                }
            }
            else
            {
                swissapCore::exitCode(0x12F);
            }
        }
        else if(string(argv[1])=="--math" || string(argv[1])=="-m")
        {
            if(argc==2)
            {
                swissapCore::exitCode(0x12D);
            }
            else if(string(argv[2])=="pi")
            {
                if(argc==4)
                {
                    pi.calculate(atoi(argv[3]));
                }
                else if(argc>4)
                {
                    swissapCore::exitCode(0x12E);
                }
                else
                {
                    swissapCore::exitCode(0x12D);
                }
            }
            else
            {
                swissapCore::exitCode(0x12F);
            }
        }
        else if(string(argv[1])=="--misc" || string(argv[1])=="-M")
        {
            if(argc==2)
            {
                swissapCore::exitCode(0x12D);
            }
            else if(string(argv[2])=="file")
            {
                if(argc==3)
                {
                    swissapCore::exitCode(0x12D);
                }
                else if(string(argv[3])=="read")
                {
                    if(argc==4)
                    {
                        swissapCore::exitCode(0x12D);
                    }
                    else if(argc==5)
                    {
                        file.read(string(argv[4]));
                    }
                    else
                    {
                        swissapCore::exitCode(0x12E);
                    }
                }
                else if(string(argv[3])=="copy")
                {
                    if(argc<=5)
                    {
                        swissapCore::exitCode(0x12D);
                    }
                    else if(argc==6)
                    {
                        file.copy(string(argv[4]),string(argv[5]));
                    }
                    else
                    {
                        swissapCore::exitCode(0x12E);
                    }
                }
                else if(string(argv[3])=="move")
                {
                    if(argc<=5)
                    {
                        swissapCore::exitCode(0x12D);
                    }
                    else if(argc==6)
                    {
                        file.move(string(argv[4]),string(argv[5]));
                    }
                    else
                    {
                        swissapCore::exitCode(0x12E);
                    }
                }
                else if(string(argv[3])=="delete")
                {
                    if(argc==4)
                    {
                        swissapCore::exitCode(0x12D);
                    }
                    else if(argc==5)
                    {
                        file.deleteF(string(argv[4]));
                    }
                    else
                    {
                        swissapCore::exitCode(0x12E);
                    }
                }
                else if(argc>6)
                {
                    swissapCore::exitCode(0x12E);
                }
                else
                {
                    swissapCore::exitCode(0x12D);
                }
            }
            else
            {
                swissapCore::exitCode(0x12F);
            }
        }
        else if(string(argv[1])=="--cryptography" || string(argv[1])=="-c")
        {
            if(argc==2)
            {
                swissapCore::exitCode(0x12D);
            }
            else if (string(argv[2])=="sha1")
            {
                if(argc==4)
                {
                    cout << sha1(argv[3]) << endl;
                    swissapCore::exitCode(0x0);
                }
                else if(argc>4)
                {
                    swissapCore::exitCode(0x12E);
                }
                else
                {
                    swissapCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="sha224")
            {
                if(argc==4)
                {
                    cout << sha224(argv[3]) << endl;
                    swissapCore::exitCode(0x0);
                }
                else if(argc>4)
                {
                    swissapCore::exitCode(0x12E);
                }
                else
                {
                    swissapCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="sha256")
            {
                if(argc==4)
                {
                    cout << sha256(argv[3]) << endl;
                    swissapCore::exitCode(0x0);
                }
                else if(argc>4)
                {
                    swissapCore::exitCode(0x12E);
                }
                else
                {
                    swissapCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="sha384")
            {
                if(argc==4)
                {
                    cout << sha384(argv[3]) << endl;
                    swissapCore::exitCode(0x0);
                }
                else if(argc>4)
                {
                    swissapCore::exitCode(0x12E);
                }
                else
                {
                    swissapCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="sha512")
            {
                if(argc==4)
                {
                    cout << sha512(argv[3]) << endl;
                    swissapCore::exitCode(0x0);
                }
                else if(argc>4)
                {
                    swissapCore::exitCode(0x12E);
                }
                else
                {
                    swissapCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="sha3")
            {
                if(argc==4)
                {
                    cout << sha3(argv[3]) << endl;
                    swissapCore::exitCode(0x0);
                }
                else if (argc==5)
                {
                    cout << sha3(argv[3], atoi(argv[4]));
                }
                else if(argc>5)
                {
                    swissapCore::exitCode(0x12E);
                }
                else
                {
                    swissapCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="md5")
            {
                if(argc==4)
                {
                    cout << md5(argv[3]) << endl;
                    swissapCore::exitCode(0x0);
                }
                else if(argc>4)
                {
                    swissapCore::exitCode(0x12E);
                }
                else
                {
                    swissapCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="aes") {
                if(argc<4)
                {
                    swissapCore::exitCode(0x12D);
                }
                else if(argc>4)
                {
                    if (argc==7)
                    {
                        if(string(argv[3])=="encrypt")
                        {
                            if(atoi(argv[5])==128 || atoi(argv[5])==192 || atoi(argv[5])==256)
                            {
                                aes.encrypt((unsigned char*)argv[4], atoi(argv[5]), (unsigned char*)argv[6]);
                            }
                            else
                            {
                                swissapCore::exitCode(0x13D);
                            }
                        }
                        else if(string(argv[3])=="decrypt")
                        {
                            if(atoi(argv[5])==128 || atoi(argv[5])==192 || atoi(argv[5])==256)
                            {
                                aes.decrypt((unsigned char*)argv[4], atoi(argv[5]), (unsigned char*)argv[6]);
                            }
                            else
                            {
                                swissapCore::exitCode(0x13D);
                            }
                        }
                        else
                        {
                            swissapCore::exitCode(0x12F);
                        }
                    }
                    else if(argc>7)
                    {
                        swissapCore::exitCode(0x12E);
                    }
                    else
                    {
                        swissapCore::exitCode(0x12F);
                    }
                }
                else
                {
                    swissapCore::exitCode(0x12F);
                }
            }
            else
            {
                swissapCore::exitCode(0x12F);
            }
        }
        else
        {
            swissapCore::exitCode(0x12F);
        }
    }
    else
    {
        swissapCore::logo();
        swissapCore::help();
        swissapCore::exitCode(0x0);
    }
    swissapCore::exitCode(0x0);
}