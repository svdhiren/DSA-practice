#include<iostream>
using namespace std;
struct bstnode{
	bstnode* lchild;
	int data;
	bstnode* rchild;
};
typedef struct bstnode* BSTPTR;
BSTPTR root= new bstnode;
void create_BST(BSTPTR T, BSTPTR root, BSTPTR tmp){  //Create function
static int x;
if(tmp->data>T->data)  {
	if(T->rchild==NULL) {
		T->rchild=tmp;
		BSTPTR t= new bstnode;
	cout<<"\nEnter the number: ";
	cin>>x;
	if(x==-1) return;
	t->data=x;
	t->lchild=NULL;
	t->rchild=NULL;
	create_BST(root, root, t);
	}
	else create_BST(T->rchild, root, tmp );
}
else{
if(T->lchild==NULL) {
		T->lchild=tmp;
		BSTPTR t= new bstnode;
	cout<<"\nEnter the number: ";
	cin>>x;
	if(x==-1) return;
	t->data=x;
	t->lchild=NULL;
	t->rchild=NULL;
	create_BST(root, root, t);
	}
	else create_BST(T->lchild, root, tmp );	
}	
	}
	
	void printLDR(BSTPTR T) {  ///Print function
		if(T==NULL) return;
		printLDR(T->lchild);
		cout<<T->data<<" ";
		printLDR(T->rchild);
		}
	
		
		
	void findrange(BSTPTR T, int& min, int& max){
		max=min=-1;
		if(T->lchild==NULL && T->rchild==NULL){
		     BSTPTR temp=root;
			 while(temp->data!=T->data){
			 	if(T->data < temp->data) {  max=temp->data; temp=temp->lchild; }
		        else { min=temp->data; temp=temp->rchild;}	 
			                                                                  }	
			}
		if(T->lchild==NULL && T->rchild!=NULL){
			BSTPTR temp=root;
			while(temp->data != T->data){
				if(T->data > temp->data) { min=temp->data; temp=temp->rchild; }
				else temp=temp->lchild;
		                              }
			temp=temp->rchild;
			while(temp->lchild != NULL) temp=temp->lchild;
			max=temp->data;	
				
	   }
		if(T->lchild!=NULL && T->rchild==NULL) {
			BSTPTR temp=root;
			while(temp->data != T->data){
				if(T->data < temp->data) { max=temp->data; temp=temp->lchild ;}
				else temp=temp->rchild;
			}
			temp=temp->lchild;
			while(temp->rchild!=NULL) temp=temp->rchild;
			min=temp->data;
		}
		
		if(T->lchild!=NULL && T->rchild!= NULL){
			BSTPTR temp;
			temp=T;
			temp=temp->lchild;
			while(temp->rchild != NULL) temp=temp->rchild;  //Finding the maximum value of the left subtree for minimmum range.
			min=temp->data;
			temp=T;
			temp=temp->rchild;
			while(temp->lchild != NULL ) temp=temp->lchild; //Finding the minimum value of the right subtree for maximum range.
			max=temp->data;
		}
			                                 
		}                                      
		                                      
		
	
	void traverseLDR(BSTPTR T) {
	    static int min, max;
		if(T==NULL) return;
		traverseLDR(T->lchild);
		findrange(T, min, max);
		if(min==-1) min=1;
		if(max==-1) max=1000; 
		cout<<"\nRange of values for "<<T->data<<" is ("<<min<<","<<max<<")";
		traverseLDR(T->rchild);
	}	
	
	
			
	int main() {
		BSTPTR T=NULL;
	int num;
	cout<<"Enter the root number: ";
	cin>>num;
	root->data=num;
	root->lchild=NULL;
	root->rchild=NULL;
	BSTPTR tmp= new bstnode;
    cout<<"\nStart entering the child numbers: ";
	cin>>tmp->data;
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	create_BST(root, root, tmp);
	
	cout<<"\nElements in LDR order: ";
	printLDR(root);
	
	traverseLDR(root);
	}	
