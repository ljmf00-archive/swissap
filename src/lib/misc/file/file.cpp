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

#include <iostream>
#include <fstream>
#include <string>

#include "file.h"

namespace swissapCore
{
    extern void exitCode(int e_code);
}

namespace swissapLib
{
void File::read(std::string file_name)
{
    std::string line;
    std::ifstream file(file_name);
    if(file.is_open())
    {
        while(getline(file,line))
        {
            std::cout << line << std::endl;
        }
    }
    else
    {
        swissapCore::exitCode(0x13F);
    }
    file.close();
}
void File::copy(std::string source_file, std::string target_file)
{
    std::string line;
    std::ifstream srcfile(source_file);
    std::ofstream trgfile(target_file);
    if(srcfile.is_open() && trgfile.is_open())
    {
        while(getline(srcfile,line))
        {
            trgfile << line << std::endl;
        }
        std::cout << "File copied!" << std::endl;
    }
    else
    {
        swissapCore::exitCode(0x140);
    }
}
void File::deleteF(std::string file_name)
{
    if( remove(file_name.c_str()) != 0 )
    {
        swissapCore::exitCode(0x141);
    }
    else
    {
        std::cout << "File deleted!" << std::endl;
    }
}
void File::move(std::string source_file, std::string target_file)
{
    copy(source_file, target_file);
    deleteF(source_file);
    std::cout << "File moved!" << std::endl;
}
}
