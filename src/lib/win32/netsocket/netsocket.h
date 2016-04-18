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

#ifndef WIN32NETSOCKET_H_INCLUDED
#define WIN32NETSOCKET_H_INCLUDED

#if defined(_WIN32) || defined(_WIN64)

namespace bssWin32
{
	struct Socket
	{
		void create(int port=27015, int buffersize=512);
		void client(std::string sendmsg, int port=27015, int buffersize=512);
	};
}

#endif // _WIN32 || _WIN64
#endif //WIN32NETSOCKET_H_INCLUDED
