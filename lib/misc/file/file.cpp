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

#include <cstdio>
#include <cstdlib>

#include "files.h"

namespace bssMiscellaneous
{
void readFile(const char* file_name)
{
    char ch;
    FILE *fp;
    fp=fopen(file_name,"r");
    if (fp==NULL)
    {
        exit(EXIT_FAILURE);
    }
    while((ch=fgetc(fp))!= EOF)
        printf("%c",ch);
    fclose(fp);
}
void copyFile(const char* source_file, const char* target_file)
{
    char ch;
    FILE *source, *target;
    source = fopen(source_file, "r");
    if( source == NULL )
    {
        exit(EXIT_FAILURE);
    }
    target = fopen(target_file, "w");
    if( target == NULL )
    {
        fclose(source);
        exit(EXIT_FAILURE);
    }
    while( ( ch = fgetc(source) ) != EOF )
        fputc(ch, target);
    fclose(source);
    fclose(target);
}
void deleteFile(const char* file_name)
{
    int status;
    status = remove(file_name);
    if( status != 0 )
    {
        //error...
    }
}
void moveFile(const char* source_file, const char* target_file)
{
    copyFile(source_file, target_file);
    deleteFile(source_file);
}
}
