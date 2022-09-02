#include"String.h"
#include<iostream>
#include<cstring>
using namespace std;

String::String():_pStr( new char[1]){
    _pStr[0] = '\0';
}

String::String(const char *pStr){
    if(pStr == nullptr){
        _pStr = new char[1];
        _pStr[0]='\0';
    }
    if(_pStr == nullptr){
        _pStr = new char[strlen(pStr)+1];      
        strcpy(_pStr, pStr);
    }
}

String::String(const String &rhs){
    
}