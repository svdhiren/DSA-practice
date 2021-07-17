#include<iostream>
using namespace std;
int v;

int calc(int G[20][20], int a){
   int ind=0;
   for(int i=1;i<=v;i++)
       if(G[i][a]==1) ind++;
   return ind;

}

void toposort(int G[20][20])
{
    int vis[20], In[20];
    for(int i=0;i<=v;i++) vis[i]=0;
    for(int i=1;i<=v;i++) In[i]=calc(G, i);
    for(int i=1;i<=v;i++)
    {
        if(vis[i]!=1 && In[i]==0)
        {
                cout<<i<<" ";
                vis[i]=1;
                for(int j=1;j<=v;j++)
                    if(G[i][j]==1)
                      In[j]--;
                i=0;

        }
    }

}

int main()
{
   //The first array and the first elements of the other arrays are dummy.
   //This has been done so that index 1 can be used as the starting one.
    int G[20][20]={ {0,0,0,0,0,0,0,0,0,0}, {2,0,0,0,0,1,0,0,0,0}, {2,0,0,0,0,1,0,0,1,0},
    {2,0,0,0,1,0,0,0,0,1},{2,0,0,0,0,0,0,1,0,0}, {2,0,0,0,0,0,1,0,0,0},
    {2,0,0,0,0,0,0,1,0,0}, {2,0,0,0,0,0,0,0,0,0}, {2,0,0,0,0,0,1,0,0,0},
    {2,0,0,0,0,0,0,1,0,0} };

    v=9;
    toposort(G);
    return 0;
}
