#include<iostream>
using namespace std;
int v;
int a=0;
void dfs(int G[20][20], int ar[], int done[20][20], int st)
{   
    ar[a++]=st;
    for(int i=1;i<=v;i++){
        if(G[st][i]==1 && done[st][i]!=1){
            done[st][i]=done[i][st]=1;
            dfs(G, ar, done, i);
        }
    }
}

int main()
{
    int G[20][20],x ,y, done[20][20];
    cout<<"Enter the number of nodes:";
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
    dfs(G, ar, done, 1);
    cout<<"\nThe cycle is: ";
    for(int i=0;i<a;i++) cout<<ar[i]<<" ";
    return 0;

}
