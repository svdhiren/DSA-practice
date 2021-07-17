#include<iostream>
#include<queue>
using namespace std;
int v;

void dj_bfs(int G[20][20], int pre[], int prev[], int d[], queue<int> q, int s){
	int yo;
	while(!q.empty()){
		yo=q.front(); q.pop();
		pre[yo]=0;
		for(int i=1;i<=v;i++){
			if(G[yo][i]!=0 && i!=s){
				
			      if(d[yo]+G[yo][i] < d[i]){
					d[i]=d[yo]+G[yo][i];
					prev[i]=yo;
					if(!pre[i]){
						q.push(i);
						pre[i]=1;
					}
					 
				}
			}
		}
	}
}

void path_print(int prev[], int cur, int s){
	if(cur==s){
		cout<<cur<<" ";
		return;
	}
	path_print(prev, prev[cur], s);
	cout<<cur<<" ";
}

int main()
{
	int G[20][20],x ,y, dis, s, des;
    cout<<"Enter the number of nodes:";
    cin>>v;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
           G[i][j]=0;
    //This is for an undirected weighted graph.       
    cout<<"Start entering the edges...\n";
    while(1){
      cout<<"Enter x : ";
      cin>>x;
      if(x==-1) break;
      cout<<"Enter y : ";
      cin>>y;
      cout<<"Enter the weight of the edge: ";
      cin>>dis;
      G[x][y]=G[y][x]=dis;
      cout<<"\n";
    }
    cout<<"Enter the source vertex: ";
    cin>>s;
    queue<int> q;
    q.push(s);
    int d[20], prev[20], pre[20];
    for(int i=1;i<=v;i++){
    	d[i]=100;
    	prev[i]=-1;
    	pre[i]=0;
	}
	d[s]=0;
	dj_bfs(G, pre, prev, d, q, s);
    cout<<"Enter the destination vertex: ";
    cin>>des;
    path_print(prev, des, s);
    return 0;
   
}
