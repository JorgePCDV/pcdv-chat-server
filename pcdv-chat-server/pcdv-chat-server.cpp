#include <iostream>
//#include "stadfx.h"
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
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


//ws2_32.lib;%(AdditionalDependencies)