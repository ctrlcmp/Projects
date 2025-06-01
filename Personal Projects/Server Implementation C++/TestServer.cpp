	#include "TestServer.h"
	#include <io.h>

HTS::TestServer::TestServer()
{ 
	sender_();
}
void HTS::TestServer::request_()
{
	// Variables 
	struct sockaddr_in address_of_socket = get_server_socket()->get_address();
	int length_of_address = sizeof(address_of_socket);
	
	//Accepting request 
	Test_server_socket = accept(get_server_socket()->get_socket()
	, (struct sockaddr*)&address_of_socket,(socklen_t *)&length_of_address);
	
	
	//Writing request to a buffer variable(JSON?)
	recv(Test_server_socket, buffer, sizeof(buffer),0);

}

void HTS::TestServer::helper_()
{
	cout << buffer << endl;
}

void HTS::TestServer::respond_()
{
	// Example but it will be Specified what to request and respond later
	const char *responder;
	if (buffer == "Hello") {
		responder = "Hello back";
	}
	else responder = "Something else to respond ";

	//Responding to server request!!!
	send(Test_server_socket, responder, strlen(responder),0);
}	



void HTS::TestServer::sender_()
{
	while (true) {
		cout << "===== Waiting =====" << endl;
		request_();
		respond_();
		//helper_();
		cout << "===== Done comunicating =====" << endl;
	}
}

HTS::TestServer::~TestServer()
{
	closesocket(Test_server_socket);
	// don't know if it is needed 
	WSACleanup();
}
