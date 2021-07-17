#include<iostream>
#include<queue>
using namespace std;
int v;

bool allvisit(int vis[])
{
    for(int i=1;i<=v;i++)
        if(vis[i]==0)
         return false;
    return true;
}

void prim(int G[20][20], int ans[20][20], int vis[], int d[], int pre[], int cur)
{
    if(allvisit(vis))
        return;

    for(int i=1;i<=v;i++){
        if(G[cur][i]!=0 && vis[i]!=1){
            if(G[cur][i] < d[i]){
                d[i]=G[cur][i];
                pre[i]=cur;
            }
        }
    }

    int mini=100, num;
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

bool cyclic(int G[20][20], int vis[], int cur, int p)
{
    for(int i=1;i<=v;i++){
        if(G[cur][i]!=0 && i!=p){
            if(vis[i]==1)
                return false;
            else{
                vis[i]=1;
                return cyclic(G, vis, i, cur);
            }
        }
    }
    if(cur==1) return true;
}

void secondbest(int G[20][20], int ans[20][20])
{

int inc=100, r, vis[20];
pair<int ,int> p;

for(int i=1;i<=v;i++)
{
    for(int j=i+1;j<=v;j++)
    {
        if(ans[i][j]!=0)
        {

    for(int k=1;k<=v;k++)
    {
        if(G[i][k]!=0 && k!=j && ans[i][k]==0 && (G[i][k]-ans[i][j])<inc)
        {
            ans[i][j]=ans[j][i]=0;
            ans[i][k]=ans[k][i]=G[i][k];
            for(int a=1;a<=v;a++) vis[a]=0;
            vis[1]=1;
            if(isconnected(ans))
            {
                inc=G[i][k]-ans[i][j];
                p.first=i;
                p.second=j;
                r=k;
            }
            ans[i][j]=ans[j][i]=G[i][j];
            ans[i][k]=ans[k][i]=0;
        }

    }

        }
    }
}
cout<<p.first<<" "<<p.second;
cout<<"\n"<<r;
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
    int pre[20], d[20], vis[20];
    for(int i=1;i<=v;i++){
        pre[i]=0;
        d[i]=100;
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

    secondbest(G, ans);



}


/* input
6
1
2
13
2
3
7
3
4
7
4
5
36
5
1
39
1
6
27
2
6
28
3
6
2
4
6
14
5
6
34
-1
*/








