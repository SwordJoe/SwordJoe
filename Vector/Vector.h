#pragma once
#include<memory>
#include<iostream>
using namespace std;

template<class T>
class Vector
{
public:
    Vector();
    ~Vector();

    void push_back(const T &);
    void pop_back();
    int size(){ return _end - _start;}
    int capacity(){ return _end_of_storage - _start;}
    
    T* begin(){ return _start;};
    T* end(){ return _end;}
    T& operator[] (int idx);

private:
    void reallocate();      

private:
    static allocator<T> _alloc;
  
    T *_start;
    T *_end;
    T *_end_of_storage;
};

template<class T>
allocator<T> Vector<T>::_alloc;

template<class T>
Vector<T>::Vector()
:_start(nullptr),_end(nullptr),_end_of_storage(nullptr)
{
    cout<<"Vector()"<<endl;
}

template<class T>
Vector<T>::~Vector(){
    cout<<"~Vector()"<<endl;
    if(_start){
        auto p = _end;
        while(p != _start){
            _alloc.destroy(--p);        //先析构对象
        }
        _alloc.deallocate(_start, capacity());      //再回收取内存
    }
}

template<class T>
void Vector<T>::push_back(const T &val){
    if(_end == _end_of_storage){
        reallocate();
    }
    _alloc.construct(_end++, val);
}

template<class T>
void Vector<T>::pop_back(){
    if(_start != _end){
        _alloc.destroy(--_end);
    }
}

template<class T>
void Vector<T>::reallocate(){
    int newCapacity = _start==_end_of_storage ? 1 : 2*capacity();
    cout<<"扩容一次,newCapacity="<<newCapacity<<endl;

    auto newAddr = _alloc.allocate(newCapacity);

    auto newPtr = newAddr;
    auto oldPtr = _start;

    while(oldPtr != _end){
        _alloc.construct(newPtr, std::move(*oldPtr));
        newPtr++;
        oldPtr++;
    }

    auto p = _end;
    while(p != _start){
        _alloc.destroy(--p);
    }
    _alloc.deallocate(_start,capacity());

    _start = newAddr;
    _end = newPtr;
    _end_of_storage = _start + newCapacity;
    cout<<"size()="<<size()<<endl;
    cout<<"capacity()="<<capacity()<<endl<<endl;
}

template<class T>
T& Vector<T>::operator[](int idx){
    if(idx >= size()){
        cout<<"越界"<<endl;
        T tmp;
        return tmp;
    }
    return *(_start+idx);
}

