#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<unistd.h>
using namespace std;

mutex mtx;
condition_variable cv;
int idx=1;

void printA(){
    unique_lock<mutex> lock(mtx);
    while(1){
        //lock.lock();
        while(idx !=1){
            cv.wait(lock);
        }
        cout<<this_thread::get_id()<<": "<<"A"<<endl;
        idx = 2;
        //lock.unlock();
        cv.notify_all();
    }

}

void printB(){
    unique_lock<mutex> lock(mtx);
    while(1){
        //lock.lock();
        while(idx != 2){
            cv.wait(lock);
        }
        cout<<this_thread::get_id()<<": "<<"B"<<endl;
        idx = 3;
        //lock.unlock();
        cv.notify_all();
        sleep(2);
    }
}

void printC(){
    unique_lock<mutex> lock(mtx);
    while(1){
        //lock.lock();
        while(idx != 3){
            cv.wait(lock);
        }
        cout<<this_thread::get_id()<<": "<<"C"<<endl;
        idx = 1;
        //lock.unlock();  //解锁
        cv.notify_all();    //通知所有线程
        sleep(1);
    }
}

int main()
{
    thread th1(printA);
    thread th2(printB);
    thread th3(printC);

    th1.join();
    th2.join();
    th3.join();
}