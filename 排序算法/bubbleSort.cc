#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void bubbleSort(vector<int> &vec){
    for(int i=vec.size()-1; i>=1; i--){
        for(int j=1; j<=i; ++j){
            if(vec[j-1]>vec[j]){
                swap(vec[j-1],vec[j]);
            }
        }
    }
}