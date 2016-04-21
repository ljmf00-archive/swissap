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

#include <cstdio>
#include <cstdlib>

#include "files.h"

namespace swissapLib
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
