#include<iostream>
using namespace std;
struct kdnode {
	int data[10];
	kdnode* lc;
	kdnode* rc;
};
typedef struct kdnode* KDPTR;

KDPTR newnode(int a[], int d){
	KDPTR tmp = new kdnode;
	for(int i=0;i<d;i++) tmp->data[i]=a[i];
	tmp->lc=tmp->rc=NULL;
	return tmp;
}

void insert(KDPTR T, int ar[], int d, int l){
	if(ar[l] < T->data[l]){
		if(T->lc==NULL){
		     KDPTR tmp = newnode(ar, d);
		     T->lc=tmp;
		}
		else insert(T->lc, ar, d, (l+1)%d);
	}
	else{
		if(T->rc==NULL){
			KDPTR tmp = newnode(ar, d);
			T->rc=tmp;
		}
		else insert(T->rc, ar, d, (l+1)%d);
	}
}

bool search(KDPTR T, int key[], int d, int l){
	if(T==NULL) return false;
	if(key[l]==T->data[l]){
		for(int i=0; i<d; i++)
		     if(key[i] != T->data[i]) return false;
		return true;     
	}
	if(key[l] < T->data[l]) return search(T->lc, key, d, (l+1)%d);
	else return search(T->rc, key, d, (l+1)%d);
}

int main() {
	KDPTR root = NULL;
	int ar[20][10], d, size;
	cout<<"Enter the dimension of the Kd array: ";
	cin>>d;
	cout<<"Enter the number of element arrays in the Kd tree: ";
	cin>>size;
	cout<<"\nEnter the arrays: "<<"\n";
	for(int i=0;i<size;i++){
		cout<<"\nEnter array "<<i+1;
		for(int j=0;j<d;j++){
			cin>>ar[i][j];
		}
	  if(i==0){
	  	root = new kdnode;
	  	root->lc=root->rc=NULL;
	  	for(int k=0; k<d;k++) root->data[k]=ar[i][k];
	  }	
	  else{
	  	insert(root, ar[i], d, 0);
	  }
	}
	int key[10];
	cout<<"\nEnter the array you want to search: ";
	for(int i=0; i<d;i++) cin>>key[i];
	bool res = search(root, key, d, 0);
	if(res) cout<<"\nArray found!";
	else cout<<"\nArrrray not found!";
	return 0;
}
