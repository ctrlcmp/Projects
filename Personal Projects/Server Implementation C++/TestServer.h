#pragma once
#include"BasicServer.h"
#include<iostream>
using namespace std;

namespace HTS {

	class TestServer :public BasicServer
	{
	private:
		  char buffer[30000] = { 0 };
		  SOCKET Test_server_socket;
		  void request_()override;
		  void respond_()override;
		  void helper_()override;
	public:
		TestServer();
		void sender_()override;
		~TestServer();
	};

}
