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

#ifndef SWISSAPFILES_H_INCLUDED
#define SWISSAPFILES_H_INCLUDED

namespace swissapLib
{
void readFile(const char* file_name);
void copyFile(const char* source_file, const char* target_file);
void deleteFile(const char* file_name);
void moveFile(const char* source_file, const char* target_file);
}

#endif // SWISSAPFILES_H_INCLUDED
