#include<vector>
#include<iostream>
using namespace std;

void shellSort(vector<int> &vec){
    int n = vec.size();
    for(int gap=n/2; gap>=1; gap/=2){
        cout<<"gap="<<gap<<endl;
        for(int i=gap; i<n; ++i){
            int tmp = vec[i];
            int j = i-gap;
            while(j>=0 && vec[j]>tmp){
                vec[j+gap] = vec[j];
                j-=gap;
            }
            vec[j+gap] = tmp;
        }
    }
}