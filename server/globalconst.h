#pragma once

#include <boost/beast/http.hpp>
#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <memory>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

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
