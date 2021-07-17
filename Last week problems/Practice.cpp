#include<iostream>
using namespace std;
int v, fl=0;

 void checkcycle(int G[20][20], int vis[], int cur)
 {
     for(int i=1;i<=v && !fl;i++)
     {
         if(G[cur][i]>0)
         {
             if(vis[i]==1)
             {
                 cout<<"Cycle exists!";
                 fl=1;
             }
             else
             {
                 vis[i]=1;
                 G[cur][i]=G[i][cur]=-1;
                 checkcycle(G, vis, i);
             }

         }
     }
 }

int main()
{
    int G[20][20], vis[20], x, y;
    cout<<"Enter the number of nodes: ";
    cin>>v;
    for(int i=0;i<=v;i++)
    {
        for(int j=0;j<=v;j++)
            G[i][j]=0;
        vis[i]=0;
    }

    cout<<"Start entering the edges: \n";
    while(1)
    {
        cout<<"Enter x: ";
        cin>>x;
        if(x==-1) break;
        cout<<"Enter y: ";
        cin>>y;
        G[x][y]=G[y][x]=1;
        cout<<"\n";
    }

    cout<<"\n";
    for(int i=1;i<=v;i++) cout<<"\t"<<i;
    cout<<"\n";
    for(int i=1;i<=v;i++){
        cout<<i<<"\t";
        for(int j=1;j<=v;j++)
            if(G[i][j]>=1)
              cout<<G[i][j]<<"\t";
            else cout<<"\t";
        cout<<"\n";
    }
    vis[1]=1;
    checkcycle(G, vis, 1);
    if(fl==0)
        cout<<"\nA cycle doesn't exist...";
    return 0;
}

// Input 1: 4 1 2 2 3 1 4 2 4 -1
// Input 2:
