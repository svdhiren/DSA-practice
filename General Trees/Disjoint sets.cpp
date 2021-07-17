#include<iostream>
using namespace std;

int finder(int S[], int i, int N, int n){
   if(n>N)
    return 0;
   if(S[i]==0)
     return i;
   else return finder(S, S[i], N, n+1);
}

void Union(int S[], int n, int i, int j){
 if(S[i]==0)
     S[i]=j;
 else if(S[j]==0)
     S[j]=i;
 else {
    int x = finder(S, i, n, 0);
    if(x==0) cout<<"\nA loop is existing, the given elements are already related.";
    else S[x]=j;
 }


}

int Check(int S[], int i, int j, int N, int n){
if(n>N)
    return 0;
if(S[i]==j)
    return -1;
if(S[i]==0)
    return i;
return Check(S, S[i], j, N, n+1);
}

int main(){
int S[20];
S[0]=-1;
for(int i=1;i<20;i++)
    S[i]=0;
int n, i, j;
char ch;
cout<<"Enter the number of elements in the set: ";
cin>>n;
cout<<"Elements less than "<<n<<" are present in the set\n";
while(1){
    cout<<"Enter the two elements: ";
    cin>>i;
    if(i==-1) break;
    cin>>j;
    Union(S, n, i, j);
}

cout<<"\nEnter the two elements to be checked: ";
cin>>i>>j;
int p1 = Check(S, i, j, n, 0);
int p2 = Check(S, j, i, n, 0);
if(p1!=-1 && p1!=0){
    if(p1==p2)
        cout<<"\nThe elements are related!";
    else cout<<"\nNO";
}
else if(p1==0 && p2==-1 || p1==-1 && p2==0 || p1==-1 && p2==-1)
    cout<<"\nThe elements are related!";
     else cout<<"\nNO";

return 0;
}
