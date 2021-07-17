#include<iostream>
using namespace std;
struct bstnode{
	bstnode* lchild;
	int data;
	bstnode* rchild;
};
typedef struct bstnode* BSTPTR;
BSTPTR newnode(){   //Creation of a new node
	BSTPTR temp=new bstnode;
	cout<<"Enter the number: ";
	cin>>temp->data;
	temp->lchild=temp->rchild=NULL;
	return temp;
}
void create_BST(BSTPTR T, BSTPTR root, BSTPTR tmp){
static int x;
if(tmp->data>T->data)  {
	if(T->rchild==NULL) {
		T->rchild=tmp;
		BSTPTR t=newnode();
		if(t->data==-1) return;
	create_BST(root, root, t);
	}
	else create_BST(T->rchild, root, tmp );
}
else{
if(T->lchild==NULL) {
		T->lchild=tmp;
		BSTPTR t= newnode();
		if(t->data==-1) return;
	    create_BST(root, root, t);
	}
	else create_BST(T->lchild, root, tmp );	
}	
	}
	
int findLCA(BSTPTR T, int n1, int n2){
	if(n1 < T->data && n2 > T->data)
	return T->data;
	else if(n1 > T->data) return (findLCA(T->rchild, n1, n2 ));
	else return(findLCA(T->lchild, n1, n2));
}	
   	
int main() {
	BSTPTR root=newnode();
	BSTPTR tmp=newnode();
	create_BST(root, root, tmp);
	int a1, a2;
	cout<<"\nEnter the two numbers whose LCA is to be found: ";
	cin>>a1>>a2;
	int k=findLCA(root, a1, a2);
	cout<<"\nThe LCA is: "<<k;
    return 0;
	}	
	
	
	
