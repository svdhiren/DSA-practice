#include<iostream>
using namespace std;
int v;

void hamiltonian(int G[20][20], int cur, int vis[], int ar[], int n)
{
    if(n==v){
        for(int i=0;i<v;i++) cout<<ar[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=1;i<=v;i++){
        if(G[cur][i]==1 && vis[i]!=1){
            vis[i]=1;
            ar[n++]=i;
            hamiltonian(G, i, vis, ar, n);
            vis[i]=0;
            n--;
        }
    }
}

int main()
{
    int G[20][20],x ,y, vis[20], ar[20];
    cout<<"Enter the number of nodes:";
    cin>>v;
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
           	G[i][j]=0;
        vis[i]=0;
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
    for(int i=1;i<=v;i++){
        vis[i]=1;
        ar[0]=i;
        hamiltonian(G, i, vis, ar, 1);
        vis[i]=0;
    }
    return 0;

}

