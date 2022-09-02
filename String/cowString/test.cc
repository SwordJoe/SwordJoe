#include"String.h"
#include<iostream>
using namespace std;


int main()
{
    String str1("swordjoe");
    cout<<str1.refCnt()<<endl;
    String str2 = str1;
    cout<<str1.refCnt()<<endl;

    str2[0]='S';
    str2[5]='J';
    cout<<str1.refCnt()<<endl;
    cout<<str2.refCnt()<<endl;
    cout<<str1<<endl;
    cout<<str2<<endl;
}