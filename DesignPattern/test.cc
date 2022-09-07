#include"simpleFactory.h"
#include<iostream>
#include<string>
using namespace std;


int main()
{  
    string name;
    while(1){
        cin >> name;
        Factory fac;
        shared_ptr<AbstractProduct> sp = fac.getProduct(name);
        if(sp){
            sp->printName();
            sp->play();
            cout<<endl;
        }
        else{
            cout<<"空指针"<<endl;
        }
    }
}