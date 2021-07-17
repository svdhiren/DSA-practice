#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int v;

void binaryBFS(int G[20][20], int d[], int st, int X)
{
    int cur;
    deque<int> q;
    q.push_back(st);
    while(q.size()!=0)
    {
        cur=q.front(); q.pop_front();
        for(int i=1;i<=v;i++){
            if(G[cur][i]!=0 && i!=st){
                if(d[cur]+G[cur][i] < d[i]){
                    d[i]=d[cur]+G[cur][i];

                    if(G[cur][i]==X)
                        q.push_front(i);
                    else
                        q.push_back(i);

                }
            }
        }
    }

}

int main()
{
    int G[20][20],x ,y, X, Y, dis;
    cout<<"Enter the number of nodes:";
    cin>>v;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
           	G[i][j]=0;
	cout<<"Enter weight 1(smaller): ";
	cin>>X;
	cout<<"Enter weight 2: ";
	cin>>Y;
    cout<<"Enter the edges whose weight is "<<X<<"...\n";
    while(1){
      cout<<"Enter x : ";
      cin>>x;
      if(x==-1) break;
      cout<<"Enter y : ";
      cin>>y;
      G[x][y]=G[y][x]=X;
      cout<<"\n";
    }

    cout<<"Enter the edges whose weight is "<<Y<<"...\n";
    while(1){
      cout<<"Enter x : ";
      cin>>x;
      if(x==-1) break;
      cout<<"Enter y : ";
      cin>>y;
      G[x][y]=G[y][x]=Y;
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

    int d[20], st;
    for(int i=1;i<=v;i++) d[i]=100;
    cout<<"Enter the starting vertex: ";
	cin>>st;
	d[st]=0;
	binaryBFS(G, d, st, X);
	cout<<"The distances are: ";
	for(int i=1;i<=v;i++) cout<<d[i]<<" ";

    return 0;

}


