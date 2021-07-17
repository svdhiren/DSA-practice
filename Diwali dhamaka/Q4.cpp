#include<iostream>
using namespace std;
int v;
struct info{
  int vis, d, pr;
};


void path(int G[20][20], info ver[], int vis[20][20], int cur, int des){

      if(cur==des){
        return;
      }
      for(int i=1;i<=v;i++){
        if(G[cur][i]!=0 && vis[cur][i]==0 && ver[i].vis!=1){

                if(ver[i].d==-1){
                    ver[i].pr=cur;
                    ver[i].d=G[cur][i];
                }
                else{
                  if(ver[cur].d+G[cur][i]<ver[i].d)
                  {
                    ver[i].d=ver[cur].d+G[cur][i];
                    ver[i].pr=cur;
                  }
                }

      }
      }

      int maxi=100, num;
      for(int i=1;i<=v;i++)
      {
        if(G[cur][i]!=0 && vis[cur][i]==0 && ver[i].vis!=1)
        {
             if(G[cur][i]<maxi)
                {
                    num=i;
                    maxi=G[cur][i];
                }

        }
      }
      ver[num].vis=1;
      path(G, ver, vis, num, des);
      }

void print_path(info ver[], int cur)
{
    if(ver[cur].d==-1){
        cout<<cur<<" ";
        return;
    }
    print_path(ver, ver[cur].pr);
    cout<<cur<<" ";
}

void initialize(info ver[])
{
    for(int i=1;i<=v;i++){
       ver[i].vis=0;
       ver[i].d=-1;
       ver[i].pr=-1;
    }
}

void mark(int vis[20][20], info ver[], int s, int cur)
{
    while(cur!=s){
        vis[ver[cur].pr][cur]=vis[cur][ver[cur].pr]=1;
        cur=ver[cur].pr;
    }
}
int main()
{
    int G[20][20],x ,y, dis, s, des;
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
      cin>>dis;
      G[x][y]=G[y][x]=dis;
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
    cout<<"Enter the source: ";
    cin>>s;
    cout<<"Enter the destination: ";
    cin>>des;
    info ver[20];
    initialize(ver);
    ver[s].vis=1;
    int vis[20][20];
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
           vis[i][j]=0;
    path(G, ver, vis, s, des);
    print_path(ver, des);        //Till here, code for the path from S to T.
    //Now all those edges which were part of the shortest path from S to T will be marked as 1.
    mark(vis, ver, s, des);
    initialize(ver);
    swap(s, des);
    ver[s].vis=1;
    cout<<"\nThe source and the destination have been swapped.The path is: ";
    path(G, ver, vis, s, des);
    //cout<<ver[1].pr;
    print_path(ver, des);
    return 0;
}
