#include<iostream>
using namespace std;
struct node{
      int data;
      node* next;
};


typedef struct node* LPTR;
int size;
 LPTR addnode(LPTR head, int ar[], int i) {
    if(i==size)
        return NULL;
    LPTR T= new node;
    T->data=ar[i];
T->next=NULL;
if(head==NULL) head=T;
else{ head->next=T;
   head=T;}
head->next=addnode(head, ar, ++i);

  }

void merge(LPTR h1, LPTR t) {
    static LPTR tmp;
   if(h1==NULL || t==NULL)
      {
      	h1->next=NULL;
      	return;
	  }
    if(h1->next->data > t->data){ 
       cout<<"\nh1= "<<h1->data;
       cout<<"\nt= "<<t->data;
	   tmp=t;
       t=h1->next;
       h1->next=tmp;
       h1=tmp;
        merge(h1, t);   
              }
if(h1->next->data < t->data){
   cout<<"\nh1= "<<h1->data;
       cout<<"\nt= "<<t->data;
    h1=h1->next;
    merge(h1, t);
	}
	
}

void print(LPTR head){
if(head==NULL) return;
cout<<head->data<<" ";
print(head->next);

}
int main() {
LPTR head1=NULL;
LPTR head2=NULL;
LPTR tmp=NULL;
int a[20];
cout<<"Enter the size of the first linked list(smaller): ";
cin>>size;
for(int i=0; i<size;i++){
cout<<"\nEnter: ";
cin>>a[i];
}
head1=addnode(head1, a, 0);
 cout<<"Enter the size of the second linked list(same or bigger): ";
cin>>size;
for(int i=0; i<size;i++){
cout<<"\nEnter: ";
cin>>a[i];
} 
head2=addnode(head2, a, 0);

merge(head1,head2);
cout<<endl;
print(head1);




return 0;

}
