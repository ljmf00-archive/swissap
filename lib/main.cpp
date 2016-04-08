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
#include "core/help.hpp"
#include "core/errors.hpp"
#include "core/asciiart.hpp"

//Cryptography Library
#include "crypto/sha1/sha1.h"
#include "crypto/sha2/sha2.h"
#include "crypto/sha3/sha3.h"

//Convert Libraries
#include "convert/types/string_int.hpp"

///Used namespaces
using namespace std;

///Objects
SHA1 sha1;
SHA3 sha3;

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
                    cout << sha1(argv[3]);
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
                    cout << sha224(argv[3]);
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
                    cout << sha256(argv[3]);
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
                    cout << sha384(argv[3]);
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
                    cout << sha512(argv[3]);
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
                    cout << sha3(argv[3]);
                    bssCore::exitCode(0x0);
                }
                else if (argc=5)
                {
                    cout << sha3(argv[3], bssConvert::stringToInt(string(argv[4])));
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
            else
            {
                bssCore::exitCode(0x12F);
            }
        }
        else
        {

        }
    }
    else
    {
        bssCore::exitCode(0x12D);
    }
    bssCore::exitCode(0x0);
}
