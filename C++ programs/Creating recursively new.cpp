#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
typedef struct node* LPTR;
LPTR Addend(){
	static int x;
	cout<<"\nEnter : ";
	cin>>x;
	if(x==-1) return NULL;
	LPTR head=new node;
	head->data=x;
	head->next=Addend();
	return head;
	
}

void display( LPTR head){
	if(head==NULL)
	   return;
	else{
		cout<<head->data<<" -> ";
		display(head->next);
	}   
}
int main(){
   LPTR h=NULL;
   h=Addend();
   display(h);
   return 0;
}
