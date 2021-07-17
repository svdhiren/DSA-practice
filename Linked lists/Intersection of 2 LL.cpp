#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
typedef struct node* LPTR;
void addEnd(LPTR &head,LPTR &tail,LPTR &L,int x)	// Addition at the END
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

void show(LPTR L,LPTR head)	
{
if(head!=NULL)
{
L = head;
while(L->next != NULL)
{
cout << L->data << " ";
L = L->next;
}
cout << L->data;
}
else
cout << "\n LIST IS EMPTY";
}

int main(){
	LPTR resh, rest, h1, t1, h2, t2, L ;
	 resh=NULL;
	 rest=NULL;
	 h1=NULL;
	 t1=NULL;
	 h2=NULL;
	 t2=NULL;
	 L=NULL;
	 int size, num;
	 
	 cout<<"Enter the size of the first linked list: ";
	 cin>>size;
	 for(int i=0;i<size;i++){
	 	cout<<"\nEnter: "; cin>>num;
	 	addEnd(h1, t1, L, num);
	 }
	 cout<<"\nEnter the size of the second linked list: ";
	 cin>>size;
	 for(int i=0;i<size;i++){
	 	cout<<"\nEnter: "; cin>>num;
	 	addEnd(h2, t2, L, num);
	 }
	 LPTR tmp=h2;
	 
	 LPTR t;
	 
	 while(tmp!=NULL){
	 	t=h1; 
	 	while(t!=NULL){
	 		if(tmp->data==t->data) { addEnd(resh, rest, L, tmp->data);  break; }
	 		else t=t->next;
	 		
		 }
		
		 
		 tmp=tmp->next;
	 }
	 
	 
	 show(L, resh);
	 return 0;
}
