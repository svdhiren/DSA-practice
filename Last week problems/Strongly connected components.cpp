#include<bits/stdc++.h>
using namespace std;
int v;
stack<int> s;

void calculate(int G[20][20], int vis[], int cur){

	for(int i=1;i<=v;i++){
		if(G[cur][i]==1 && vis[i]!=1){
			vis[i]=1;
			calculate(G, vis, i);
		}
	}
    s.push(cur);
}

void dfs(int G[20][20], int vis[], int cur, int res[], int &n)
{
    for(int i=1;i<=v;i++)
    if(G[cur][i]>=1 && vis[i]!=1){
        vis[i]=1;
        vis[0]++;
        res[n++]=i;
        dfs(G, vis, i, res, n);
    }
}

void revert(int G[20][20])
{
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
          if(G[i][j]==1)
    {
        G[i][j]=-1;
        G[j][i]=2;
    }
}

void print(int G[20][20])
{
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
}

int main()
{
    int G[20][20], vis[20], res[20], x , y;
    cout<<"Enter the number of nodes:";
    cin>>v;
    for(int i=0;i<=v;i++)
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
      G[x][y]=1;
      cout<<"\n";
    }

   print(G);
   for(int i=1;i<=v;i++){
    if(vis[i]!=1)
        calculate(G, vis, i);
   }
   revert(G);
   print(G);
   for(int i=0;i<=v;i++)  vis[i]=0;
   int n;
   cout<<"\nThe connected components are: \n";
   while(vis[0]!=v){
    int cur = s.top(); s.pop();
    if(vis[cur]!=1)
    {
    n=0;
    vis[cur]=1;
    vis[0]++;
    res[n++]= cur;
    dfs(G, vis, cur, res, n);
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
    cout<<"\n";
    }
   }

}

/*
Input: 10 1 2 2 3 3 4 4 5 3 5 2 6 6 3 1 4 7 6 7 8 8 6 8 10 10 9 9 8 3 1 -1
*/

