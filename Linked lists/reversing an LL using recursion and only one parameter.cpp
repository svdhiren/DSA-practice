#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
typedef struct node* LPTR;

int size;
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
  
  LPTR revLL(LPTR prev, LPTR cur, LPTR after ){
  	if(cur==NULL)
  	return prev;
  	after=cur->next;
  	cur->next=prev;
  	prev=cur;
  	cur=after;
  return	revLL(prev, cur, after );
  	
  }
  
  int main() {
  	LPTR head=NULL;
  	int a[50];
	cout<<"Enter the number of elements: ";
	cin>>size;
	for(int i=0;i<size;i++){
		cout<<"\nEnter: ";
		cin>>a[i];
	}
	head=addnode(head, a, 0);
	print(head);
	cout<<endl;
	head=revLL(NULL, head, NULL);
	print(head);
	return 0;
  }
