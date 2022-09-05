#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<pthread.h>
using  namespace std;

unsigned long long a=0;
void addOne(){
    static mutex mtx;
    unique_lock<mutex> lock(mtx);

    for(int i=0; i<10000000000; ++i){
        a++;
    }

    lock.unlock();
    cout<<"线程"<<pthread_self()<<"解锁一次"<<endl;
    //cout<<"此时a="<<a<<endl;
    lock.lock();
    for(int i=0; i<10000000000; ++i){
        a++;
    }
}


int main()
{
    thread t1(addOne), t2(addOne);
    t1.join();
    t2.join();
    cout<<endl<<endl;
    cout<<"a="<<a<<endl;
}
