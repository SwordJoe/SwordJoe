#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

void selectSort(vector<int> &);
void insertSort(vector<int> &);
void bubbleSort(vector<int> &);

int main()
{
    srand(time(nullptr));
    vector<int> vec;

    for(int i=0; i<10; ++i){
        vec[i] = rand() % 100;
    }
    
    //insertSort(vec);
    selectSort(vec);
    for(auto num : vec){
        cout<<num<<" ";
    }
    cout<<endl;
}