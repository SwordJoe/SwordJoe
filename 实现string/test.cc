#include<iostream>
#include"String.h"
using namespace std;


int main()
{
    String str1;
    String str2("hello world");
    String str3(str2);
    str1 = str3;
    cout<<str1<<endl;
    str1[0]='H';
    cout<<str1<<endl;
}
