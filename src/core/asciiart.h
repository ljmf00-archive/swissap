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

#ifndef BSSASCIIART_H_INCLUDED
#define BSSASCIIART_H_INCLUDED

#include <iostream>

namespace bssASCII
{
void logoOnce()
{
    std::cout << "  ___  _  ___  _____ _______  _____ ___.__.______   | Swiss Army Project" << std::endl
              << " / _/_| |_\\_ \\ \\__  \\\\_  __ \\/     <   |  |\\____ \  | Project in C/C++ Language" << std::endl
              << " || |_   _| ||  / __ \\|  | \\/  Y Y  \\___  ||  |_> > |" << std::endl
              << " ||_  |_|  _|| (____  /__|  |__|_|  / ____||   __/  | @author Luís Ferreira" << std::endl
              << " \__\     /__/      \\/            \\/\\/     |__|     | @license GNU Public License v3" << std::endl;
}
void logo()
{
    logoOnce();
    std::cout << "---------------------------------------------------------" << std::endl << std::endl;

}
}

#endif // BSSASCIIART_H_INCLUDED
