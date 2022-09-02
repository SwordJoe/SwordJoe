#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

void selectSort(vector<int> &arr){
    for(int i=0; i<arr.size()-1; ++i){
        int minIdx = i;
        for(int j=i+1; j<arr.size();++j){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
    }
}