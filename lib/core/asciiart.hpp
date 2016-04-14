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

#ifndef BSSASCIIART_HPP_INCLUDED
#define BSSASCIIART_HPP_INCLUDED

#include <iostream>

namespace bssASCII
{
void logoOnce()
{
    std::cout << "__________  _________ _________" << std::endl
              << "\\______   \\/   _____//   _____/ | BigSource Script" << std::endl
              << " |    |  _/\\_____  \\ \\_____  \\  | Project in C/C++ Language" << std::endl
              << " |    |   \\/        \\/        \\ |" << std::endl
              << " |______  /_______  /_______  / | @author Luís Ferreira" << std::endl
              << "        \\/        \\/        \\/  | @license GNU Public License v3" << std::endl;
}
void logo()
{
    logoOnce();
    std::cout << "---------------------------------------------------------" << std::endl << std::endl;

}
}

#endif // BSSASCIIART_HPP_INCLUDED
