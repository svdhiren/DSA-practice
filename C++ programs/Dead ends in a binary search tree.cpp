#include<iostream>
using namespace std;
struct bstnode{
	bstnode* lchild;
	int data;
	bstnode* rchild;
};
typedef struct bstnode* BSTPTR;
BSTPTR newnode(){
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
    
/*	void isBST(BSTPTR T, int min, int max) {
		
		if(T==NULL) return;
		if(T->data<min || T->data>max) {
			k=-1;
			cout<<"\nPOINT OF violation = "<<T->data;
			return;
		}
	    isBST(T->lchild, min, T->data-1);
	    isBST(T->rchild, T->data+1, max);
	} */
	int k=1;
	void isDeadEnd(BSTPTR T, int min, int max){
		if(T==NULL) return;
		if((T->data==min && T->rchild!=NULL) || (T->data==max && T->lchild!=NULL) || (min==max))
		{  k=-1;
	       cout<<"\n"<<T->data<<" is a deadend.";
		}
		isDeadEnd(T->lchild, min, T->data-1);
		isDeadEnd(T->rchild, T->data+1, max);
	}
int main() {
	BSTPTR root=newnode();
	BSTPTR tmp=newnode();
	create_BST(root, root, tmp);
    isDeadEnd(root, 0, 1000);
    if(k==1) cout<<"\nThere are no dead ends.";
    return 0;
}	
	
