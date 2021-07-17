#include<iostream>
using namespace std;
struct bstnode {
	int data;
	bstnode *lc, *rc;
};
typedef struct bstnode* BSTPTR;
BSTPTR insert(BSTPTR T, int key) {
	if(T==NULL){
		BSTPTR Tmp = new bstnode;
		Tmp->data = key;
		Tmp->lc = Tmp->rc = NULL;
		return Tmp;
	}
	if( key < T->data) T->lc = insert(T->lc, key);
	else T->rc = insert(T->rc, key);
	return T;
}

void print(BSTPTR T){
	if(T==NULL) return;
	print(T->lc);
	cout<<T->data<<" ";
	print(T->rc);
}

int main(){
	BSTPTR root = NULL;
	cout<<"Enter the number of elements you want to enter: ";
	int n, k;
	cin>>n;
	cout<<"\nStart entering: \n";
	for(int i=0;i<n;i++){
		cout<<"Enter: ";
		cin>>k;
		root = insert(root, k);
	}
	cout<<"\nTHe inorder of the BST is: ";
	print(root);
	cout<<"\n"<<root->rc->lc->data<<endl;
	cout<<root->lc->lc->data;
	return 0;
}
