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

#ifndef BSSWIN32_CLIENT_HPP_INCLUDED
#define BSSWIN32_CLIENT_HPP_INCLUDED

#define WIN32_LEAN_AND_MEAN

#include "../../core/errors.hpp"

#include <iostream>
#include <cstdlib>
#include <cstdio>

/// Required Libraries: Windows Sockets
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

/// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

namespace bssWin32 {
struct Socket {
	void client(std::string sendmsg, int port=27015, int buffersize=512)
{
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
    char *sendbuf = sendmsg.c_str();
    char recvbuf[buffersize];
    int iResult;
    int recvbuflen = buffersize;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        bssCore::exitCode(0x131);
        std::cout << iResult << std::endl;
        exit(0x131);
    }

    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo(argv[1], port, &hints, &result);
    if ( iResult != 0 ) {
        bssCore::exitCode(0x132);
        std::cout << iResult << std::endl;
        WSACleanup();
        exit(0x132);
    }

    // Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, 
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            bssCore::exitCode(0x133);
            std::cout << WSAGetLastError() << std::endl;
            WSACleanup();
            exit(0x133);
        }

        // Connect to server.
        iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        bssCore::exitCode(0x13A);
        WSACleanup();
        exit(0x13A);
    }

    // Send an initial buffer
    iResult = send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );
    if (iResult == SOCKET_ERROR) {
    	bssCore::exitCode(0x13B);
    	std::cout << WSAGetLastError() << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        exit(0x13B);
    }
    std::cout << "Bytes Sent: " << iResult << std::endl;

    // shutdown the connection since no more data will be sent
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
    	bssCore::exitCode(0x139);
    	std::cout << WSAGetLastError() << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        exit(0x139);
    }

    // Receive until the peer closes the connection
    do {

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 )
        	std::cout << "Bytes received: " << iResult << std::endl;
        else if ( iResult == 0 )
        	std::cout << "Connection closed" << std::endl;
        else
        	bssCore::exitCode(0x13C);
        	std::cout << WSAGetLastError() << std::endl;
        	exit(0x13C);

    } while( iResult > 0 );

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();
}
};
}

#endif // BSSWIN32_CLIENT_HPP_INCLUDED
