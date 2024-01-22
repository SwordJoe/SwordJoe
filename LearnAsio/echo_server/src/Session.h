#pragma once
#include "boost/asio.hpp"
using namespace boost;

class Session{
public:
    Session(asio::io_context& ioc):_socket(ioc){}
    ~Session(){}

    asio::ip::tcp::socket& socket(){return _socket;}

    void start();

private:
    void handle_read(const boost::system::error_code& error, std::size_t bytes_transfered);
    void handle_write(const boost::system::error_code& error);

private:
    asio::ip::tcp::socket _socket;
    char _data[1024];
};