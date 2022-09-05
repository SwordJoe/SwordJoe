#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<unistd.h>
using  namespace std;

mutex mtx;
condition_variable cv;
char flag='A';

void printA(){
    unique_lock<mutex> lock(mtx);
    while(1){
        while( flag != 'A'){
            cv.wait(lock);
        }
        cout<<this_thread::get_id()<<": A"<<endl;
        flag = 'B';
        cv.notify_one();
        sleep(1);
    }
}

void printB(){
    unique_lock<mutex> lock(mtx);
    while(1){
        while(flag != 'B'){
            cv.wait(lock);
        }
        cout<<this_thread::get_id()<<": B"<<endl;
        flag = 'A';
        cv.notify_one();
        sleep(1);
    }
}

int main()
{
    thread th1(printA);
    thread th2(printB);

    th1.join();
    th2.join();
}