#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;

void merge(vector<int>&,int,int,int);
void mergeSort(vector<int> &vec, int left, int right){
    if(left >= right){
        return;
    }
    int mid = (left+right)/2;
    mergeSort(vec, left, mid);
    mergeSort(vec, mid+1, right);
    merge(vec,left, mid, right);
}


void merge(vector<int> &vec, int left, int mid, int right){
    int i=left;
    int j=mid+1;
    int len = right-left+1;
    vector<int> tmp(len);
    int idx = 0;

    while(i<=mid && j<=right){
        if(vec[i] < vec[j]){
            tmp[idx++] = vec[i++];
        }
        else{
            tmp[idx++] = vec[j++];
        }
    }

    while(i <= mid){
        tmp[idx++] =  vec[i++];
    }
    while(j <= right){
        tmp[idx++]  = vec[j++];
    }

    copy(tmp.begin(), tmp.begin()+len, vec.begin()+left);
}