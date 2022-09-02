#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;

void selectSort(vector<int> &);
void insertSort(vector<int> &);
void bubbleSort(vector<int> &);
void heapSort(vector<int> &);
void quickSort(vector<int> &, int left, int right);
void mergeSort(vector<int> &vec, int left, int right);
void shellSort(vector<int> &vec);
void countSort(vector<int> &vec);

int main()
{
    srand(time(nullptr));
    vector<int> vec(20);

    for(int i=0; i<20; ++i){
        vec[i] = rand() % 100;
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    //insertSort(vec);
    //selectSort(vec);
    //bubbleSort(vec);
    //heapSort(vec);
    //quickSort(vec, 0, vec.size()-1);
    //mergeSort(vec,0,vec.size()-1);
    //shellSort(vec);
    countSort(vec);
    for(auto num : vec){
        cout<<num<<" ";
    }
    cout<<endl;
}
