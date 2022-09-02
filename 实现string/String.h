#pragma once
#include<iostream>
using namespace std;

class String
{
public:
    String();
    String(const char* pStr);           //const char*参数的构造函数
    String(const String &rhs);          //拷贝构造函数
    String& operator= (const String &rhs);      //赋值运算符函数
    ~String();
    
    char& operator[] (int idx) const;    //重载[]，返回值char& 很重要，有可能str1[0]='A',所以需要返回引用
    int size() const;
    char *c_str() const;
    
private:
    char *_pStr;
    friend ostream& operator<<(ostream& out, String &rhs);   //重载输出运算符
};