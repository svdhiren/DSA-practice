#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int v;

struct heap{
int v1;
int v2;
int w;
};

void perup(heap H[], heap ele, int &n)
{
    H[n]=ele;
    int i=n;
    while(H[i].w > H[(i-1)/2].w  && i>0){
		heap tmp = H[i];
		H[i]=H[(i-1)/2];
		H[(i-1)/2]=tmp;
		i=(i-1)/2;
	}
	n++;
}

heap perdown(heap H[], int &s)
{
    heap res=H[0];
    H[0]=H[--s];
    int i=0;
    while(2*i+1 < s){
		if(2*i+2 < s)
		{
			if(H[i].w < H[2*i+1].w || H[i].w < H[2*i+2].w){
				if(H[2*i+1].w > H[2*i+2].w)
				{
					heap tmp = H[2*i+1];
					    H[2*i+1] = H[i];
					    H[i]=tmp;
					    i = 2*i+1;
				}
				else
				{
					heap tmp = H[2*i+2];
					    H[2*i+2] = H[i];
					    H[i]=tmp;
					    i = 2*i+2;
				}
			}
			else break;
		}
		else{
			if(H[i].w < H[2*i+1].w)
			{
				heap tmp = H[2*i+1];
					H[2*i+1] = H[i];
					H[i]=tmp;
					i = 2*i+1;
			}
			else break;
		}
	}
	return res;
}

bool isconnected(int G[20][20])
{
    int vis[20], n=0, s;
    for(int i=1;i<=v;i++) vis[i]=0;
    queue<int> q;
    vis[1]=1;
    q.push(1);
    while(!q.empty()){
        s=q.front(); q.pop();
        n++;
        for(int i=1;i<=v;i++){
            if(G[s][i]!=0 && vis[i]!=1){
                vis[i]=1;
                q.push(i);
            }
        }
    }
    if(n==v) return true;
    return false;
}

void MST(int G[20][20], heap H[], int &n)
{
    if(n==0) return;
    heap tmp;
      tmp = perdown(H, n);
      G[tmp.v1][tmp.v2]=G[tmp.v2][tmp.v1]=0;
      if(!isconnected(G))
        G[tmp.v1][tmp.v2]=G[tmp.v2][tmp.v1]=tmp.w;
    MST(G, H, n);
}

int main()
{
    int G[20][20], x ,y, d;
    heap H[20];
    int n=0;
    for(int i=0;i<20;i++){
        H[i].v1=0;
        H[i].v2=0;
        H[i].w=100;
    }
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
      cout<<"Enter the weight of the edge: ";
      cin>>d;
      G[x][y]=G[y][x]=d;
      heap h;
      h.v1=x;
      h.v2=y;
      h.w=d;
      perup(H, h, n);
      cout<<"\n";
    }

    MST(G, H, n);
   cout<<"The minimum spanning tree is: \n";
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

}

/*
8
1
2
9
2
7
5
7
8
4
8
5
4
5
4
1
4
3
3
3
1
4
1
6
2
3
6
5
6
4
2
2
5
1
*/

