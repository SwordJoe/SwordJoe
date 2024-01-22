#include"Session.h"
#include<cstring>
#include<iostream>
using namespace std::placeholders;

void Session::start(){
    memset(_data, 0, sizeof(_data));
    _socket.async_read_some(asio::buffer(_data, 1024),
            std::bind(&Session::handle_read, this, _1, _2));
}

void Session::handle_read(const boost::system::error_code& error, std::size_t bytes_transfered){
    if(!error){
        std::cout<<"Received: "<<_data<<std::endl;
        _socket.async_send(asio::buffer(_data, bytes_transfered),  std::bind(&Session::handle_write, this, _1));
    }
    else{
        delete this;
    }
}

void Session::handle_write(const boost::system::error_code& error){
    if(!error){
        memset(_data, 0, sizeof(_data));
        _socket.async_read_some(asio::buffer(_data, 1024), std::bind(&Session::handle_read, this, _1, _2));
    }
    else{
        delete this;
    }
}
