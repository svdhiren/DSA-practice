#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
typedef struct node* LPTR;
int size;

LPTR addnode( int ar[], int i) {
    if(i==size)  return NULL;
    LPTR head= new node;
         head->data=ar[i];
         head->next=addnode(ar, ++i);
         return head; //  Control reaches here only after all the nodes get created.
}
  
  void print(LPTR head){
if(head==NULL) return;
cout<<head->data<<" ";
print(head->next);
}

 void change_link(LPTR head){
	int count=1;
	LPTR t=head;
	LPTR tmp=head;
    LPTR L;
	while(count<size/2){
		 L=tmp;
		for(int i=count;i<=size-count;i++) L=L->next;
		
		tmp=tmp->next;
		t->next=L;
		t=L;
	//	cout<<"t= "<<t->data<<" ";
		t->next=tmp;
		t=tmp;
//		cout<<"t= "<<t<<"\n ";
		count++;
	}
	tmp->next->next=NULL;
	
	
}

int main(){
	LPTR head;
	head=NULL;
	int a[50];
	cout<<"Enter the size of the linked list: ";
cin>>size;
for(int i=0; i<size;i++){
cout<<"\nEnter: ";
cin>>a[i];
}
head=addnode(a, 0);
print(head);
change_link(head);
cout<<endl;
print(head);
//cout<<"\n"<<head->next->next->data;
return 0;

}
