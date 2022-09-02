#include"String.h"
#include<iostream>
#include<cstring>
using namespace std;

String::String():_pStr( new char[1]){
    cout<<"String()"<<endl;
    _pStr[0] = '\0';
}

String::String(const char *pStr)
:_pStr(new char[strlen(pStr)+1])
{
    cout<<"String(const char*)"<<endl;
    strcpy(_pStr, pStr);
}

String::String(const String &rhs)
:_pStr(new char[strlen(rhs._pStr)+1])
{
    cout<<"String(const String&)"<<endl;
    strcpy(_pStr, rhs._pStr);
}

String& String::operator=(const String &rhs){
    cout<<"String& operator=(const String&)"<<endl;
    if(this != &rhs){
        delete []_pStr;
        _pStr = nullptr;

        _pStr = new char[strlen(rhs._pStr)+1];
        strcpy(_pStr, rhs._pStr);
    }
    return *this;
}

String::~String(){
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
    out<<rhs._pStr;
    return out;
}




