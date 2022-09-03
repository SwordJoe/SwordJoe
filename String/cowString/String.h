#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class String
{
    friend ostream& operator<<(ostream& out, String &rhs);
public:
    String();
    String(const char *str);
    String(const String &rhs);
    String& operator= (const String &rhs);
    ~String();

    char& operator[] (int idx);
    int size() const{ return strlen(_pStr);}
    char *c_str() const { return _pStr;}

//private:
    int& refCnt() { return *(int*)(_pStr - 4);}
private:
    char *_pStr;
    static char _nullchar;
};