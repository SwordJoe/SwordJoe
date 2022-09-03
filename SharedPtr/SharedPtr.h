#pragma once
#include<iostream>
using namespace std;

template<class T>
class SharedPtr
{
public:
    SharedPtr():_ptr(nullptr),_pcnt(nullptr){ cout<<"SharedPtr()"<<endl;}
    SharedPtr(T* ptr):_ptr(ptr),_pcnt(new int(1)){cout<<"SharedPtr(const T*)"<<endl;}
    SharedPtr(const SharedPtr &);                //拷贝构造函数
    SharedPtr& operator= (const SharedPtr &);    //复制运算符函数
    SharedPtr(SharedPtr &&);                    //移动构造函数
    SharedPtr& operator= (SharedPtr &&);        //移动赋值运算符函数
    ~SharedPtr();
    
    T& operator*(){ 
        if(_ptr){
            cout<<"不空"<<endl;
            return *_ptr;
        }
    }

    int useCnt() const { return _pcnt ? *_pcnt : 0; }

private:
    T *_ptr;
    int *_pcnt;
};

template<class T>   //拷贝构造函数
SharedPtr<T>::SharedPtr(const SharedPtr &rhs)
:_ptr(rhs._ptr),_pcnt(rhs._pcnt)
{
    ++(*_pcnt);
    cout<<"SharedPtr(const SharedPtr&)"<<endl;
}

template<class T>   //赋值运算符函数
SharedPtr<T>& SharedPtr<T>::operator= (const SharedPtr &rhs){
    cout<<"Shared& operator= (const SharedPtr&)"<<endl;
    if(this == &rhs){
        return *this;
    }
    if(_pcnt != nullptr){
        --(*_pcnt);
        if(*_pcnt == 0){
            delete _ptr;    _ptr = nullptr;
            delete _pcnt;   _pcnt = nullptr;
        }
    }

    _ptr = rhs._ptr;
    _pcnt = rhs._pcnt;
    ++(*_pcnt);
    return *this;
}

template<class T>   //移动构造函数
SharedPtr<T>::SharedPtr(SharedPtr &&rhs)
:_ptr(rhs._ptr),_pcnt(rhs._pcnt)
{
    cout<<"SharedPtr(SharedPtr &&)"<<endl;
    if(rhs._ptr){
        rhs._ptr = nullptr;
        --(*(rhs._pcnt));           //tips:这里不需要判断引用计数是否为0，因为这是移动构造函数，即使为0的话，接管该指针的另一个智能指针也会需要引用计数+1
        rhs._pcnt = nullptr;
    }
    if(_ptr){
        ++(*_pcnt);
    }
}

template<class T>   //移动赋值运算符
SharedPtr<T>& SharedPtr<T>::operator= (SharedPtr &&rhs){
    cout<<"SharedPtr(SharedPtr&&)"<<endl;
    if(_ptr){
        --(*_pcnt);
        if(*_pcnt == 0){
            delete _ptr;
            delete _pcnt; 
        }
        _ptr = nullptr;
        _pcnt = nullptr;
    }

    _ptr = rhs._ptr;    rhs._ptr = nullptr;
    _pcnt = rhs._pcnt;  rhs._pcnt = nullptr;
    return *this;
}

template<class T>
SharedPtr<T>::~SharedPtr(){
    cout<<"~SharedPtr()"<<endl;
    if(_ptr){
        --(*_pcnt);
        if(*_pcnt == 0){
            delete _ptr; _ptr = nullptr;
            delete _pcnt; _pcnt = nullptr;
        }
    }
}


