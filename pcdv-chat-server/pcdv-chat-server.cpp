#include <iostream>
//#include "stadfx.h"
#include <winsock2.h>
#include <ws2tcpip.h>

using namespace std;

int main()
{
    SOCKET serverSocket, acceptSocket;
    int port = 55555;
    WSADATA wsaData;
    int wsaError;
    WORD wVersionRequested = MAKEWORD(2, 2);

    wsaError = WSAStartup(wVersionRequested, &wsaData);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


//ws2_32.lib;%(AdditionalDependencies)