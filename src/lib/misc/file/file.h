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

#ifndef BSSFILES_H_INCLUDED
#define BSSFILES_H_INCLUDED

namespace bssMiscellaneous
{
void readFile(const char* file_name);
void copyFile(const char* source_file, const char* target_file);
void deleteFile(const char* file_name);
void moveFile(const char* source_file, const char* target_file);
}

#endif // BSSFILES_H_INCLUDED
