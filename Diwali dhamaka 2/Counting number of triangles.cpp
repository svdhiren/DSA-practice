#include<iostream>
using namespace std;
int v, ct=0;

void k_dis(int G[20][20], int done[20][20], int a, int cur, int d)
{
	for(int i=1;i<=v;i++){
        if(G[cur][i]==1 && done[cur][i]!=1){
            done[cur][i]=done[i][cur]=1;
            if(d==3){
                if(a==i)
                 {
                 	ct++;
                 	done[cur][i]=done[i][cur]=0;
                 	return;
				 }
            }
            else
                k_dis(G, done, a, i, d+1);
        }
    }
}

void makezero(int done[20][20]){
	for(int i=1;i<=v;i++)
           for(int j=1;j<=v;j++)
            done[i][j]=0;
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
    for(int a=1;a<=v;a++){
    	makezero(done);
        k_dis(G, done, a, a, 1);
    }
    cout<<"The number of triangles is: "<<ct/3;
     return 0;
}
