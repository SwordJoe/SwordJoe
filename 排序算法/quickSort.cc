#include<vector>
#include<cmath>
using namespace std;

void quickSort(vector<int> &vec, int left, int right){
    if(left >= right){
        return;
    }
    int i = left;
    int j = right;
    int tmp = vec[left];
    while(i < j){
        while(i<j && vec[j] >= tmp) j--;
        if(i < j){
            vec[i] = vec[j];
            i++;
        }

        while(i<j && vec[i] <= tmp) i++;
        if(i < j){
            vec[j] = vec[i];
            j--;
        }
    }
    vec[j] = tmp;
    quickSort(vec, left, j-1);
    quickSort(vec, j+1, right);
}