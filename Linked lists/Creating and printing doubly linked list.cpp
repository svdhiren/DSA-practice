#include<iostream>
using namespace std;
struct dlnode{
	int data;
	dlnode* left;
	dlnode* right;
};
typedef struct dlnode* DPTR;
int size;

 DPTR addnode(DPTR head, int ar[], int i){
 	if(i==size){
 		return NULL;
	 }
	 else{
	 	DPTR T=new dlnode;
	 	T->data=ar[i];
	 	T->left=NULL;
	 	T->right=NULL;
	 	if(head==NULL) head=T;
	 	else{
	 		head->right=T;
	 		T->left=head;
	 		head=T;
		 }
	 }
	 head->right=addnode(head, ar, ++i);
 	// return head;
 }
  void print(DPTR head){
  	if(head==NULL) return;
  	if(head->left!=NULL) cout<<head->data<<" < - "<<head->left->data;
  	else cout<<head->data<<" <- ";
  	print(head->right);
  	
  }

int main() {
	DPTR head;
	head=NULL;
	
	int a[50];
	cout<<"Enter the number of elements: ";
	cin>>size;
	for(int i=0;i<size;i++){
		cout<<"\nEnter: ";
		cin>>a[i];
	}
	head=addnode(head, a, 0);
	print(head);
	return 0;
	
}
