#include<iostream>
using namespace std;
int v;

int calc(int G[20][20], int a){
   int ind=0;
   for(int i=1;i<=v;i++)
       if(G[i][a]==1) ind++;
   return ind;

}

void toposort(int G[20][20], int vis[], int In[], int res[], int ct)
{   static int ctr=1;
    for(int i=1;i<=v;i++)
    {
        if(vis[i]!=1 && In[i]==0){
            res[ct++]=i;
            if(ct==v){
                cout<<ctr<<".) "; ctr++;
                for(int j=0;j<ct;j++) cout<<res[j]<<" ";
                cout<<"\n";

            }
            vis[i]=1;
            for(int j=1;j<=v;j++)
                if(G[i][j]==1)
                In[j]--;
            toposort(G, vis, In, res, ct);
            ct--;
            vis[i]=0;
            for(int j=1;j<=v;j++)
                if(G[i][j]==1)
                In[j]++;
        }
    }

}

int main()
{

    int G[20][20],x ,y;
    cout<<"Enter the number of nodes:";
    cin>>v;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
           G[i][j]=0;
    while(1){
      cout<<"Enter x : ";
      cin>>x;
      if(x==-1) break;
      cout<<"Enter y : ";
      cin>>y;
      G[x][y]=1;
    }
    int vis[20], In[20], res[20], ct=0;
    for(int i=0;i<=v;i++) vis[i]=0;
    for(int i=1;i<=v;i++) In[i]=calc(G, i);
    cout<<"THE VARIOUS POSSIBILITIES ARE: \n";
    toposort(G, vis, In, res, 0);

    return 0;
}
