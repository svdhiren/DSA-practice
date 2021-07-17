#include<iostream>
using namespace std;

struct bstnode{
	bstnode* lchild;
	int data;
	bstnode* rchild;
};
typedef struct bstnode* BSTPTR;
void create_BST(BSTPTR T, BSTPTR root, BSTPTR tmp){
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

struct stack{
		int size;
		BSTPTR ele[50];
		int top;
	
	};
	
void push(stack &s, BSTPTR x){
		if(s.top!=s.size-1) s.ele[++s.top]=x;
		else cout<<"Stack overflow!";
		
	}
	BSTPTR pop(stack &s) {
      if(s.top!=-1)
        return(s.ele[s.top--]);
      else {
      	
      	BSTPTR del=new bstnode;
      	del->data=-1;
      	del->lchild=del->rchild=NULL;
      	return del;
	  }
	}
	
	void preorder(BSTPTR T, stack &s){
		cout<<T->data<<" ";
		do {
			if(T->rchild!=NULL) push(s, T->rchild);
			if(T->lchild != NULL) {
				T=T->lchild;
				cout<<T->data<<" ";
			}
			else {
				T=pop(s);
				if(T->data!=-1) cout<<T->data<<" ";
			}
			
		}while(T->data!=-1);
	}
	
	int main() {
		BSTPTR root=new bstnode;
		stack s1;
		s1.top=-1;
		s1.size=30;
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
	
	cout<<endl;
	preorder(root, s1);
	
	
	}
	
