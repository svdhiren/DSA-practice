#include<iostream>
using namespace std;
struct bstnode{
	int data;
	int pr;
	bstnode* lc;
	bstnode* rc;
};
typedef struct bstnode* BSTPTR;
BSTPTR root = NULL;
int flag;
void insert(BSTPTR T, int k, int pr, BSTPTR p ) {
	  if(k < T->data){
		if(T->lc == NULL){
			BSTPTR tmp = new bstnode;
			tmp->data=k;
			tmp->lc=tmp->rc=NULL;
			tmp->pr = pr;
			T->lc=tmp;
		}
		else insert(T->lc, k, pr, T);
	}
	else{
		if(T->rc == NULL){
			BSTPTR tmp = new bstnode;
			tmp->data=k;
			tmp->lc=tmp->rc=NULL;
			tmp->pr = pr;
			T->rc=tmp;
		}
		else insert(T->rc, k, pr, T);
	   } 
	   
	//Checking the priority.
	flag=0;    
	if(T->lc!=NULL){
		if(T->pr < T->lc->pr){
			//Right rotation.
			flag=1;
			BSTPTR x = T->lc;
			if(p!=NULL){
				if(p->lc == T) p->lc = x;
				else p->rc = x;
				root = p;
			}
			else root = x;
		BSTPTR t = x->rc;
		x->rc = T;
		T->lc = t;	
		}
	}
	
	if(T->rc != NULL && flag!=1){
		if(T->pr < T->rc->pr){
			//Left rotation.
			BSTPTR x = T->rc;
			if(p!=NULL){
				if(p->lc == T) p->lc = x;
				else p->rc = x;
				root = p;
			}
			else root = x;
			BSTPTR t = x->lc;
			x->lc = T;
			T->rc = t;
		}
		else root=T; 	
		}
	else {
		if(flag!=1) root=T;
	}		
	   
	}
	
void print(BSTPTR T){
	if(T==NULL) return;
	cout<<T->data<<" ";
	print(T->lc);
	print(T->rc);
}

bool check(BSTPTR T, int min, int max) {
	if(T==NULL)
	   return true;
	if(T->data < min || T->data > max) return false;
	if(T->lc!=NULL) if(T->pr < T->lc->pr) return false;
	if(T->rc!=NULL) if(T->pr < T->rc->pr) return false;
	return (check(T->lc, min, T->data) && check(T->rc, T->data, max)); 
}



int main(){

	BSTPTR head = new bstnode;
	head->lc=head->rc=NULL;
	int n, k, pr;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"\nEnter the elements: ";
	for(int i=0;i<n;i++){
		cout<<"\nNumber: "; cin>>k;
		cout<<"Priority: "; cin>>pr;
		if(i==0) {
			head->data=k;
			head->pr=pr;
			root = head;
		}
		else  {
			insert(root, k, pr, NULL);
		}
		}
	cout<<"\nThe preorder of the tree is: ";
	print(root);
	if(check(root, 0, 200)) cout<<"\nTHe treap is indeed TREAP man!";
	else cout<<"\nThis is not a treap damn it...";
	root->rc->lc->data=65;
	if(check(root, 0, 200)) cout<<"\nTHe treap is indeed TREAP man!";
	else cout<<"\nThis is not a treap damn it...";
	root->rc->rc->pr=84;
	if(check(root, 0, 200)) cout<<"\nTHe treap is indeed TREAP man!";
	else cout<<"\nThis is not a treap damn it...";
		return 0;	
}
