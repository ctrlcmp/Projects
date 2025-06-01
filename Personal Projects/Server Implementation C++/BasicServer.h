#pragma once
#include"BasicSoket.h"
#include<iostream>
using namespace std;


namespace HTS {
	class BasicServer
	{
	private:
		BasicSocket* socket;
		virtual void request_() = 0;
		virtual void respond_() = 0;
		virtual void helper_() = 0;
	public:
		// Constructor
		BasicServer();
		virtual void sender_() = 0;
		//Destructor
		~BasicServer();

		// Getter
		BasicSocket* get_server_socket();

	};

}
