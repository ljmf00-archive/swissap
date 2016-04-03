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

///Used namespaces
using namespace std;

///Objects
SHA1 sha1;

/// Main Function
int main(int argc, char* argv[])
{
    if(argc >=2)
    {
        if(string(argv[1])=="--cryptography" || string(argv[1])=="-cR")
        {
            if(argc==2)
            {
                bssCore::exitCode(301);
            }
            else if (string(argv[2])=="sha1")
            {
                if(argc==4)
                {
                    cout << sha1(argv[3]);
                    bssCore::exitCode(0);
                }
                else if(argc>4)
                {
                    bssCore::exitCode(302);
                }
                else
                {
                    bssCore::exitCode(301);
                }
            }
            else if (string(argv[2])=="sha224")
            {
                if(argc==4)
                {
                    cout << sha224(argv[3]);
                    bssCore::exitCode(0);
                }
                else if(argc>4)
                {
                    bssCore::exitCode(302);
                }
                else
                {
                    bssCore::exitCode(301);
                }
            }
            else if (string(argv[2])=="sha256")
            {
                if(argc==4)
                {
                    cout << sha256(argv[3]);
                    bssCore::exitCode(0);
                }
                else if(argc>4)
                {
                    bssCore::exitCode(302);
                }
                else
                {
                    bssCore::exitCode(301);
                }
            }
            else if (string(argv[2])=="sha384")
            {
                if(argc==4)
                {
                    cout << sha384(argv[3]);
                    bssCore::exitCode(0);
                }
                else if(argc>4)
                {
                    bssCore::exitCode(302);
                }
                else
                {
                    bssCore::exitCode(301);
                }
            }
            else if (string(argv[2])=="sha512")
            {
                if(argc==4)
                {
                    cout << sha512(argv[3]);
                    bssCore::exitCode(0);
                }
                else if(argc>4)
                {
                    bssCore::exitCode(302);
                }
                else
                {
                    bssCore::exitCode(301);
                }
            }
            else
            {
                bssCore::exitCode(303);
            }
        }
        else
        {

        }
    }
    else
    {
        bssCore::exitCode(301);
    }
    bssCore::exitCode(0x0);
}

