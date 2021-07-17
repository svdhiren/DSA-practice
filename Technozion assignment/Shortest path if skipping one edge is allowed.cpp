#include<iostream>
using namespace std;
int v;
struct info{
  int vis, d, pr, m;
};


void path(int G[20][20], info ver[], int cur, int des){

      if(cur==des)
        return;
      for(int i=1;i<=v;i++)
      {
        if(G[cur][i]!=0 && ver[i].vis!=1)
        {
          if(ver[cur].m>G[cur][i]){
            if((ver[cur].d+G[cur][i]-ver[cur].m) < (ver[i].d-ver[i].m)){
                ver[i].d=ver[cur].d+G[cur][i];
                ver[i].m=ver[cur].m;
                ver[i].pr=cur;
            }
          }
          else{
            if(ver[cur].d < (ver[i].d-ver[i].m)){
                ver[i].d=ver[cur].d+G[cur][i];
                ver[i].m=G[cur][i];
                ver[i].pr=cur;
            }
          }
        }
      }

      int maxi=100, num;
      for(int i=1;i<=v;i++)
      {
        if(ver[i].vis!=1)
        {
             if(ver[i].d<maxi)
                {
                    num=i;
                    maxi=ver[i].d;
                }

        }
      }
      ver[num].vis=1;
      path(G, ver, num, des);
      }

void print_path(info ver[], int cur, int des)
{
    if(cur==des){
        cout<<cur<<" ";
        return;
    }
    print_path(ver, ver[cur].pr, des);
    cout<<cur<<" ";
}

void initialize(info ver[20])
{
    for(int i=1;i<=v;i++){
       ver[i].vis=0;
       ver[i].d=100;
       ver[i].pr=0;
       ver[i].m=0;
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
      G[x][y]=dis;
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
    ver[s].d=0;
    path(G, ver, s, des);
    print_path(ver, des, s);

    return 0;
}
/* Input: 7 1 2 2 1 3 5 1 4 1 2 4 3 3 6 7 4 3 2 4 6 8 4 7 4 4 5 2 5 2 10 7 6 1 7 5 6 */

