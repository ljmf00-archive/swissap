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
	struct File {
		void read(std::string file_name);
		void copy(std::string source_file, std::string target_file);
		void deleteF(std::string file_name);
		void move(std::string source_file, std::string target_file);
	};
}

#endif // SWISSAPFILES_H_INCLUDED
