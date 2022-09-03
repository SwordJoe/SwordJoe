#include"SharedPtr.h"
#include<iostream>
#include<memory>
using namespace std;


int main()
{
    SharedPtr<int> sp1(new int(100));
    SharedPtr<int> sp2(sp1);
    SharedPtr<int> sp3(sp1);
    SharedPtr<int> sp4(sp1);
    cout<<"sp1.useCnt()="<<sp1.useCnt()<<endl;
    SharedPtr<int> sp_0(std::move(sp1));
    cout<<"sp_0.useCnt()="<<sp_0.useCnt()<<endl;
    SharedPtr<int> sp_1(std::move(sp2));
    cout<<"sp_1.useCnt()="<<sp_1.useCnt()<<endl;
    cout<<"sp1.useCnt()="<<sp1.useCnt()<<endl;
    cout<<"hello world"<<endl;
    //cout<<"*sp1="<<*sp1<<endl;

    shared_ptr<int> p;
    cout<<*p<<endl;
}