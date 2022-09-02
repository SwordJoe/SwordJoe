#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/**
 * @brief dijkstra思想：
 * 1、从起点s开始，每次选取一个最短距离的顶点u，记录u点已访问过
 * 2、以u点为中介，更新所有与u点相连的顶点的最短距离
 * 3、继续选取下一个最短距离的顶点u,重复以上两步
 */

int N;  //顶点个数
int M;  //边数
int S;  //起点编号
vector<vector<int>> grid;   //邻接矩阵
vector<bool> visit;
vector<int> dist;
vector<int> pre;

void dijkstra(int s){
    for(int i=0;i<N;++i){
        int u=-1;
        int Min=INT32_MAX;
        for(int i=0;i<N;++i){       //从当前未被访问的顶点中寻找一个dist最小的顶点u
            if(visit[i]==false && dist[i]<Min){
                u=i;
                Min=dist[i];
            }
        }
        visit[u]=true;

        for(int v=0;v<N;++v){       //以顶点u为中介，更新其他节点的距离
            if(visit[v]==false && grid[u][v]!=INT32_MAX && dist[u]+grid[u][v]<dist[v]){
                dist[v]=dist[u]+grid[u][v];
                pre[v]=u;
            }
        }
    }
}

int main()
{
    int u,v,w;
    cin>>N>>M>>S;       //输入顶点个数、边数、起点编号
    grid.resize(N,vector<int>(N,INT32_MAX));
    visit.resize(N,false);
    dist.resize(N,INT32_MAX);
    pre.resize(N);
    dist[S]=0;

    for(int i=0;i<N;++i){
        pre[i]=i;
    }

    for(int i=0;i<M;++i){
        cin>>u>>v>>w;
        grid[u][v]=w;
    }
    dijkstra(S);
    for(int i=0;i<N;++i){
        cout<<"到达"<<i<<"的最短路径:"<<dist[i]<<" 路径为：";
        stack<int> st;
        int v=i;
        while(pre[v]!=v){
            st.push(pre[v]);
            v=pre[v];
        }
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<i<<endl;
    }

    cout<<endl;
}


