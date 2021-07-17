#include<iostream>
#include<queue>
using namespace std;
struct btnode {
	int data;
	btnode* lc;
	btnode* rc;
};
typedef struct btnode* BTPTR;
BTPTR create(int ar[], int n){
	static int i=0;
	if(i==n || ar[i]==0)
	{
		return NULL;
	}
	BTPTR T= new btnode;
	T->data=ar[i];
	T->lc=T->rc=NULL;
	i++;
	T->lc=create(ar, n);
	i++;
	T->rc=create(ar,  n);
	
	return T;
}

void print(BTPTR t){
	if(t==NULL) return;
	cout<<t->data<<" ";
	print(t->lc);
	print(t->rc);
}

void search(BTPTR T, queue<int> q, int k, queue<int> &res){
	if(T==NULL) return;
	else{
		if(T->data==k){
			q.push(T->data);
			res=q;
			return;
		}
	}
    q.push(T->data);
	search(T->lc, q, k, res);
	if(T->rc==NULL) return;
	search(T->rc, q, k, res);
}

  int help(BTPTR T, int a, int b){
  	int lca;
	queue<int> A, B;
  	queue<int> r1, r2;
  	search(T, A, a, r1);
  	search(T, B, b, r2);
  	while(!r1.empty() && !r2.empty()){
  		if(r1.front() == r2.front())
  		         lca = r1.front();
  		r1.pop();
  		r2.pop();
		      
	  }
	return lca;  
  }
int main() {
	BTPTR root = new btnode;
	root=NULL;
	int size;
	size = 19;
	int arr[]={5,1,7,0,0,6,0,8,0,0,9,4,0,0,3,2,0,0,0};
	root = create(arr, size);
	print(root);
	int a, b;
	cout<<"\nEnter the two elememts whose LCA is to be found: ";
	cin>>a>>b;
	int lca = help(root, a, b);
	cout<<"\nThe LCA of "<<a<<" and "<<b<<" is: "<<lca;
	return 0;
}
