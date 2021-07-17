#include<iostream>
#include<stack>
using namespace std;
struct btnode {
	int data;
	btnode* lc;
	btnode* rc;
};
typedef struct btnode* BTPTR;
int count;
BTPTR create(int ar[], int n){
	static int i=0;
	if(i==n || ar[i]==0)
	{
		count--;
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

void ancestor(BTPTR T){
	stack<BTPTR> s1; stack<int> s2; int ar[50]; int n;
	int i=0;
	while(i<count){
		if(n==0) cout<<"\nAncestors for "<<T->data<<" : Nothing.";
		else{
			cout<<"\nAncestors for "<<T->data<<" : ";
			for(int i=0;i<n;i++) cout<<ar[i]<<" ";
		}
		ar[n++]=T->data;
		i++;
		if(T->rc!=NULL){
			s1.push(T->rc);
			s2.push(n);
		}
		if(T->lc!=NULL) T=T->lc;
		else if(i<count){
			T=s1.top(); s1.pop();
			n=s2.top(); s2.pop();
		}
		
	}
}

int main() {
	BTPTR root = new btnode;
	root=NULL;
	int size;
	size = 19;
	count=size;
	int arr[]={5,1,7,0,0,6,0,8,0,0,9,4,0,0,3,2,0,0,0};
	root = create(arr, size);
	print(root);
//	cout<<"\n"<<count;
	ancestor(root);
}
