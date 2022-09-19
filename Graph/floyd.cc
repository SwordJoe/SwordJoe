#include<iostream>
#include<vector>
using namespace std;
/**
 * @brief floyd思想：
 * 三次for循环，每次选取一个点k，以k点为中间节点，如果dist[u][k]+dist[k][v]<dist[u][v]
 * 则用dist[u][k]+dist[k][v]更新dist[u][v]的距离
 */

int N;  //顶点个数
int M;  //边数
vector<vector<int>> dist;

void floyd(){
    for(int k=0;k<N;++k){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(dist[i][k]!=INT32_MAX && dist[k][j]!=INT32_MAX && dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

int main()
{
    cin>>N>>M;
    dist.resize(N,vector<int>(N,INT32_MAX));
    for(int i=0;i<N;++i){
        dist[i][i]=0;
    }
    int u,v,w;
    for(int i=0;i<M;++i){   //输入顶点之间的距离
        cin>>u>>v>>w;
        dist[u][v]=w;       
    }

    floyd();
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(dist[i][j]==INT32_MAX){
                cout<<"# ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}