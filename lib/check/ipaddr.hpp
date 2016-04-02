/*lsferreira programming */

/*
                                              _       _
                                             (_)     | |
  ___  ___  _   _ _ __ ___ ___  ___  ___ _ __ _ _ __ | |_
 / __|/ _ \| | | | '__/ __/ _ \/ __|/ __| '__| | '_ \| __|
 \__ \ (_) | |_| | | | (_|  __/\__ \ (__| |  | | |_) | |_
 |___/\___/ \__,_|_|  \___\___||___/\___|_|  |_| .__/ \\__|
                                               | |
                                               |_|
			Copyright  (c) lsferreira programming - 2015
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

class chipaddr {
public:
	bool is_ipv4_address(const string& str)
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

	bool is_ipv6_address(const string& str)
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
};

#endif // SSIPADDR_HPP_INCLUDED