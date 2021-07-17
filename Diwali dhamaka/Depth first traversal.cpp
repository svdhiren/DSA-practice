#include<iostream>
using namespace std;
int v;

void dfs(int G[20][20], int ar[], int vis[], int st)
{   static int a=1;
    for(int i=1;i<=v;i++){
        if(G[st][i]==1 && vis[i]!=1){
            vis[i]=1;
            ar[a++]=i;
            dfs(G, ar, vis, i);
        }
    }
}

int main()
{
    int G[20][20],x ,y;
    cout<<"Enter the number of nodes:";
    cin>>v;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
           G[i][j]=0;
    cout<<"Start entering the edges...\n";
    while(1){
      cout<<"Enter x : ";
      cin>>x;
      if(x==-1) break;
      cout<<"Enter y : ";
      cin>>y;
      G[x][y]=1;
      cout<<"\n";
    }

    for(int i=1;i<=v;i++) cout<<"\t"<<i;
    cout<<"\n";
    for(int i=1;i<=v;i++){
        cout<<i<<"\t";
        for(int j=1;j<=v;j++)
            if(G[i][j]!=0)
              cout<<G[i][j]<<"\t";
            else cout<<"\t";
        cout<<"\n";
    }
    int vis[20], ar[20];
    for(int i=1;i<=v;i++) vis[i]=0;
    cout<<"Enter the starting vertex: ";
    cin>>ar[0];
    vis[ar[0]]=1;
    dfs(G, ar, vis, ar[0]);
    cout<<"\nThe dfs is: ";
    for(int i=0;i<v;i++) cout<<ar[i]<<" ";
    return 0;

}
