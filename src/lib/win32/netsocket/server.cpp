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

#if defined(_WIN32) || defined(_WIN64)

#include "netsocket.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>

///Required Libraries: Windows Sockets
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

///Need to link windows sockets library
#pragma comment (lib, "Ws2_32.lib")

namespace swissapCore {
    extern exitCode(int e_code);
}

namespace swissapLib
{
    void Socket::create(int port, int buffersize)
    {
        WSADATA wsaData;
        int iResult;

        SOCKET ListenSocket = INVALID_SOCKET;
        SOCKET ClientSocket = INVALID_SOCKET;

        struct addrinfo *result = NULL;
        struct addrinfo hints;

        int iSendResult;
        char recvbuf[buffersize];
        int recvbuflen = buffersize;

        // Initialize Winsock
        iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
        if (iResult != 0)
        {
            swissapCore::exitCode(0x131);
            std::cout << iResult << std::endl;
            exit(0x131);
        }

        ZeroMemory(&hints, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;
        hints.ai_flags = AI_PASSIVE;

        // Resolve the server address and port
        iResult = getaddrinfo(NULL, (const char*)port, &hints, &result);
        if ( iResult != 0 )
        {
            swissapCore::exitCode(0x132);
            std::cout << iResult << std::endl;
            WSACleanup();
            //return error code
            exit(0x132);
        }

        // Create a SOCKET for connecting to server
        ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
        if (ListenSocket == INVALID_SOCKET)
        {
            swissapCore::exitCode(0x133);
            std::cout << WSAGetLastError() << std::endl;
            freeaddrinfo(result);
            WSACleanup();
            exit(0x133);

        }

        // Setup the TCP listening socket
        iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
        if (iResult == SOCKET_ERROR)
        {
            swissapCore::exitCode(0x134);
            std::cout << WSAGetLastError() << std::endl;
            freeaddrinfo(result);
            closesocket(ListenSocket);
            WSACleanup();
            exit(0x134);
        }

        freeaddrinfo(result);

        iResult = listen(ListenSocket, SOMAXCONN);
        if (iResult == SOCKET_ERROR)
        {
            swissapCore::exitCode(0x135);
            std::cout << WSAGetLastError() << std::endl;
            closesocket(ListenSocket);
            WSACleanup();
            exit(0x135);
        }

        // Accept a client socket
        ClientSocket = accept(ListenSocket, NULL, NULL);
        if (ClientSocket == INVALID_SOCKET)
        {
            swissapCore::exitCode(0x136);
            std::cout << WSAGetLastError() << std::endl;
            closesocket(ListenSocket);
            WSACleanup();
            exit(0x136);
        }

        // No longer need server socket
        closesocket(ListenSocket);

        // Receive until the peer shuts down the connection
        do
        {

            iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
            if (iResult > 0)
            {
                std::cout << "Bytes received: " << iResult << std::endl;

                // Echo the buffer back to the sender
                iSendResult = send( ClientSocket, recvbuf, iResult, 0 );
                if (iSendResult == SOCKET_ERROR)
                {
                    swissapCore::exitCode(0x137);
                    std::cout << WSAGetLastError() << std::endl;
                    closesocket(ClientSocket);
                    WSACleanup();
                    exit(0x137);
                }
                std::cout << "Bytes sent: " << iSendResult << std::endl;
            }
            else if (iResult == 0)
                std::cout << "Connection closing..." << std::endl;
            else
            {
                
                swissapCore::exitCode(0x138);
                std::cout << WSAGetLastError() << std::endl;
                closesocket(ClientSocket);
                WSACleanup();
                exit(0x138);
            }

        }
        while (iResult > 0);

        // shutdown the connection since we're done
        iResult = shutdown(ClientSocket, SD_SEND);
        if (iResult == SOCKET_ERROR)
        {
            swissapCore::exitCode(0x139);
            std::cout << WSAGetLastError() << std::endl;
            closesocket(ClientSocket);
            WSACleanup();
            exit(0x139);
        }

        // cleanup
        closesocket(ClientSocket);
        WSACleanup();
        swissapCore::exitCode(0x0);
    }
}
#endif // _WIN32 || _WIN64
