#include<vector>
#include<cmath>
using namespace std;

void adjustHeap(vector<int> &vec, int low, int high){
    int i = low;
    int j = 2*i+1;

    while(j <= high){
        if(j<high && vec[j]<vec[j+1]){
            j++;
        }
        if(vec[i] < vec[j]){
            swap(vec[i], vec[j]);
            i = j;
            j = 2*i +1;
        }
        else{
            break;
        }
    }
}

void heapSort(vector<int> &vec){
    int n = vec.size();
    int lastFatherIdx = n/2 - 1;
    for(int i=lastFatherIdx; i>=0; --i){
        adjustHeap(vec, i, n-1);
    }

    for(int i=n-1; i>0; --i){
        swap(vec[0],vec[i]);
        adjustHeap(vec, 0, i-1);
    }
}