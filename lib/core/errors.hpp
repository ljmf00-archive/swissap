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

#ifndef BSSERRORS_HPP_INCLUDED
#define BSSERRORS_HPP_INCLUDED

#include <cstdlib>
#include "asciiart.hpp"
#include "help.hpp"

namespace bssCore
{
void msgCode(int e_code, std::string name, std::string value, bool endline=false) {
    std::cout <<std::hex<< name <<"(0x" << e_code << "): " << value;
    if(endline=true){
        std::cout << std::endl;
    }
}
void debugCode(int d_code)
{
}
void exitCode(int e_code)
{
    switch(e_code)
    {
    case 0x0:
        exit(e_code);
        break;
    case 2:
        msgCode(e_code, "FATAL", "Unknown fatal error", true);
        exit(e_code);
        break;
    case 3:
        msgCode(e_code, "FATAL", "Invalid string in bssCore::helpSpecific()", true);
        exit(e_code);
        break;
    case 100:
        msgCode(e_code, "INFORMATION", "Success exit in debug mode, return 0x0", false);
        exit(e_code);
        break;
    }
    bssASCII::logo();
    switch(e_code)
    {
    case 301:
        msgCode(e_code, "ERROR", "Argument missing", true);
        break;
    case 302:
        msgCode(e_code, "ERROR", "Too much arguments", true);
        break;
    case 303:
        msgCode(e_code, "ERROR", "Invalid argument", true);
        break;
    case 304:
        msgCode(e_code, "ERROR", "Win32Lib not founded");
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

#endif // BSSERRORS_HPP_INCLUDED
