#include<vector>
using namespace std;


void insertSort(vector<int> &vec){
    for(int i=1; i<arr.size(); ++i){
        int j = i-1;
        int tmp = arr[i];
        while(j>=0 && arr[j]>tmp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[++j] = tmp;
    }
}