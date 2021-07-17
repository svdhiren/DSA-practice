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

int maxi(BSTPTR T){
	if(T==NULL) return -1;
	
	else if(T->rc==NULL) return T->data;
	
	else return(maxi(T->rc));
}

void delete_node(BSTPTR T, int k, BSTPTR P){
	
	if(k < T->data) delete_node(T->lc, k, T);
	else if(k > T->data) delete_node(T->rc, k, T);
	else {
	int max = maxi(T->lc);
	if(max==-1) {
		if(P->lc==T) P->lc=NULL;
		else P->rc=NULL;
	}
	else{
		T->data=max;
		delete_node(T->lc, max, T);
	}
         }
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
	cout<<"\nEnter the element to be deleted: ";
	cin>>k;
	delete_node(root, k, NULL);
	cout<<"\n"<<root->lc->data;
 //   cout<<"\nThe maximum on the left subtree of 8 is: "<<maxi(root->lc);
    cout<<"\nTHe  new inorder of the BST is : ";
	print(root);
	return 0;
}
