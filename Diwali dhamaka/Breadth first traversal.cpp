#include<iostream>
#include<queue>
using namespace std;
int v;

void bfs(int G[20][20], queue<int> q, int vis[])
{
    if(q.empty()) return;
    int s=q.front(); q.pop();
    cout<<s<<" ";
    for(int i=1;i<=v;i++)
       if(G[s][i]==1 && vis[i]!=1){
        vis[i]=1;
        q.push(i);
       }
    bfs(G, q, vis);
}

int main()
{
    int G[20][20], x, y, s;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
               G[i][j]=0;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    //This is for an undirected unweighted graph.
    cout<<"Start entering the edges...\n";
    while(1){
      cout<<"Enter x : ";
      cin>>x;
      if(x==-1) break;
      cout<<"Enter y : ";
      cin>>y;
      G[x][y]=G[y][x]=1;
      cout<<"\n";
    }
    int vis[20];
    for(int i=1;i<=v;i++)
        vis[i]=0;
    cout<<"Enter the starting vertex: ";
    cin>>s;
    vis[s]=1;
    queue<int> q;
    q.push(s);
    bfs(G, q, vis);
    return 0;
}
