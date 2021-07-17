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
void printrev(BTPTR T){
	if(T==NULL) return;
	printrev(T->rc);
	printrev(T->lc);
	cout<<T->data<<" ";
}
void printcode(BTPTR T, int ar[], int n){
	if(T==NULL) return;
	if(T->lc==NULL && T->rc==NULL){
		cout<<"\nThe code for "<<T->data<<" is: ";
		for(int i=0; i<n;i++) cout<<ar[n++];
	}
	if(T->lc!=NULL) ar[n++]=0;
	printcode(T->lc, ar, n);
	if(T->rc!=NULL) ar[n++]=1;
	printcode(T->rc, ar, n++);
}

int main() {
	BTPTR root= new btnode;
	root=NULL;
	int size;
	size= 19;
	char a[]={'1', '2','4','8','.', '.', '9', '.', '.', '5', '.', '.', '3', '6', '.', '.', '7', '.', '.' };
	root=create(a, size);
	cout<<"\nThe preorder is: \n";
	print(root);
	cout<<endl;
	printrev(root);
//	cout<<root->lc->rc->lc->data<<endl;
//	cout<<root->rc->rc->lc->data;
//  int ar[50];
//  printcode(root, ar, 0);
    return 0;
}
