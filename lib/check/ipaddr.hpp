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

#ifndef SSIPADDR_HPP_INCLUDED
#define SSIPADDR_HPP_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
#include <arpa/inet.h>

using std::string;
using std::cout;
using std::endl;
using std::stringstream;

namespace bssCheck {
	bool isIPv4Address(const string& str)
	{
		struct sockaddr_in sa;
		return inet_pton(AF_INET, str.c_str(), &(sa.sin_addr))!=0;

	//    struct sockaddr_in sa;
	//    char ip[INET_ADDRSTRLEN];
	//    inet_pton(AF_INET, str.c_str(), &(sa.sin_addr));
	//    inet_ntop(AF_INET, &(sa.sin_addr), ip, INET_ADDRSTRLEN);
	//    return str==string(ip);

	//    char d;
	//    short ip1,ip2,ip3,ip4;
	//    stringstream ss;
	//    ss << str;
	//    ss >> ip1 >> d >> ip2 >> d >> ip3 >> d >> ip4 >> d;
	//    ss.str("");
	//    ss.clear();
	//    ss << (ip1&0xFF) << "." << (ip2&0xFF) << "." << (ip3&0xFF) << "." << (ip4&0xFF);
	//    return ss.str() == str;
	}

	bool isIPv6Address(const string& str)
	{
		struct sockaddr_in6 sa;
		return inet_pton(AF_INET6, str.c_str(), &(sa.sin6_addr))!=0;

	//    struct sockaddr_in6 sa;
	//    char ip[INET6_ADDRSTRLEN];
	//    inet_pton(AF_INET6, str.c_str(), &(sa.sin6_addr));
	//    inet_ntop(AF_INET6, &(sa.sin6_addr), ip, INET6_ADDRSTRLEN);
	//    return str==string(ip);

	//    const char* s=str.c_str();
	//    int colons=0,segsize=0,i,ix=str.length();
	//    if (s[0]==':' || s[ix-1]==':') return false;
	//
	//    for(colons=0,i=0,segsize=0; i<ix; i++)
	//    {
	//        if (s[i]==':')
	//        {
	//            segsize=0;
	//            colons++;
	//        }
	//        else if (('0' <= s[i] && s[i] <='9') || ('a' <= s[i] && s[i] <='f') )//|| ('A' <= s[i] && s[i] <='F')
	//        {
	//            segsize++;
	//        }
	//        else
	//        {
	//            return false;
	//        }
	//        if (segsize>=5) return false;
	//    }
	//    if (colons>7) return false;
	//    return true;
	}
}

#endif // SSIPADDR_HPP_INCLUDED
