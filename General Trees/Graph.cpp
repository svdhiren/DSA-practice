#include<iostream>
using namespace std;
int v;
int calc(int G[20][20], int a){
   int ind=0;
   for(int i=1;i<=v;i++)
       if(G[i][a]==1) ind++;
   return ind;

}

void makezero(int G[20][20], int a){
     for(int i=1;i<=v;i++)
        G[a][i]=0;
}

void print(int G[20][20])
{
   int ar[10], ind;
   for(int i=1;i<=v;i++) ar[i]=0;
   for(int i=1;i<=v;i++){
     if(ar[i]!=-1){
        ind=calc(G, i);
        if(ind==0){
            cout<<i<<" ";
            makezero(G, i);
            ar[i]=-1;
            i=1;
        }
     }

   }

}

int main()
{   //The first array and the first elements of the other arrays are dummy.
    //This has been done so that index 1 can be used as the starting one.
    int G[20][20]={ {0,0,0,0,0,0,0,0,0,0}, {2,0,0,0,0,1,0,0,0,0}, {2,0,0,0,0,1,0,0,1,0}, {2,0,0,0,1,0,0,0,0,1},
{2,0,0,0,0,0,0,1,0,0}, {2,0,0,0,0,0,1,0,0,0}, {2,0,0,0,0,0,0,1,0,0}, {2,0,0,0,0,0,0,0,0,0}, {2,0,0,0,0,0,1,0,0,0},
{2,0,0,0,0,0,0,1,0,0}
                };
    v=9;
    print(G);
   // cout<<calc(G, 7);
   return 0;
}
