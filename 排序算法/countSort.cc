#include<vector>
#include<map>
using namespace std;

void countSort(vector<int> &vec){
    map<int,int> M;
    for(auto num : vec){
        auto iter = M.find(num);
        if(iter == M.end()){
            M[num] = 1;
        }
        else{
            M[num]++;
        }
    }
    int idx = 0;
    for(auto pair : M){
        while(pair.second > 0){
            vec[idx++] = pair.first;
            pair.second--;
        }
    }
}