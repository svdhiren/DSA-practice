#include<iostream>
using namespace std;
struct btnode {
	int data;
	btnode* lc;
	btnode* rc;
	int hd;
};
typedef struct btnode* BTPTR;

BTPTR create(int ar[], int n){
	static int i = 0;
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
	print(t->lc);
	cout<<t->data<<" ";
	print(t->rc);
}
int l=0;
void sort(BTPTR T, int ar[]){
	
	if(T==NULL) return;
	if(l==0){ ar[l]=T->data; l++; }
	else
	{ 
	    int j;
		for( j=0 ; j<l ; j++)
			if(T->data < ar[j]) break;
		for(int k=l ; k>j ; k--)
		    ar[k]=ar[k-1];
		ar[j]=T->data;
		l++;    
	}
	sort(T->lc, ar);
	sort(T->rc, ar);
}

void change(BTPTR T, int ar[]){
	static int i=0;
	if(T==NULL) return;
	change(T->lc, ar);
	T->data=ar[i++];
	change(T->rc, ar);
}

int main() {
	BTPTR root = new btnode;
	root=NULL;
	int a[50], size;
	cout<<"Enter the size of the expression: ";
	cin>>size;
	cout<<"\nEnter preorder serialization expression: ";
	for(int i=0; i<size; i++) cin>>a[i];
	root = create(a, size);
	cout<<"\nThe inorder of the binary tree given: ";
	print(root);
	int b[50];
	sort(root, b);
    change(root, b);
    cout<<"\nThe inorder of the BST obtained is: ";
	print(root);	
	return 0;
}
