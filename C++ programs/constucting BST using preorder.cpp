#include<iostream>
using namespace std;
struct bstnode{
	int data;
	bstnode* lchild;
	bstnode* rchild;
};
typedef struct bstnode* BSTPTR;
BSTPTR newnode(int x){
	BSTPTR tmp = new bstnode;
	tmp->data=x;
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	return tmp;
}
BSTPTR construct_BST(int ar[], int l, int h){
	if(l>h) return NULL;
	BSTPTR T= newnode(ar[l]);
	int i=l+1;
	 while(T->data > ar[i] && i<=h) i++;
	 T->lchild=construct_BST(ar, l+1, i-1);
	 T->rchild=construct_BST(ar, i, h);
	 
	 
	 return T; // THis 'T' contains the value of the root, i.e., the function has returned to its first call.
	 
}

 void print(BSTPTR T){
 	if(T==NULL) return;
 	print(T->lchild);
 	cout<<T->data<<" ";
 	print(T->rchild);
 } 

int main() {
	int size, a[50];
	cout<<"Enter the number of elements";
	cin>>size;
	for(int i=0; i<size; i++){
		cout<<"\nEnter: ";
		cin>>a[i];
	}
	BSTPTR root=construct_BST(a, 0, size-1);
	cout<<endl;
	print(root);
	return 0;
	}
