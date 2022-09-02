#include<iostream>
#include<string>
#include<cstring>
using namespace std;


int main()
{
    char *str = nullptr;
    char *_pStr = new char[strlen(str) + 1];
    strcpy(str, _pStr);
    cout<<_pStr<<endl;
    cout<<strlen(_pStr)<<endl;


    cout<<"hel"<<endl;
}