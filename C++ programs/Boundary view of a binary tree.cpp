#include<iostream>
using namespace std;
struct btnode {
	int data;
	int hd;
	btnode* lc;
	btnode* rc;
};
typedef struct btnode* BTPTR;
BTPTR create(int ar[], int n){
	static int i=0;
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

void hd_cal(BTPTR T, int hd) {
	if(T==NULL) return;
	T->hd=hd;
	cout<<"\nThe value of hd for "<<T->data<<" is: "<<T->hd;
	hd_cal(T->lc, hd-1);
	hd_cal(T->rc, hd+1);
}

void leftside(BTPTR T, int ar[], int &n){
	static int flag=0;
	if(T->lc==NULL && T->rc==NULL) {
	   ar[n++]=T->data;
	   flag=1;
	   return;
	}
	if(T->lc == NULL){
		ar[n++]=T->data;
		if(flag!=1) leftside(T->rc, ar, n);
	}
	if(flag!=1){
		ar[n++]=T->data;
	    leftside(T->lc, ar, n);
	}
}

void bottomside(BTPTR T, int ar[], int &n){
	static int flag = 1;
	if(T==NULL) return;
	bottomside(T->lc, ar, n);
	if(T->lc == NULL && T->rc == NULL){
		if(flag!=1){
			ar[n++]=T->data;
		}
		else flag=0;
	}
	bottomside(T->rc, ar, n);
}

void rightside(BTPTR T, int ar[], int &n){
	static int flag=0;
	if(T->rc==NULL && T->lc==NULL){
		flag=1;
		ar[n++]=T->data;
		return;
	}
	if(T->rc==NULL){
		if(flag!=1){
			rightside(T->lc, ar, n);
			ar[n++]=T->data;
		}
	}
	if(flag!=1){
		rightside(T->rc, ar, n);
		ar[n++]=T->data;
	}
}

int main() {
	BTPTR root= new btnode;
	root=NULL;
	int size;
	size = 17;
	int a[]={20,8,4,0,0,12,10,0,0,14,0,0,0,0,7,9,0,0,0};
	root = create(a, size);
	cout<<"\nThe inorder is: ";
	print(root);
	cout<<endl;
	hd_cal(root, 0);
	cout<<endl;
	int res[50], n=0;
	leftside(root, res, n);
	bottomside(root, res, n);
	n--;
	rightside(root->rc, res, n);
	for(int i=0; i<n; i++) cout<<res[i]<<" ";
	return 0;
}
