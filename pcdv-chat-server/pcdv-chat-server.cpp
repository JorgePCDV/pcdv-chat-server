#include <iostream>
//#include "stadfx.h"
#include <tchar.h>
#include <winsock2.h>
#include <ws2tcpip.h>

using namespace std;

int main()
{
    cout << "Step 1: Setting up DLL" << endl;
    SOCKET serverSocket, acceptSocket;
    int port = 55555;
    WSADATA wsaData;
    int wsaError;
    WORD wVersionRequested = MAKEWORD(2, 2);

    wsaError = WSAStartup(wVersionRequested, &wsaData);

    if (wsaError != 0) 
    {
        cout << "Winsock dll not found!" << endl;
        return 0;
    }
    else 
    {
        cout << "Winsock dll found!" << endl;
        cout << "Status: " << wsaData.szSystemStatus << endl;
    }

    cout << "Step 2: Setting up Server Socket" << endl;

    serverSocket = INVALID_SOCKET;
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (serverSocket == INVALID_SOCKET) 
    {
        cout << "Error at socket():" << WSAGetLastError() << endl;
        WSACleanup();
        return 0;
    }
    else 
    {
        cout << "socket() is OK!" << endl;
    }

    cout << "Step 3: Bind Socket" << endl;
    sockaddr_in service;
    service.sin_family = AF_INET;

    InetPton(AF_INET, _T("127.0.0.1"), &service.sin_addr.s_addr);
    service.sin_port = htons(port);
    if(bind(serverSocket, (SOCKADDR*)&service, sizeof(service))==SOCKET_ERROR)
    {
        cout << "bind() failed: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 0;
    }
    else 
    {
        cout << "bind() is OK!" << endl;
    }

    cout << "Step 4: Initiate Listen" << endl;
    if (listen(serverSocket, 1) == SOCKET_ERROR) 
    {
        cout << "listen(): Error listening on socket" << WSAGetLastError() << endl;
    }
    else 
    {
        cout << "listen() is OK, server waiting for connections" << endl;
    }

    cout << "Step 5: Accept Connections" << endl;
    acceptSocket = accept(serverSocket, NULL, NULL);
    if (acceptSocket == INVALID_SOCKET) 
    {
        cout << "Accept failed:" << WSAGetLastError() << endl;
        WSACleanup();
        return -1;
    }
    cout << "Accepted connection" << endl;
    system("pause");
    WSACleanup();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


//ws2_32.lib;%(AdditionalDependencies)