#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

int a;
void addOne(){
    //注意这里一定要是static变量或全局变量
    //如果是函数内的局部变量的话，一个线程拿着一个mutex，起不到互斥的作用
    static mutex mtx;       
    lock_guard<mutex> lock(mtx);
    for(int i=0; i<2000000;++i){
        ++a;
    }
}

int main()
{
    thread t1(addOne), t2(addOne);
    t1.join();
    t2.join();    
    cout<<"a="<<a<<endl;
}
