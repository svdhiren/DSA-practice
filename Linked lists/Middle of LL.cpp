#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
typedef struct node* LPTR;

void addEnd(LPTR &head,LPTR &tail,int x)	// Addition at the END
{
LPTR T = new(struct node);

if(head==NULL)
{
T->data = x;
T->next = NULL;
head = T;
tail = T;
}
else
{
T->data=x;
T->next=NULL; 
tail->next = T;
tail = T;
}

}

void midLL(LPTR s, LPTR f){
   if(f->next==NULL){
   	cout<<"\nMiddle element is: "<<s->data;
   	return;
   }
    else if(f->next->next==NULL){
   	cout<<"\n Middle elements are: "<<s->data<<" and "<<s->next->data;
   	return;
   }
   
   midLL(s->next, f->next->next);
}

int main(){
	LPTR head, tail;
	head=NULL;
	tail=NULL;
	int ar[50], size;
	cout<<"Enter the number of elements: ";
	cin>>size;
	for(int i=0;i<size;i++){
		cout<<"\nEnter: ";
		cin>>ar[i];
		addEnd(head, tail, ar[i]);
	}
	midLL(head, head);
	return 0;
}
