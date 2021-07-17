#include<iostream>
using namespace std;
int v;


void calculate(int G[20][20], int num[], int low[], int vis[], int cur, int p){
	static int n=1;

	//Assigning the arrival time and checking for a back edge if any and updating.
	num[cur]=n;
	low[cur]=n++;
	for(int i=1;i<=v;i++){
        if(G[cur][i]==1 && i!=p && vis[i]==1 && num[i]<low[cur])
           low[cur]=num[i];
	}

	// Loop for depth first traversal
	for(int i=1;i<=v;i++){
        if(G[cur][i]==1 && vis[i]!=1)
        {
            vis[i]=1;
            calculate(G, num, low, vis, i, cur);
        }
	}

	//When the function returns; checking whether the "low" of the parent can be changed.
	if(low[cur] < low[p] && p!=0)
        low[p]=low[cur];
    if(low[cur] >= num[p] && p!=0 && p!=1)
         cout<<p<<" ";
    //Incrementing the departure time;
    n++;

}


void print(int G[20][20])
{
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
}

void print_num(int G[20][20], int num[], int low[])
{
    cout<<"\n\n";
    cout<<"\tNum\tLow"<<"\n";
    for(int i=1;i<=v;i++){
        cout<<i<<"\t";
        cout<<num[i]<<"\t"<<low[i];
        cout<<"\n";
    }
}

int main()
{
    int G[20][20], vis[20], num[20], low[20], x , y;
    cout<<"Enter the number of nodes:";
    cin>>v;
    for(int i=0;i<=v;i++)
    {
         for(int j=0;j<=v;j++)
           G[i][j]=0;
        num[i]=0;
        vis[i]=0;
        low[i]=0;

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

   print(G);
   vis[1]=1;
   calculate(G, num, low, vis, 1, 0);
   //print_num(G, num, low);

}

/*
Input: 7 1 2 2 3 3 7 3 4 4 5 5 6 6 4 4 1 -1
*/

