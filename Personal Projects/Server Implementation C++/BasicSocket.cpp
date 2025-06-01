#include "BasicSoket.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include<iostream>
#pragma comment(lib, "Ws2_32.lib") // Linkovanje Winsock biblioteke
using namespace std;

HTS::BasicSocket::BasicSocket() {
    
    // Setting version of winsock2 lib and trying if it works
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << " WINSOCK biblioteka nije incijalizovana!" << endl;
        exit(1);
    }

    adresa.sin_family = AF_INET;
    adresa.sin_port = htons(8080);            // usable port for server(HTTP port here!)
    adresa.sin_addr.s_addr = INADDR_ANY;     // server now is  excepting any address

    // definition file descriptor server_socket
    server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (server_socket == INVALID_SOCKET) {
        cout << " Server_socket variable is not declared properly ";
        exit(1);
    }
    cout << "Socket is declared! " << endl ;
    if (connect_to_network(server_socket, adresa) == SOCKET_ERROR) {
        cout << "Binding problem !!!" << endl;
        exit(1);
    }
    cout << "Socket is connected to network" << endl;;
    if (!listening(server_socket, SOMAXCONN)) {
        cout << "Listening problem!!";
        exit(1);
    }
    cout << "Socket is listening the PORT" << endl;
}  

// Binding Socket to specific IPA and PORT
int HTS::BasicSocket::connect_to_network(SOCKET soket, sockaddr_in adresa)
{
    return bind(soket, (const sockaddr*)&adresa,sizeof(adresa));
}

bool HTS::BasicSocket::listening(SOCKET server , int queue)    
{
    return listen(server, queue) == 0;
}

// Getters
sockaddr_in HTS::BasicSocket::get_address()
{
    return adresa;
}

SOCKET HTS::BasicSocket::get_socket()
{
    return server_socket;
}

// Destructor => Closing socket
HTS::BasicSocket::~BasicSocket()
{
    closesocket(server_socket);
    WSACleanup();
}
