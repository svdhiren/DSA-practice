#include<iostream>
using namespace std;
int v;

struct comp
{
    int w;
    int a;
    int b;
};

int calc(int dis[])
{   int sum=0;
    for(int i=1;i<=v;i++)
        if(dis[i]==0)
          sum++;
    return sum;
}

void initialize(comp edge[])
{
    for(int i=1;i<=v;i++){
        edge[i].a=0;
        edge[i].b=0;
        edge[i].w=100;
    }
}


int findpar(int dis[], int i)
{
    if(dis[i]==0)
        return i;
    else
     return findpar(dis, dis[i]);
}

void  union_it(int x, int y, int dis[])
{
    int p1=findpar(dis, x);
    int p2=findpar(dis, y);

    if(p1!=p2){
        if(p2>p1)
            dis[p1]=p2;
        else
            dis[p2]=p1;

    }
}

void create_MST(int G[20][20], int ans[20][20])
{
    comp edge[20];
    int dis[20];
    for(int i=1;i<=v;i++) dis[i]=0;

while(calc(dis) > 1){

  initialize(edge);
  for(int i=1;i<=v;i++)
    {
    for(int j=1;j<=v;j++)
    {
        if(G[i][j]!=0 && ans[i][j]==0)
        {
            if(findpar(dis, i)!=findpar(dis, j))
            {
                if(edge[findpar(dis, i)].w > G[i][j])
                {
                    edge[findpar(dis, i)].w=G[i][j];
                    edge[findpar(dis, i)].a=i;
                    edge[findpar(dis, i)].b=j;
                }
                if(edge[findpar(dis, j)].w > G[i][j])
                {
                    edge[findpar(dis, j)].w=G[i][j];
                    edge[findpar(dis, j)].a=i;
                    edge[findpar(dis, j)].b=j;
                }
            }
        }
    }
}  //End of double for loop.

for(int i=1;i<=v;i++){
    if(edge[i].w!=100){
        ans[edge[i].a][edge[i].b]=ans[edge[i].b][edge[i].a]=edge[i].w;
        union_it(edge[i].a, edge[i].b, dis);
    }
}
    }  //End of while loop.

}

int main()
{
    int G[20][20], ans[20][20], x ,y, dis;
    cout<<"Enter the number of nodes:";
    cin>>v;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
           {
               G[i][j]=0;
               ans[i][j]=0;
           }
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

    create_MST(G, ans);

    cout<<"\nThe MST is: \n";

    for(int i=1;i<=v;i++) cout<<"\t"<<i;
    cout<<"\n";
    for(int i=1;i<=v;i++){
        cout<<i<<"\t";
        for(int j=1;j<=v;j++)
            if(ans[i][j]!=0)
              cout<<ans[i][j]<<"\t";
            else cout<<"\t";
        cout<<"\n";
    }


}

