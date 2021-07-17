#include<iostream>
using namespace std;
int v, res[50], rs=0, rsum=0, k=11;


int calc(int G[20][20], int a){
   int d=0;
   for(int i=1;i<=v;i++)
       if(G[a][i]==1) d++;
   return d;

}

void maxsumpath(int G[20][20], int deg[], int sum, int cur, int p, int ar[], int n)
{
    if(sum==k){
       for(int i=0;i<n;i++) cout<<ar[i]<<" ";
       cout<<"\n";
    }

/*    if(deg[cur]==1 && n!=1){
        if(sum>rsum){
            rsum=sum;
            rs=n;
            for(int i=0;i<n;i++)
                res[i]=ar[i];
        }
        return;
    }
*/
    for(int i=1;i<=v;i++){
        if(G[cur][i]==1 && i!=p){
            ar[n++]=i;
            maxsumpath(G, deg, sum+i, i, cur, ar, n);
            n--;
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

    cout<<"Start entering the edges...\n";
    while(1){
      cout<<"Enter x : ";
      cin>>x;
      if(x==-1) break;
      cout<<"Enter y : ";
      cin>>y;
      G[x][y]=G[y][x]=1;
      cout<<"\n";
    }

    int ar[20], deg[20];
    for(int i=1;i<=v;i++){
    	deg[i]=calc(G, i);
	}
    for(int i=1;i<=v;i++){
        ar[0]=i;
        maxsumpath(G, deg, i, i, 0, ar, 1);
    }
  //  cout<<"The maximum path sum is: "<<rsum;
  //  cout<<"\nThe path is: ";
   // for(int i=0;i<rs;i++) cout<<res[i]<<" ";
    return 0;
}
