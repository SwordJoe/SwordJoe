#include<iostream>
#include<cstring>
#include"String.h"
using namespace std;


int main()
{
    String str1("HelloWorld");
    String str2(str1);
    String str3;
    str3 = str1;

    String str4(std::move(str1));
    cout<<str1<<endl;
    cout<<str4<<endl;
}