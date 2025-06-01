#include "BasicServer.h"

HTS::BasicServer::BasicServer()
{
	socket = new BasicSocket();
}

HTS::BasicServer::~BasicServer()
{
	delete socket;
}

HTS::BasicSocket* HTS::BasicServer::get_server_socket()
{
	return this->socket;
}
