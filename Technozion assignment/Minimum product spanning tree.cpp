#include<iostream>
#include<cmath>
using namespace std;
int v;

bool allvisit(int vis[])
{
    for(int i=1;i<=v;i++)
        if(vis[i]==0)
         return false;
    return true;
}

void prim(int G[20][20], int ans[20][20], int vis[], float d[], int pre[], int cur)
{
    if(allvisit(vis))
        return;

    for(int i=1;i<=v;i++){
        if(G[cur][i]!=0 && vis[i]!=1){
            if(log(G[cur][i]) < d[i]){
                d[i]=log(G[cur][i]);
                pre[i]=cur;
            }
        }
    }

    int  num;
    float mini=100.0;
    for(int i=1;i<=v;i++){
        if(d[i]<mini && vis[i]!=1)
        {
            mini=d[i];
            num=i;
        }
    }
    vis[num]=1;
    ans[num][pre[num]]=ans[pre[num]][num]=G[num][pre[num]];

    prim(G, ans, vis, d, pre, num);
}

int main()
{
    int G[20][20], ans[20][20], x ,y, dis, s, des;
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
    int pre[20], vis[20];
    float d[20];
    for(int i=1;i<=v;i++){
        pre[i]=0;
        d[i]=100.0;
        vis[i]=0;
    }
    d[1]=0;
    vis[1]=1;
    prim(G, ans, vis, d, pre, 1);

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
/*  INPUT
*/
