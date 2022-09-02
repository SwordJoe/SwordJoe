#include<iostream>
#include<memory>
using namespace std;

class AbstractProduct
{
public:
    AbstractProduct(string name):_name(name){}
    virtual ~AbstractProduct() = default;

    virtual void printName() = 0;
    virtual void play() = 0;
private:
    string _name;
};

class BasketBall : public AbstractProduct
{
public:
    BasketBall(string name):AbstractProduct(name){}
    ~BasketBall() = default;
    void printName() override{
        cout<<"this is basketball"<<endl;
    }
    void play() override{
        cout<<"we are playing basketball"<<endl;
    }
};

class FootBall : public AbstractProduct
{
public:
    FootBall(string name):AbstractProduct(name){}
    ~FootBall() = default;
    void printName() override{
        cout<<"this is football"<<endl;
    }
    void play() override{
        cout<<"we are playing football"<<endl;
    }
};


class Factory
{
public:
    shared_ptr<AbstractProduct> getProduct(string name){
        shared_ptr<AbstractProduct> ptr;
        if(name == "BasketBall"){
            ptr = shared_ptr<AbstractProduct>(new BasketBall(name));
        }
        else if(name == "FootBall"){
            ptr = shared_ptr<AbstractProduct>(new FootBall(name));
        }

        return ptr;
    }
};
