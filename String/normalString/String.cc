#include"String.h"
#include<iostream>
#include<cstring>
using namespace std;

String::String():_pStr(nullptr){
    cout<<"String()"<<endl;
}

String::String(const char *pStr)
{
    cout<<"String(const char*)"<<endl;

    if(!pStr){
        _pStr = new char[1];
        _pStr[0] = '\0';
    }
    else{
        _pStr = new char[strlen(pStr)+1];
        strcpy(_pStr, pStr);
    }
}


String::String(const String &rhs)     
{
    cout<<"String(const String&)"<<endl;
    if(rhs._pStr == nullptr){
        _pStr = nullptr;
    }
    else{
        _pStr = new char[strlen(rhs._pStr)+1];
        strcpy(_pStr, rhs._pStr);
    }
}

String::String(String &&rhs){
    cout<<"String(String &&)"<<endl;
    _pStr = rhs._pStr;
    rhs._pStr = nullptr;    //这里需要将rhs的底层char*置空，不然会double free
}

String& String::operator=(const String &rhs){
    cout<<"String& operator=(const String&)"<<endl;
    if(this != &rhs && rhs._pStr != nullptr){
        delete []_pStr;
        _pStr = nullptr;

        _pStr = new char[strlen(rhs._pStr)+1];
        strcpy(_pStr, rhs._pStr);
    }
    return *this;
}

String& String::operator= (String &&rhs){
    cout<<"String& operator=(String &&)"<<endl;
    if(this != &rhs && rhs._pStr != nullptr){
        delete []_pStr;
        _pStr = nullptr;
        _pStr = rhs._pStr;

        rhs._pStr = nullptr;
    }
    return *this;
}

String::~String(){
    //cout<<"~String()"<<endl;
    if(_pStr){
        cout<<"~String()"<<endl;
        delete []_pStr;
        _pStr = nullptr;
    }
}

char& String::operator[](int idx) const{
    return _pStr[idx];
}

int String::size() const{
    return strlen(_pStr);
}

char* String::c_str() const{
    return _pStr;
}

ostream& operator<<(ostream &out, String &rhs){
    if(rhs._pStr){
        out << rhs._pStr;
    }
    return out;
}

istream& operator>>(istream &in, String &rhs){
    char buff[1024] = {0};
    in.getline(buff,sizeof(buff));
    rhs = buff;
    return in;
}



