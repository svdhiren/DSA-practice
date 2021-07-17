#include<iostream>
using namespace std;
struct btnode {
	int data;
	btnode* lc;
	btnode* rc;
};
typedef struct btnode* BTPTR;
BTPTR newnode(int k){
	BTPTR tmp = new btnode;
	tmp->data=k;
	tmp->lc=tmp->rc=NULL;
	return tmp;
}
BTPTR construct(int ar[], int n, int i){
	
	if(i>=n) return NULL;
	BTPTR T=newnode(ar[i]);
	T->lc = construct(ar, n, 2*i+1);
	T->rc = construct(ar, n, 2*i+2);
	
	return T;
	

}
void print(BTPTR t){
	if(t==NULL) return;
	print(t->lc);
	cout<<t->data<<" ";
	print(t->rc);
}

int main() {
	int a[30], size;
	cout<<"Enter the number of elements: ";
	cin>>size;
	cout<<"\nEnter the elements: ";
	for(int i=0; i<size; i++) cin>>a[i];
	BTPTR root = NULL;
	root = construct(a, size, 0);
	cout<<"\nThe inorder of the tree is: "<<endl;
	print(root);
	return 0;
}
