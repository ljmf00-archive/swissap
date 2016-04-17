/*
 * __________  _________ _________
 * \______   \/   _____//   _____/  | BigSource Script
 *  |    |  _/\_____  \ \_____  \   | Project in C/C++ Language
 *  |    |   \/        \/        \  |
 *  |______  /_______  /_______  /  | @author Luís Ferreira
 *         \/        \/        \/   | @license GNU Public License v3
 * Copyright (C) 2016 - Luís Ferreira. All right reserved
 * More information in: https://github.com/ljmf00/ (Github Page)
 */

/* NOTE: This file is only dedicated for
 * main function and their content.
 */

///Libraries
#include <iostream>

//Core Library
#include "help.h"
#include "errors.h"
#include "asciiart.h"

//Cryptography Library
#include "../lib/crypto/sha1/sha1.h"
#include "../lib/crypto/sha2/sha2.h"
#include "../lib/crypto/sha3/sha3.h"
#include "../lib/crypto/md5/md5.h"
#include "../lib/crypto/aes/aes.h"

//Convert Libraries

///Used namespaces
using namespace std;

///Objects
SHA1 sha1;
SHA3 sha3;
MD5 md5;
AES aes;

/// Main Function
int main(int argc, char* argv[])
{
    if(argc >=2)
    {
        if(string(argv[1])=="--cryptography" || string(argv[1])=="-cR")
        {
            if(argc==2)
            {
                bssCore::exitCode(0x12D);
            }
            else if (string(argv[2])=="sha1")
            {
                if(argc==4)
                {
                    cout << sha1(argv[3]) << endl;
                    bssCore::exitCode(0x0);
                }
                else if(argc>4)
                {
                    bssCore::exitCode(0x12E);
                }
                else
                {
                    bssCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="sha224")
            {
                if(argc==4)
                {
                    cout << sha224(argv[3]) << endl;
                    bssCore::exitCode(0x0);
                }
                else if(argc>4)
                {
                    bssCore::exitCode(0x12E);
                }
                else
                {
                    bssCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="sha256")
            {
                if(argc==4)
                {
                    cout << sha256(argv[3]) << endl;
                    bssCore::exitCode(0x0);
                }
                else if(argc>4)
                {
                    bssCore::exitCode(0x12E);
                }
                else
                {
                    bssCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="sha384")
            {
                if(argc==4)
                {
                    cout << sha384(argv[3]) << endl;
                    bssCore::exitCode(0x0);
                }
                else if(argc>4)
                {
                    bssCore::exitCode(0x12E);
                }
                else
                {
                    bssCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="sha512")
            {
                if(argc==4)
                {
                    cout << sha512(argv[3]) << endl;
                    bssCore::exitCode(0x0);
                }
                else if(argc>4)
                {
                    bssCore::exitCode(0x12E);
                }
                else
                {
                    bssCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="sha3")
            {
                if(argc==4)
                {
                    cout << sha3(argv[3]) << endl;
                    bssCore::exitCode(0x0);
                }
                else if (argc==5)
                {
                    cout << sha3(argv[3], atoi(argv[4]));
                }
                else if(argc>5)
                {
                    bssCore::exitCode(0x12E);
                }
                else
                {
                    bssCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="md5")
            {
                if(argc==4)
                {
                    cout << md5(argv[3]) << endl;
                    bssCore::exitCode(0x0);
                }
                else if(argc>4)
                {
                    bssCore::exitCode(0x12E);
                }
                else
                {
                    bssCore::exitCode(0x12D);
                }
            }
            else if (string(argv[2])=="aes") {
                if(argc<4)
                {
                    bssCore::exitCode(0x12D);
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
                                bssCore::exitCode(0x13D);
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
                                bssCore::exitCode(0x13D);
                            }
                        }
                        else
                        {
                            bssCore::exitCode(0x12F);
                        }
                    }
                    else if(argc>7)
                    {
                        bssCore::exitCode(0x12E);
                    }
                    else
                    {
                        bssCore::exitCode(0x12F);
                    }
                }
                else
                {
                    bssCore::exitCode(0x12F);
                }
            }
            else
            {
                bssCore::exitCode(0x12F);
            }
        }
        else
        {
            bssCore::exitCode(0x12F);
        }
    }
    else
    {
        bssASCII::logo();
        bssCore::help();
        bssCore::exitCode(0x0);
    }
    bssCore::exitCode(0x0);
}