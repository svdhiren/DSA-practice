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
  	if(head->left!=NULL) cout<<head->data<<" < - "<<head->left->data;
  	else cout<<head->data<<" <- ";
  	print(head->right);
  	
  }
  void triplets(DPTR head, int sum){
  	int a1=-1, a2=-1, a3=-1, s=sum;
  	  while(head->right->right!=NULL){
  	  	DPTR t=head;
  	  	sum=s;
  	  	while(t->data >= sum && t->right!=NULL) t=t->right;
  	  	if(t->data < sum) {
  	  		sum=sum-t->data;
  	  		a1=t->data;
			}
		else a1=-1;	
		while(t->data >= sum && t->right!=NULL) t=t->right;
  	  	if(t->data < sum && t->right!=NULL) {
  	  		sum=sum-t->data;
  	  		a2=t->data;
			}
		else a2=-1;
		while(t->data != sum )  t=t->right;
		if(t->data==sum) {
			a3=t->data;
			sum=sum-t->data;
		}
		if(sum==0 && a1!=-1 && a2!= -1 && a3!= -1) cout<<a1<<" "<<a2<<" "<<a3<<" \n";
  	  	head=head->right;
			
		}
  }
  

int main() {
	DPTR head;
	head=NULL;
	
	int a[50], sum;
	cout<<"Enter the number of elements: ";
	cin>>size;
	cout<<"\nEnter the elements in decreasing order: \n";
	for(int i=0;i<size;i++){
		cout<<"\nEnter: ";
		cin>>a[i];
	}
	head=addnode(head, a, 0);
	cout<<"\nEnter the sum: ";
	cin>>sum;
	triplets(head, sum);
	
	return 0;
	
}
