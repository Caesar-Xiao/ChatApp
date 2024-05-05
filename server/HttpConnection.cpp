#include <iostream>
#include <memory>
#include "HttpConnection.h"

HttpConnection::HttpConnection(tcp::socket socket) : _socket(std::move(socket))
{
}

void HttpConnection::Start()
{
	auto self = shared_from_this();
	http::async_read(_socket, _buffer, _request, [self](beast::error_code err,
		std::size_t bytes_transferred) {
			try {
				if (err) {
					std::cout << "http read err is " << err.what() << std::endl;
					return;
				}
				//��������������
				boost::ignore_unused(bytes_transferred);
				self->HandleReq();
				self->CheckDeadline();
			}
			catch (std::exception& exp) {
				std::cout << "exception is " << exp.what() << std::endl;
			}
		}
	);
}

void HttpConnection::HandleReq()
{
	//���ð汾
	_response.version(_request.version());
	//����Ϊ������
	_response.keep_alive(false);
	if (_request.method() == http::verb::get) {
		bool success = LogicSystem::GetInstance()->HandleGet(_request.target(), shared_from_this());
		if (!success) {
			_response.result(http::status::not_found);
			_response.set(http::field::content_type, "text/plain");
			beast::ostream(_response.body()) << "url not found\r\n";
			WriteResponse();
			return;
		}
		_response.result(http::status::ok);
		_response.set(http::field::server, "GateServer");
		WriteResponse();
		return;
	}
}