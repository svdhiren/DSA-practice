#include<iostream>
using namespace std;
int v;
void permute(int G[20][20], int ar[], int s, int e){
	if(s==e){
		int a;
		for(a=1;a<v;a++)
		  if(G[ar[a]][ar[a+1]]!=1)
		   break;
		if(a==v){
			for(int k=1;k<=v;k++)
		        cout<<ar[k]<<" ";
		    cout<<"\n";
		}	    
	}
	else{
	
	for(int i=s;i<=e;i++){
		swap(ar[s], ar[i]);
	    permute(G, ar, s+1, e);
	    swap(ar[s], ar[i]);
	}
}
}

int main()
{
    int G[20][20],x ,y, done[20][20];
    cout<<"Enter the number of nodes:";
    cin>>v;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
           {
           	G[i][j]=0;
           	done[i][j]=0;
		   }
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

    int ar[20];
    for(int i=1;i<=v;i++) ar[i]=i;
    permute(G, ar, 1, v);
    return 0;

}
