#include<iostream>
using namespace std;
int v;

void dfs(int G[20][20], int ar[], int cur, int n)
{
    if(n==5){
        if(cur==3){
            for(int i=0;i<5;i++) cout<<ar[i]<<" ";
            cout<<"\n";
        }
        else return;
    }
    for(int i=1;i<=v;i++){
        if(G[cur][i]==1){
            ar[n++]=i;
            dfs(G, ar, i, n);
            n--;
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
    int ar[20];
    cout<<"Enter the starting vertex: ";
    cin>>ar[0];
    dfs(G,ar,ar[0], 1);
    return 0;

}


/*
Input
9
9
1
1
2
2
3
9
6
6
5
5
8
7
1
1
6
1
5
5
2
5
3
3
8
*/
