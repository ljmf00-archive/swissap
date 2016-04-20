/*
 * __________  _________ _________
 * \______   \/   _____//   _____/  | BigSource Script
 *  |    |  _/\_____  \ \_____  \   | Project in C/C++ Language
 *  |    |   \/        \/        \  |
 *  |______  /_______  /_______  /  | @author Lu�s Ferreira
 *         \/        \/        \/   | @license GNU Public License v3
 * Copyright (C) 2016 - Luís Ferreira. All right reserved
 * More information in: https://github.com/ljmf00/ (Github Page)
 */

#ifndef BSSERRORS_H_INCLUDED
#define BSSERRORS_H_INCLUDED

#include <cstdlib>
#include "asciiart.h"
#include "help.h"

namespace bssCore
{
void help();
}

namespace bssCore
{
void msgCode(int e_code, std::string name, std::string value, bool endline=false)
    {
    std::cout << std::hex<< name 
              <<"(0x" << e_code << "): " << value;

    if(endline==true)
    {
        std::cout << std::endl;
    }
}

void exitCode(int e_code)
{
    switch(e_code)
    {
    case 0x0:
        exit(e_code);
        break;
    case 0x2:
        msgCode(e_code, "FATAL", "Unknown fatal error", true);
        exit(e_code);
        break;
    case 0x3:
        msgCode(e_code, "FATAL", "Invalid string in bssCore::helpSpecific()", true);
        exit(e_code);
        break;
    case 0x131:
        msgCode(e_code, "WIN32", "WSAStartup failed with an error");
        break;
    case 0x132:
        msgCode(e_code, "WIN32", "getaddrinfo failed with an error");
        break;
    case 0x133:
        msgCode(e_code, "WIN32", "socket failed with an error");
        break;
    case 0x134:
        msgCode(e_code, "WIN32", "bind failed with an error");
        break;
    case 0x135:
        msgCode(e_code, "WIN32", "listen failed with an error");
        break;
    case 0x136:
        msgCode(e_code, "WIN32", "accept failed with an error");
        break;
    case 0x137:
        msgCode(e_code, "WIN32", "send failed with an error");
        break;
    case 0x138:
        msgCode(e_code, "WIN32", "recv failed with an error");
        break;
    case 0x139:
        msgCode(e_code, "WIN32", "shutdown failed with an error");
        break;
    case 0x13A:
        msgCode(e_code, "WIN32", "unable to connect to server");
        break;
    case 0x13B:
        msgCode(e_code, "WIN32", "send failed with an error");
        break;
    case 0x13C:
        msgCode(e_code, "WIN32", "recv failed with an error");
        break;
    case 0x64:
        msgCode(e_code, "INFORMATION", "Success exit in debug mode, return 0x0", false);
        exit(e_code);
        break;
    }
    bssASCII::logo();
    switch(e_code)
    {
    case 0x12D:
        msgCode(e_code, "ERROR", "Argument missing", true);
        break;
    case 0x12E:
        msgCode(e_code, "ERROR", "Too many arguments", true);
        break;
    case 0x12F:
        msgCode(e_code, "ERROR", "Invalid argument", true);
        break;
    case 0x130:
        msgCode(e_code, "ERROR", "Win32Lib not founded");
        exit(e_code);
        break;
    case 0x13D:
        msgCode(e_code, "AESERROR", "Invalid key size");
        std::cout << "\taes" << std::endl
                  << "\t\tdecrypt <key> <keylen> <string>\tAES Decryptation Algoritm" << std::endl
                  << "\t\tencrypt <key> <keylen> <string>\tAES Encryptation Algoritm" << std::endl << std::endl
                  << "<keylen> must be: 128, 192 or 256 bits!" << std::endl;
        exit(e_code);
        break;
    case 0x1:
        msgCode(e_code, "ERROR", "Unknown error", true);
        break;
    default:
        msgCode(e_code, "ERROR", "Unknown exit code", false);
        exit(e_code);
    }
    help();
    exit(e_code);
}
}

#endif // BSSERRORS_H_INCLUDED
