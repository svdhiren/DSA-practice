#include<iostream>
using namespace std;
int v, ct=1;

bool allfill(int G[20][20]){
	for(int i=1;i<=v;i++)
	   for(int j=1;j<=v;j++){
	   	if(G[i][j]==0 && i!=j)
	   	    return false;
	   }
    return true;	   
}

void days(int G[20][20], int cur, int path[], int &n){
	
	path[n++]=cur;
	if(n==v+1){
		ct++;
		for(int a=0;a<n;a++) cout<<path[a]<<" ";
		cout<<"\n";
		if(allfill(G))
		   return;
		for(int a=1;a<=v;a++)
            for(int b=1;b<=v;b++){
            	if(G[a][b]==-1)
            	  G[a][b]=-2;
            	else if(G[a][b]==1)
				  G[a][b]=-1;  
			}  
		n=0;   
		days(G, 1, path, n);   
	}
	int i, j;
	for(i=1;i<=v;i++){
		if(G[cur][i]==-1){
			for(j=1;j<=v;j++)
			  if(G[i][j]==-1 && j!=cur)
			    break;
			    
			if(G[cur][j]==0){
				G[cur][j]=G[j][cur]=1;
				days(G, j, path, n);
			} 
			else continue;   
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
    for(int i=1;i<=v;i++){
    	if(i==v)
    	 G[v][1]=G[1][v]=-1;  
		else
		 G[i][i+1]=G[i+1][i]=-1;
	}
	int path[20], n=0;
	cout<<"The paths are as follows: ";
	for(int i=1;i<=v;i++) cout<<i<<" ";
	cout<<"\n";
	days(G, 1, path, n);
	cout<<"So the number of paths is: "<<ct;  
	     
}
