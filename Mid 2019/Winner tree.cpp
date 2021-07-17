#include<iostream>
using namespace std;
struct btnode{
	int data;
    btnode* lc;
    btnode* rc;
};
typedef struct btnode* BTPTR;
BTPTR newnode(int k){
	BTPTR tmp = new btnode;
	tmp->data = k;
	tmp->lc=tmp->rc= NULL;
	return tmp;
}

void winner(BTPTR T, int l, int L, int ar[]){
	static int i = 0;
	if(T->lc==NULL){
		if(l+1 < L) T->lc=newnode(0);
		else if(l+1 == L) T->lc=newnode(ar[i++]);
		else return;
		winner(T->lc, l+1, L, ar);
	}
	if(T->rc==NULL){
		if(l+1 < L) T->rc=newnode(0);
		else if(l+1 == L) T->rc=newnode(ar[i++]);
		else return;
		winner(T->rc, l+1, L, ar);
	}
}

void print(BTPTR T){
	if(T==NULL) return;
	cout<<T->data<<" ";
	print(T->lc);
	print(T->rc);
}

int The_winner(BTPTR T){
	if(T->lc==NULL && T->rc==NULL)
	    return T->data;
	int m = The_winner(T->lc);
	int n = The_winner(T->rc);
	return ((m > n) ? m : n);    
}

void make_zero(BTPTR T, int k){
	if(T==NULL) return;
	if(T->data==k) T->data=0;
	make_zero(T->lc, k);
	make_zero(T->rc, k);
}

int main() {
	BTPTR root= new btnode;
	int ar[20], n, L=0;
	cout<<"Enter the number of players: ";
	cin>>n;
	cout<<"Enter the scores: ";
	for(int i=0;i<n;i++) cin>>ar[i];
	while(n>0){
		L++;
		n=n/2;
	}
	L--;

	root = newnode(0);
	winner(root, 0, L, ar);
	cout<<"\nThe preorder is: ";
	print(root);
	for(int i=0; i<2;i++){
		int k = The_winner(root);
		make_zero(root, k);
	}
	cout<<"\nThe third best player is: "<<The_winner(root);
	return 0;
}
