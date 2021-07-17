#include<iostream>
using namespace std;
using namespace std;
struct node{
	int data;
	struct node* next;
};
typedef struct node* LPTR;
int size, k=0;

LPTR addnode(LPTR head, int ar[], int i) {
    if(i==size)
       {   return NULL;}
    LPTR T= new node;
    T->data=ar[i];
T->next=NULL;
if(head==NULL) head=T;
else{ head->next=T;
   head=T;}
head->next=addnode(head, ar, ++i);

  }
  
  void print(LPTR head){
if(head==NULL) return;
cout<<head->data<<" ";
print(head->next);

}

LPTR newnode(int x){
	LPTR t=new node;
	t->data=x;
	t->next=NULL;
	return t;
}
LPTR result=NULL;
void sorted(int k) {
	if(result==NULL)  result=newnode(k);
    else{
	     if(k < result->data)
      	  {
		LPTR tmp=newnode(k);
		tmp->next=result;
		result=tmp;
	      }
         else{
	             if(k > result->data && result->next==NULL)
				 {
		              LPTR tmp=newnode(k);
		              result->next=tmp;
	             }
	             else
				 {
	             	LPTR L=result;
	             	while(L->next!=NULL)
					 {
	             		if(k< L->next->data)
						 {
	             			LPTR tmp=newnode(k);
	             			tmp->next=L->next;
	             			L->next=tmp;
	             			return;
						 }
						 L=L->next;
					 }
					LPTR tmp = newnode(k);
					L->next=tmp; 
				 }
            }	
        }	
}

void traverse(LPTR T){
	if(T==NULL) return;
	sorted(T->data);
	traverse(T->next);
}
int main() {
	LPTR head;
	head=NULL;
	int a[50];
	cout<<"Enter the size of the linked list: ";
cin>>size;
for(int i=0; i<size;i++){
cout<<"\nEnter: ";
cin>>a[i];
}
head=addnode(head, a, 0);
traverse(head);
cout<<"\nThe linked list in sorted order is: ";
print(result);
return 0;
}
