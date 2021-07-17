#include<iostream>
using namespace std;
int v;

void k_dis(int G[20][20], int vis[], int done[20][20], int a, int cur, int k, int d)
{
	for(int i=1;i<=v;i++){
        if(G[cur][i]==1 && vis[i]!=1){
            vis[i]=1;
            if(d==k && done[a][i]!=1){
                done[a][i]=done[i][a]=1;
                cout<<a<<" , "<<i<<"\n";
            }
            else
                k_dis(G, vis, done, a, i, k, d+1);
        }
    }
}

int main()
{
    int G[20][20], done[20][20], x, y, k;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
           {
               G[i][j]=0;
               done[i][j]=0;
           }
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
    cout<<"Enter k: ";
    cin>>k;
    cout<<"The different pairs are:\n";
    int vis[20];
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++) vis[j]=0;
        vis[i]=1;
        k_dis(G, vis, done, i, i, k, 1);
    }
     return 0;
}
