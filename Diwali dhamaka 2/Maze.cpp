#include<iostream>
using namespace std;
int v;
int calc(int G[20][20], int a){
   int d=0;
   for(int i=1;i<=v;i++)
       if(G[a][i]==1) d++;
   return d;

}

void mazepath(int G[20][20], int done[20][20], int deg[], int cur, int des, int ar[], int n)
{   static int fl=1;
    if(cur==des){
        cout<<"The path is: ";
        for(int i=0;i<n;i++) cout<<ar[i]<<" ";
        fl=0;
        return;
    }
    if(deg[cur]==0){
        return;
    }
    for(int i=1;i<=v && fl==1;i++){
        if(G[cur][i]==1 && done[cur][i]!=1){
           done[cur][i]=done[i][cur]=1;
           deg[cur]--;
           deg[i]--;
           ar[n++]=i;
           mazepath(G, done, deg, i, des, ar, n);
           done[cur][i]=done[i][cur]=0;
           deg[cur]++;
           deg[i]++;
           n--;
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

    int deg[20];
    for(int i=1;i<=v;i++) deg[i]=0;
    for(int i=1;i<=v;i++){
    	deg[i]=calc(G, i);
	}
	int st, des, ar[20];
	cout<<"Enter the starting vertex: ";
	cin>>st;
	cout<<"Enter the destination vertex: ";
	cin>>des;
	ar[0]=st;
	mazepath(G, done, deg, st, des, ar, 1);
    return 0;

}

