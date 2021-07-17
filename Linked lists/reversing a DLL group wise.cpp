#include<iostream>
using namespace std;
struct dlnode{
	int data;
	dlnode* left;
	dlnode* right;
};
typedef struct dlnode* DPTR;
int t=1, k, size;

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
  	print(head->right);
  	
  }
  DPTR rev_group(DPTR prev, DPTR cur, DPTR next, DPTR tmp, DPTR head){
  	
	  if(tmp==NULL) {
	  	
	  	while(t%k!=0){
	  		next=cur->left;
	  		cur->left=prev;
	  		cur->right=next;
	  		prev=cur;
	  		cur=next;
	  		t++;
		  }
		  cur->left=prev;
		  cur->right=NULL;
		  return head;
	  }
  	
	  static int count =1;
  	if(count==1) {
  		for(int i=1; i<k;i++) cur=cur->right;
  		head=cur;
  		tmp=cur->right;
  		count++;
	  }
  	
  	if(t%k==0){
  		cur->left=prev;
  		prev=cur;
  		cur=tmp;
  		for(int i=1; i<k;i++) cur=cur->right;
  		prev->right=cur;
  		t++;
  		tmp=cur->right;
  		}
  	else{
  		next=cur->left;
  		cur->left=prev;
  		cur->right=next;
  		prev=cur;
  		cur=next;
  		t++;
	  }	
	  return rev_group(prev, cur, next, tmp, head);
  	
  }

int main() {
	DPTR head;
	head=NULL;
	
	int a[50];
	
	cout<<"Enter the size of the group: ";
	cin>>k;
	cout<<"\nEnter the number of elements in multiples of "<<k<<": ";
	cin>>size;
	for(int i=0;i<size;i++){
		cout<<"\nEnter: ";
		cin>>a[i];
	}
	head=addnode(head, a, 0);
	head=rev_group(NULL, head, NULL, head, head);
	cout<<endl;
	print(head);


	return 0;
	
}
