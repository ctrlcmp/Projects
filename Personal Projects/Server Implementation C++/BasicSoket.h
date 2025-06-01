#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib") // Linkovanje Winsock biblioteke

using namespace std;
#define PORT 8080; // port za HTTPS 
#pragma once
namespace HTS {
	class BasicSocket
	{
	private:
		sockaddr_in adresa;
		WSADATA wsaData;
		SOCKET server_socket;
	public:
		BasicSocket();
		int connect_to_network(SOCKET, sockaddr_in);
		bool listening(SOCKET, int);
		//Getters
		struct sockaddr_in get_address();
		SOCKET get_socket();

		~BasicSocket();
	};


}
