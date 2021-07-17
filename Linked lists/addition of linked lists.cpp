#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};

typedef struct node* LPTR;
int size;
int sum[10], k=0;

LPTR addnode(LPTR head, int ar[], int i){
	if(i==size){
 		return NULL;
	 }
	 else{
	 	LPTR T=new node;
	 	T->data=ar[i];
	 	T->next=NULL;
	 	if(head==NULL) head=T;
	 	else{
	 		head->next=T;
	 		head=T;
		 }
	 }
	 head->next=addnode(head, ar, ++i);
}
void print(LPTR head){
  	if(head==NULL) return;
  	
  	cout<<head->data<<" ";
  	print(head->next);
  	
  }
  
 
	

	int co=0;
	void addition(LPTR h1, LPTR h2){
		
		if(h1==NULL) return;
		addition(h1->next, h2->next);
		sum[k++]=(h1->data + h2->data + co)%10;
		co=(h1->data + h2->data + co)/10;
	
	}
	
	int main() {
		LPTR head1, head2;
		head1=NULL;
		head2=NULL;
		int a[50];
		cout<<"Enter the number of digits: "; cin>>size;
		cout<<"\nEnter the elements of the first linked list: ";
		for(int i=0;i<size;i++) {
			cout<<"\nEnter: ";
			cin>>a[i];
		}
		head1=addnode(head1, a, 0);
		
		cout<<"\nEnter the elements of the second linked list: ";
		for(int i=0;i<size;i++) {
			cout<<"\nEnter: ";
			cin>>a[i];
		}
		head2=addnode(head2, a, 0);
		
		print(head1);
		cout<<endl;
		print(head2);
	    addition(head1, head2);
	   sum[k++]=(head1->data+head2->data+co)/10;
	    cout<<endl;
	    for(k--; k>=0;k--) cout<<sum[k];
	    return 0;
		
		}
	 ///
	
	
	
