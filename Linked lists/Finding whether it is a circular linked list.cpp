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
if(head==NULL) {
	cout<<" NULL "; 
	return;
}
cout<<head->data<<" ";
print(head->next);

}

void findtail(LPTR &tail, LPTR head){
	
	while(head!=NULL){
	tail=head;
	head=head->next;
		}
		
}
LPTR t;
void findcircular(LPTR s, LPTR f, int i){
	if(f->next->next==NULL || f->next==NULL || s->next==NULL){
		cout<<"\nThe loop is not circular!";
		return;
	}
	if(s==f){
		 k++;
		if(k>=2){
	if(i==1) { t=f;cout<<"\nThe loop is circular ";}
	if(i==2) cout<<"\nThe point of loop is "<<s->data;
		return;
		
	}
}
	if(i==1) findcircular(s->next, f->next->next, 1);
	else findcircular(s->next, f->next, 2);

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
LPTR tail=NULL;
findtail(tail, head);
//cout<<head->data<<endl;
tail->next=head->next->next;
//cout<<tail->data<<endl;
//cout<<tail->next->data;
LPTR s, f;
s=head;
f=head;
findcircular(head, head, 1);

findcircular(head, t, 2);


return 0;
}

