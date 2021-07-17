#include<iostream>
using namespace std;
struct btnode {
	char data;
	btnode* lc;
	btnode* rc;
};
typedef struct btnode* BTPTR;
BTPTR create(char ar[], int n){
	static int i=0;
	if(i==n || ar[i]=='.')
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

void printpath(BTPTR T, char ar[], int n){
	if(T!=NULL){
		if(T->lc == NULL && T->rc==NULL)
	{   ar[n++]=T->data;
	    cout<<endl;
		for(int i=0;i < n;i++) cout<<ar[i]<<" ";
		return;
	}
	}
	else if(T==NULL) return;
	ar[n++]=T->data;
	printpath(T->lc, ar, n);
	if(T->rc==NULL) return;
	printpath(T->rc, ar, n);
}

int main() {
	BTPTR root= new btnode;
	root=NULL;
	char a[50], b[50];
	int size;
	cout<<"Enter the size of the expression: ";
	cin>>size;
	cout<<"\nEnter preorder serialization expression: ";
	for(int i=0; i<size; i++) cin>>a[i];
	root=create(a, size);
	cout<<"\nThe preorder is: \n";
	print(root);
	cout<<endl;
	printpath(root, b, 0);
	return 0;
//	cout<<root->lc->rc->lc->data<<endl;
//	cout<<root->rc->rc->lc->data;
}
