#include<iostream>
#include<string.h>
using namespace std;
int v;

bool compare(string s1, string s2)
{
    if(s1.size()!=s2.size()){
    if(s1.substr(1)==s2 || s1.substr(0, s1.size()-2)==s2 ||
           s2.substr(1)==s1 || s2.substr(0, s2.size()-2)==s1)
       return true;
    }
    else {
        if(s1.substr(1)==s2.substr(1) || s1.substr(0, s1.size()-2)==s2.substr(0, s2.size()-2))
            return true;
    }

    return false;
}

struct info{
  int vis, d, pr;
};


void path(int G[20][20], info ver[], int cur, int des){
      if(cur==des)
        return;
      for(int i=1;i<=v;i++)
      {
        if(G[cur][i]!=0 && ver[i].vis!=1)
        {
          if(ver[cur].d+G[cur][i]<ver[i].d)
         {
            ver[i].d=ver[cur].d+G[cur][i];
            ver[i].pr=cur;
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

void print_path(info ver[], int cur, string s[])
{
    if(ver[cur].d==0){
        cout<<s[cur]<<"->";
        return;
    }
    print_path(ver, ver[cur].pr, s);
    cout<<s[cur]<<"->";
}

void initialize(info ver[20])
{
    for(int i=1;i<=v;i++){
       ver[i].vis=0;
       ver[i].d=100;
       ver[i].pr=0;
    }
}


int main()
{
    v=7;
    int G[20][20], x, y, src, des;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
          G[i][j]=0;

    string s[]={"", "BCCI", "AICC", "ICC", "CCI", "MCC", "MCA", "ACC"};

    for(int i=1;i<=v;i++)
        for(int j=i+1;j<=v;j++)
            if(compare(s[i], s[j]))
        {
            G[i][j]=G[j][i]=1;
            cout<<s[i]<<"-"<<s[j]<<"\n";
        }

    for(int i=1;i<=v;i++) cout<<"\t"<<s[i];
    cout<<"\n";
    for(int i=1;i<=v;i++){
        cout<<s[i]<<"\t";
        for(int j=1;j<=v;j++)
            if(G[i][j]!=0)
              cout<<G[i][j]<<"\t";
            else cout<<"\t";
        cout<<"\n";
    }
    cout<<"Enter the source: ";
    cin>>src;
    cout<<"Enter the destination: ";
    cin>>des;
    info ver[20];
    initialize(ver);
    ver[src].vis=1;
    ver[src].d=0;
    path(G, ver, src, des);
    print_path(ver, des, s);
    cout<<"\b";




}
