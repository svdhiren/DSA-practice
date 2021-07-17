#include<iostream>
using namespace std;
int v;

void calculate(int G[20][20], int at[], int dt[], int vis[], int cur){
	static int n=0;
	at[cur]=n++;
	for(int i=1;i<=v;i++){
		if(G[cur][i]==1 && vis[i]!=1){
			vis[i]=1;
			calculate(G, at, dt, vis, i);
		}
	}
	dt[cur]=n++;
}

int main(){
	int G[20][20],x ,y, at[20], dt[20], vis[20];
    cout<<"Enter the number of nodes:";
    cin>>v;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
           G[i][j]=0;
    for(int i=1;i<=v;i++){
    	at[i]=dt[i]=vis[i]=0;
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
    int a, fl;
    for(a=1;a<=v;a++){
    	fl=1;
    	for(int i=1;i<=v;i++)
    	   if(G[i][a]==1){
    	   	fl=0;
    	   	break;
		   }
		if(fl){
			calculate(G, at, dt, vis, a);
		}   
	}
	cout<<"The departure times are: ";
	for(int i=1;i<=v;i++) cout<<dt[i]<<" ";
}
