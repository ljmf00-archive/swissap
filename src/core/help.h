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

#ifndef BSSHELP_H_INCLUDED
#define BSSHELP_H_INCLUDED

#include <iostream>
#include "errors.h"

namespace bssCore
{
void help();
void exitCode(int e_code);
}

#include "errors.h"

namespace bssCore
{
void helpMain()
{
    std::cout << "Usage: bss (arg_choise) [argv] ...\n" << std::endl;
    std::cout << "Available commands:" << std::endl;
}
void helpSpecific(std::string name)
{
    if(name=="cryptography")
    {
        std::cout << "  -cR --cryptography" << std::endl
                  << "       aes" << std::endl
                  << "          decrypt <key> <keylen> <string>   AES Decryptation Algoritm (Hexadecimal Block)" << std::endl
                  << "          encrypt <key> <keylen> <string>   AES Encryptation Algoritm (Hexadecimal Block)" << std::endl
                  << "       md5 <string>                         MD5 Hash Calculation" << std::endl
                  << "       sha1 <string>                        SHA-1 Hash Calculation" << std::endl
                  << "       sha224 <string>                      SHA-224 Hash Calculation" << std::endl
                  << "       sha256 <string>                      SHA-256 Hash Calculation" << std::endl
                  << "       sha384 <string>                      SHA-384 Hash Calculation" << std::endl
                  << "       sha512 <string>                      SHA-512 Hash Calculation" << std::endl
                  << "       sha3 <string> [bits]                 SHA-3 Hash Calculation" << std::endl;
    }
    else if(name=="win32lib")
    {
        std::cout << "  --win32" << std::endl
                  << "       " << std::endl;
    }
    else
    {
        exitCode(3);
    }
}
void helpOnce(std::string name)
{
    helpMain();
    helpSpecific(name);
}
void help()
{
    helpMain();
    helpSpecific("cryptography");

}
}

#endif // BSSHELP_H_INCLUDED
