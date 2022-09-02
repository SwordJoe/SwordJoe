#pragma once 
#include<iostream>
using namespace std;

template<class T>
class Sharedptr
{
public:
    Sharedptr():_ptr(nullptr),_pcnt(nullptr){}
    Sharedptr(T *ptr):_ptr(ptr),_pcnt(new int(1)){cout<<"Sharedptr(T*)"<<endl;}
    Sharedptr(const Sharedptr&);
    Sharedptr& operator= (const Sharedptr&);
    Sharedptr(Sharedptr &&);
    Sharedptr& operator=(Sharedptr &&);
    ~Sharedptr();

    int useCount(){
        return _pcnt? *_pcnt : 0;
    }
private:
    T *_ptr;
    int *_pcnt;
};


template<class T>
Sharedptr<T>::Sharedptr(const Sharedptr &rhs)
:_ptr(rhs._ptr),_pcnt(rhs._pcnt)
{
    ++*(_pcnt);
    cout<<"Sharedptr(const Sharedptr&)"<<endl;
}

template<class T>
Sharedptr<T>& Sharedptr<T>::operator=(const Sharedptr& rhs)
{
    cout<<"Sharedptr& operator=(const Sharedptr&)"<<endl;
    if(this == &rhs){
        return *this;
    }
    if(_pcnt){
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

template<class T>
Sharedptr<T>::Sharedptr(Sharedptr &&rhs)
:_ptr(rhs.ptr),_pcnt(rhs._pcnt)
{
    cout<<"Sharedptr(Sharedptr &&)"<<endl;
    rhs._ptr = nullptr;
    rhs._pcnt = nullptr;
}

template<class T>
Sharedptr<T>& operator= (Sharedptr &&rhs){
    if(_ptr){
        --(*_pcnt);
        if(*_pcnt == 0){
            delete _pcnt;
            delete _ptr;
        }
        _ptr = rhs._ptr;
        _pcnt = rhs._pcnt;
    }
    rhs._ptr = nullptr;
    rhs._pcnt = nullptr;
    return *this;
}

template<class T>
Sharedptr<T>::~Sharedptr(){
    cout<<"~Sharedptr()"<<endl;
    if(_ptr){
        --(*_pcnt);
        if(*_pcnt == 0){
            delete _ptr;    _ptr = nullptr;
            delete _pcnt;   _pcnt = nullptr;
        }
    }
}