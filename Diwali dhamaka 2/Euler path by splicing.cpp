#include<iostream>
using namespace std;
int v;

void insert_ele(int ar[], int ele, int pos, int &n){

	for(int i=n;i>pos;i--)
	    ar[i]=ar[i-1];
	 ar[pos]=ele;
	 n++;
}

void delete_ele(int ar[], int pos, int &n)
{
    for(int i=pos;i<n-1;i++)
         ar[i]=ar[i+1];
     n--;

}

bool degreezero(int deg[]){
	for(int i=1;i<=v;i++)
	  if(deg[i]!=0)
	    return false;

	return true;
}

void euler_path(int G[20][20], int done[20][20], int deg[], int cur, int ar[], int index, int n){

	if(degreezero(deg)){
		for(int i=0;i<n;i++) cout<<ar[i]<<" ";
		cout<<"\n";
		return;
	}
	if(deg[cur]==0){
	//Then we need to search for the appropriate index.
	int a;
	for(a=0;a<n;a++)
	   if(deg[ar[a]]!=0)
	     break;
     index=a;
     a=ar[a];
	for(int i=1;i<=v;i++){
		if(G[a][i]!=0 && done[a][i]!=1){
			done[a][i]=done[i][a]=1;
			insert_ele(ar, i, index+1, n);
			deg[a]--;
			deg[i]--;
			euler_path(G, done, deg, i, ar, index+1, n);
        //For combinations; uncomment the below statements.
		//	done[a][i]=done[i][a]=0;
		//	delete_ele(ar, index+1, n);
		//	deg[a]++;
		//	deg[i]++;
		}
	}
	}
	else{
		for(int i=1;i<=v;i++){
			if(G[cur][i]!=0 && done[cur][i]!=1){
			done[cur][i]=done[i][cur]=1;
			insert_ele(ar, i, index+1, n);
			deg[cur]--;
			deg[i]--;
			euler_path(G, done, deg, i, ar, index+1, n);
        //For combinations; uncomment the below statements.
		//	done[cur][i]=done[i][cur]=0;
		//	delete_ele(ar, index+1, n);
		//	deg[cur]++;
		//	deg[i]++;
			}
		}
	}

}

int calc(int G[20][20], int a){
   int d=0;
   for(int i=1;i<=v;i++)
       if(G[a][i]==1) d++;
   return d;

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

    int ar[100], deg[20];
    for(int i=1;i<=v;i++) deg[i]=0;
    for(int i=1;i<=v;i++){
    	deg[i]=calc(G, i);
	}
	ar[0]=1;
	euler_path(G, done, deg, 1, ar, 0, 1);
    return 0;

}
