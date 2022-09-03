#include"Vector.h"
#include<iostream>
using namespace std;

int main()
{
    Vector<int> vec;
    cout<<"vec.size()="<<vec.size()<<endl;
    cout<<"vec.capacity()="<<vec.capacity()<<endl;

    for(int i=0; i<10; ++i){
        vec.push_back(i+1);
    }

    cout<<"vec.size()="<<vec.size()<<endl;
    cout<<"vec.capacity()="<<vec.capacity()<<endl;
    cout<<vec[10]<<endl;
}