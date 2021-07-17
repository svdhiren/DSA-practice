#include<iostream>
using namespace std;
int v;
struct info{
  int vis, d, pr, l, id; //id: increase or decrease.
};


void update(info ver[], int i, int d, int pr, int l, int id)
{
    ver[i].d=d;
    ver[i].l=l;
    ver[i].pr=pr;
    ver[i].id=id;
}

bool allvisit(info ver[])
{
    for(int i=1;i<=v;i++)
        if(ver[i].vis!=1)
          return false;
    return true;
}

void path(int G[20][20], info ver[], int cur){

    if(allvisit(ver))  return;


    for(int i=1;i<=v;i++)
    {
        if(G[cur][i]!=0 && ver[i].vis!=1)
        {
          if(ver[cur].d+G[cur][i] < ver[i].d)
        {
            if(ver[cur].id==-1){
                update(ver, i, G[cur][i], cur, G[cur][i], 0);
            }
            else if(ver[cur].id==0){
                int pri;
                if(G[cur][i] > ver[cur].l)
                    pri=1;
                else pri=2;
                update(ver, i,ver[cur].d+G[cur][i], cur, G[cur][i], pri);
            }
            else if(ver[cur].id==1){
                if(G[cur][i] > ver[cur].l)
                update(ver, i, ver[cur].d+G[cur][i], cur, G[cur][i], 1);
            }
            else{
               if(G[cur][i] < ver[cur].l)
                update(ver, i, ver[cur].d+G[cur][i], cur, G[cur][i], 2);
            }
        }

        }
      }

      int maxi=100, num;
      for(int i=1;i<=v;i++)
        if(ver[i].vis!=1)
          if(ver[i].d<maxi)
            {
             num=i;
             maxi=ver[i].d;
            }
      ver[num].vis=1;
      path(G, ver, num);


      }

void print_path(info ver[], int cur, int des)
{
    if(cur==des){
        cout<<cur<<" ";
        return;
    }
    print_path(ver, ver[cur].pr, 1);
    cout<<cur<<" ";
}

void initialize(info ver[20])
{
    for(int i=1;i<=v;i++){
       ver[i].vis=0;
       ver[i].d=100;
       ver[i].pr=0;
       ver[i].id=0;
       ver[i].l=-1;
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
    info ver[20];
    initialize(ver);
    ver[s].d=0;
    ver[s].vis=1;
    ver[s].id=-1;
    path(G, ver, s);
    print_path(ver, 6, 1);

    return 0;
}

/*
Input:
7
1
2
2
1
3
5
1
4
1
2
4
1
3
6
3
4
3
2
4
6
8
4
7
3
4
5
3
5
2
10
7
6
1
7
5
6
-1
*/
