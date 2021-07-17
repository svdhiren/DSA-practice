#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
typedef node* LPTR;

struct btnode {
	int data;
	btnode *lc, *rc;
};
typedef btnode* BTPTR;

BTPTR newnode(int k){
	BTPTR tmp = new btnode;
	tmp->data = k;
	tmp->lc=tmp->rc=NULL;
	return tmp;
}

LPTR addnode(int ar[], int n){
	static int i=0;
	if(i==n) return NULL;
	LPTR T = new node;
	T->data = ar[i++];
	T->next = addnode(ar, n);
	return T;
}

void search(BTPTR r, int k, BTPTR &s){
	if(r==NULL) return;
	if(r->data == k) { s=r; return; }
	search(r->lc, k, s);
	search(r->rc, k, s);
}

void createBT(LPTR head, BTPTR root){
	int i=0;
	LPTR tmp, t;
	BTPTR T;
	tmp = head;
	while(tmp!=NULL){
		//searching..
		 search(root, tmp->data, T);
		 t = head;
		 for(int j=0;j<2*i+1;j++)
		     if(t!=NULL) t=t->next;
		  if(t==NULL) break;
		  else{
		  	T->lc = newnode(t->data);
		  	if(t->next==NULL) break;
		  	else T->rc = newnode(t->next->data);
		  }
		  tmp = tmp->next;
		  i++;   
	}
}

void print(BTPTR T){
	if(T==NULL) return;
	cout<<T->data<<" ";
	print(T->lc);
	print(T->rc);
}

int main() {
	int ar[30], n;
	cout<<"Enter the number of elements in the linked list: ";
	cin>>n;
	cout<<"Start entering...\n";
	for(int i=0;i<n;i++){
		cout<<"Enter: ";
		cin>>ar[i];
	}
	LPTR head = addnode(ar, n);
	BTPTR root = newnode(head->data);
	createBT(head, root);
	cout<<"\nPreorder is given as: ";
	print(root);
	return 0;
}
