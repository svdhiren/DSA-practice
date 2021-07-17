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
 	
 }
  void print(DPTR head){
  	if(head==NULL) return;
  	
  	cout<<head->data<<"  ";
  	print(head->left);
  	
  	
  }
  DPTR revDLL(DPTR prev, DPTR cur, DPTR next){
  	if(cur==NULL) return prev;
  	next=cur->right;
  	if(next!=NULL) next->left=NULL;
  	cur->right=prev;
  	cur->left=next;
  	prev=cur;
  	cur=next;
  	return   revDLL(prev, cur, next);
  	
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
	DPTR tail=revDLL(NULL,head,NULL);
	cout<<endl;
	print(head);


	return 0;
	
}
