#include<iostream>
#include<cmath>
using namespace std;
struct gtnode{
 int data;
 gtnode* c[10];
};
typedef gtnode* GTPTR;

int k;

GTPTR newnode(int d){
 GTPTR tmp = new gtnode;
	tmp->data=d;
	for(int i=0;i<10;i++)
	    tmp->c[i]=NULL;
	return tmp;
 }

GTPTR construct_pre(int ar[], int n, int L, int l){
  static int i=0;
  if(l>L || i==n) return NULL;
  GTPTR T = newnode(ar[i++]);
  for(int j=0;j<k;j++)
     T->c[j] = construct_pre(ar, n, L, l+1);
  return T;
}

void print(GTPTR T) {
	if(T==NULL) return;
	for(int i=0; i<k; i++)
    	print(T->c[i]);
    cout<<T->data<<" ";

}

int main(){
cout<<"Enter the value of k:";
cin>>k;
int n, ar[20];
cout<<"Enter the number of elements: ";
cin>>n;
cout<<"Start entering...\n";
for(int i=0;i<n;i++) cin>>ar[i];
int s=0, l=0;
while(s<n){
    s+=pow(k,l);
    l++;
}
GTPTR root = construct_pre(ar, n, l, 1);
print(root);

}
