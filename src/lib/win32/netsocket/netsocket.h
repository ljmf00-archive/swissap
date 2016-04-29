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

#ifndef WIN32NETSOCKET_H_INCLUDED
#define WIN32NETSOCKET_H_INCLUDED

#if defined(_WIN32) || defined(_WIN64)

#include <iostream>

namespace swissapLib
{
	struct Socket
	{
		void create(int port=27015, int buffersize=512);
		void client(std::string sendmsg,std::string address ,int port, int buffersize);
	};
}

#endif // _WIN32 || _WIN64
#endif //WIN32NETSOCKET_H_INCLUDED
