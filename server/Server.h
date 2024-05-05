#pragma once

#include "globalconst.h"

class Server :
	public std::enable_shared_from_this<Server>
{
public:
	Server(boost::asio::io_context& ioc, unsigned short& port);
	void Start();

private:
	tcp::acceptor  _acceptor;
	net::io_context& _ioc;
	boost::asio::ip::tcp::socket   _socket;
};
