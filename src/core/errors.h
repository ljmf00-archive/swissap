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

#ifndef SWISSAPERRORS_H_INCLUDED
#define SWISSAPERRORS_H_INCLUDED

#include <cstdlib>
#include "asciiart.h"
#include "help.h"

namespace swissapCore
{
    void help();
    void helpSpecific(std::string name);
}

namespace swissapCore
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
            msgCode(e_code, "FATAL", "Not enough memory", true);
            exit(e_code);
            break;
        case 0x3:
            msgCode(e_code, "FATAL", "Unknown fatal error", true);
            exit(e_code);
            break;
        case 0x4:
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
        swissapCore::logo();
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
            msgCode(e_code, "AESERROR", "Invalid key size\n <keylen> must be: 128, 192 or 256 bits!");
            helpSpecific("cryptography");
            exit(e_code);
            break;
        case 0x13E:
            msgCode(e_code, "ERROR", "Invalid help command", true);
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

#endif // SWISSAPERRORS_H_INCLUDED
