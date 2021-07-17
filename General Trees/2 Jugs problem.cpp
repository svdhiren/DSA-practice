#include<iostream>
#include<queue>
using namespace std;
struct state
{
    int x;
    int y;
};

int calc_i(state s){
  return (4*s.x+s.y);
}

int calc_ind(int G[20][20], int a){
  int ind=0;
  for(int i=0;i<20;i++)
     if(G[i][a]==1) ind++;
  return ind;

}

void create_graph(int G[20][20], int vis[])
{   int ct=1;
    queue<state> q;
    int d=0, fl=1;
    state tmp;
    state str;
    str.x=0;  str.y=0;
    q.push(str);
    while(1){
     tmp = q.front(); q.pop();
     cout<<"Iteration "<<ct++<<" : ("<<tmp.x<<","<<tmp.y<<")\n";
     //Initial conditions where the state is (0,0).
     if(tmp.x==0 && tmp.y==0 && fl==1){
     //   cout<<1<<"\n";
        fl=0;
        str.x=4; str.y=0;
        vis[4*4]=1;
        q.push(str);
        G[calc_i(tmp)][calc_i(str)]=1;
        str.x=0; str.y=3;
        vis[3]=1;
        q.push(str);
        G[calc_i(tmp)][calc_i(str)]=1;
     }

     //If one of them can be filled.
     if(tmp.x==0)
     if(vis[4*4+tmp.y]!=1){
        str.x=4; str.y=tmp.y;
        vis[4*4+tmp.y]=1;
        q.push(str);
        G[calc_i(tmp)][calc_i(str)]=1;
        if(str.x==2 || str.y==2) break;
     }

     if(tmp.y==0)
     if(vis[4*tmp.x + 3]!=1){
        str.x=tmp.x; str.y=3;
        vis[4*tmp.x + 3]=1;
        q.push(str);
        G[calc_i(tmp)][calc_i(str)]=1;
        if(str.x==2 || str.y==2) break;
     }

     //If only X can be emptied.
     if(vis[tmp.y]!=1){
      //  cout<<2<<"\n";
        str.x=0; str.y=tmp.y;
        vis[tmp.y]=1;
        q.push(str);
        G[calc_i(tmp)][calc_i(str)]=1;
        if(str.x==2 || str.y==2) break;
     }

     //If only Y can be emptied.
     if(vis[4*tmp.x]!=1){
       // cout<<3<<"\n";
        str.x=tmp.x; str.y=0;
        vis[4*tmp.x]=1;
        q.push(str);
        G[calc_i(tmp)][calc_i(str)]=1;
        if(str.x==2 || str.y==2) break;
     }

     //Transferring contents from X to Y so that Y is full.
      d=3-tmp.y;
      if(tmp.x-d>=0)
      if(vis[4*(tmp.x-d)+3]!=1){
      //  cout<<4<<"\n";
        str.x=tmp.x-d; str.y=3;
        vis[calc_i(str)]=1;
        q.push(str);
        G[calc_i(tmp)][calc_i(str)]=1;
        if(str.x==2 || str.y==2) break;
      }

      //Emptying the contents of X and transferring to Y.
      if((tmp.y+tmp.x)<=3)
      if(vis[tmp.y+tmp.x]!=1){
      //  cout<<5<<"\n";
        str.x=0; str.y=tmp.y+tmp.x;
        vis[calc_i(str)]=1;
        q.push(str);
        G[calc_i(tmp)][calc_i(str)]=1;
        if(str.x==2 || str.y==2) break;
      }

      //Transferring contents from Y to X so that X is full.
      d=4-tmp.x;
      if(tmp.y-d>=0)
      if(vis[4*4+tmp.y-d]!=1){
      //  cout<<6<<"\n";
        str.x=4; str.y=tmp.y-d;
        vis[calc_i(str)]=1;
        q.push(str);
        G[calc_i(tmp)][calc_i(str)]=1;
        if(str.x==2 || str.y==2) break;
      }

      //Emptying the contents of Y and transferring to X.
      if((tmp.y+tmp.x)<=4)
      if(vis[4*(tmp.y+tmp.x)]!=1){
      //  cout<<7<<"\n";
        str.x=tmp.y+tmp.x; str.y=0;
        vis[calc_i(str)]=1;
        q.push(str);
        G[calc_i(tmp)][calc_i(str)]=1;
        if(str.x==2 || str.y==2) break;
      }
  }
}

void print(int G[20][20], int In[], int vis[], state res[], int ct)
{
    static int flag=1;
    for(int i=0;i<20 && flag==1;i++){
        if(vis[i]!=1 && In[i]==0){
            vis[i]=1;
            res[ct].x=i/4;
            res[ct].y=i%4;
            ct++;
            if(i/4==2 || i%4==2){
                for(int j=0;j<ct;j++)
                    cout<<res[j].x<<","<<res[j].y<<"  ";
                flag=0;
            }
            for(int a=0;a<20;a++)
                if(G[i][a]==1)
                 In[a]--;
            print(G, In, vis, res, ct);
            if(flag==0) return;
            ct--;
            vis[i]=0;
            for(int a=0;a<20;a++)
                if(G[i][a]==1)
                 In[a]--;
        }
    }
}

int main()
{   //The capacity of jug1 is 4L and that of jug2 is 3L. So maximum state is:(4,3).
    int G[20][20];
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            G[i][j]=0;
    int vis[30];
    for(int i=0;i<20;i++) vis[i]=0;
    vis[0]=1;
    create_graph(G, vis);
    cout<<"The graph is: \n";
    for(int i=0;i<20;i++)
    {   cout<<" ";
        for(int j=0;j<20;j++)
            cout<<G[i][j]<<" ";
        cout<<"\n";
    }
    state res[20];
    int In[20];
  //  for(int i=0;i<20;i++) vis[i]=0;
    for(int i=0;i<20;i++) In[i]=calc_ind(G, i);
    print(G, In, vis, res, 0);
    return 0;
}
