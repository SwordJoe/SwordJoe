#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<queue>
#include<ctime>
#include<chrono>
#include<unistd.h>
using namespace std;
using namespace std::chrono;

#define FULL  10

queue<int> que;
mutex mtx;
condition_variable notEmpty;
condition_variable notFull;

void produce(){
    srand(time(nullptr));
    while(1){
        unique_lock<mutex> lock(mtx);
        //while(que.size() == FULL){
        //     cout<<"进来了"<<endl;
        //     notFull.wait(lock);
        // }
        /**
         * @brief 下面的wait()调用等价于上面的while(){}
         * 调用条件变量的wait()之后，线程会进行如下步骤：
         * step1: 立即解锁，并且阻塞到本行
         * step2: 等待其他线程用相同条件变量进行notify_one()唤醒自己
         * step3: 如果wait没有第二个参数(即lambada表达式), wait直接返回，上锁继续执行后面的流程
         *          如果wait有第二个lambada参数，wait返回之后会判断lambada表达式是否为true，如果为真则同上(上锁继续执行后续流程)；如果lambada返回false，则继续解锁等待被唤醒
         */  
        notFull.wait(lock, [](){return que.size() < FULL;});
        int num = rand()%100;
        que.push(num);
        cout<<"生产者生产一个产品："<<num<<endl;
        notEmpty.notify_one();      //通知消费者不空
        lock.unlock();
        sleep(1);
    }
}

void consume(){
    while(1){
        unique_lock<mutex> lock(mtx);
        //while(que.empty()){
        //     notEmpty.wait(lock);
        // }
        notEmpty.wait(lock, [](){ return que.size() > 0;});
        int num=que.front();
        que.pop();
        cout<<"=====消费者消费一个产品:"<<num<<endl;
        notFull.notify_one();   //通知生产者不满
        lock.unlock();
        //sleep(1);
    }
}

int main()
{
    thread Consumer(consume);
    thread Producer(produce);

    Producer.join();
    Consumer.join();
    
}