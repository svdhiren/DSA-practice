#include<iostream>
using namespace std;
int v;
struct info{
  int vis, d, pr;
};

void path(int G[20][20], info ver[], int w[], int cur, int des){

      if(cur==des){
        return;
      }
      for(int i=1;i<=v;i++){
        if(G[cur][i]==1 && ver[i].vis!=1){

                if(ver[i].d==-1){
                    ver[i].pr=cur;
                    ver[i].d=w[i];
                }
                else{
                  if(ver[cur].d+w[i]<ver[i].d)
                  {
                    ver[i].d=ver[cur].d+w[i];
                    ver[i].pr=cur;
                  }
                }

      }
      }

      int maxi=100, num;
      for(int i=1;i<=v;i++)
      {
        if(G[cur][i]==1 && ver[i].vis!=1)
        {
             if(w[i]<maxi)
                {
                    num=i;
                    maxi=w[i];
                }

        }
      }
      ver[num].vis=1;
      path(G, ver, w, num, des);
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

int main()
{
    int G[20][20], w[20], x, y, s, des;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    for(int i=1;i<=v;i++)
    {
        cout<<"Enter the weight of vertex "<<i<<" : ";
        cin>>w[i];
    }
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
      G[x][y]=1;
      cout<<"\n";
    }
    cout<<"Enter the source: ";
    cin>>s;
    cout<<"Enter the destination: ";
    cin>>des;
    info ver[20];
    for(int i=1;i<=v;i++){
       ver[i].vis=0;
       ver[i].d=-1;
       ver[i].pr=-1;
    }
    ver[s].vis=1;
    path(G, ver, w, s, des);
    print_path(ver, des);
    return 0;

}
