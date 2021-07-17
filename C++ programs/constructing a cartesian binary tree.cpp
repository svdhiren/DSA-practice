#include<iostream>
using namespace std;
struct btnode {
	int data;
	btnode* lc;
	btnode* rc;
};
typedef struct btnode* BTPTR;
BTPTR newnode(int k){
	BTPTR tmp = new btnode;
	tmp->data=k;
	tmp->lc=tmp->rc=NULL;
	return tmp;
}
BTPTR construct(int ar[], int l, int h){
	
	if(l > h) return NULL;
	int j, i, max=-1;
	for(j=l; j<=h; j++){
		if(ar[j] > max) {
			max=ar[j];
			i=j;
		}
	}
	BTPTR T = newnode(max);
	T->lc = construct(ar, l, i-1);
	T->rc = construct(ar, i+1, h);
	
	return T;
}

void print(BTPTR t){
	if(t==NULL) return;
	print(t->lc);
	cout<<t->data<<" ";
	print(t->rc);
}

int main() {
	int a[30], size;
	cout<<"Enter the number of elements: ";
	cin>>size;
	cout<<"\nEnter the elements: ";
	for(int i=0; i<size; i++) cin>>a[i];
	BTPTR root = NULL;
	root = construct(a, 0, size-1);
	cout<<endl;
	print(root);
	return 0;
}
