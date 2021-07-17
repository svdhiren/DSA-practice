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


void addFront(LPTR &head,LPTR &tail,int x)
{
LPTR T = new(struct node);
T->data = x;

if(head==NULL)
{
T->next=NULL;
head = T;
tail = T;	
}
else
{
T->next = head;
head = T;
}
}


int delAtFront(LPTR &head,LPTR &L,LPTR &tail)	// Deletion at the FRONT
{
int x;
if(head == NULL)
{
cout << "\n The list is already EMPTY";
x =-1;
}
else
{
if(head == tail)
{
x = head->data;
head = tail = NULL;
}
else
{
x = head->data;
head = head->next;
}
}
return x;
}

int delAtEnd(LPTR &head,LPTR &L,LPTR &tail)
{
int x;
if(head == NULL)
{
cout << "\n The list is already EMPTY";
return -1;
}
else
{
if(head == tail)
{
x = head->data;
head = tail = NULL;
}
else
{
L = head;
while(L->next->next != NULL)
L=L->next;
x = L->next->data;
cout << "x="<<x<<endl;
L->next = NULL;
tail = L;
}
}
return x;
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

int main() {
	LPTR L, head, tail;
	head=NULL;
	tail=NULL;
	L=NULL;
	int num, ch;
	do{
	 cout<<"\n1.add at end.\n2.add at front.\n3.delete at front.\n4.delete at end.\n5.exit";
	 cin>>ch;
	 switch(ch){
	 	case 1: cout<<"\nEnter the element to be added at the end: ";
	 	        cin>>num;
	 	        addEnd(head, tail, num);
	 	        show(L, head); break;
	 	case 2: cout<<"\nEnter the element to be added at the front: ";
	 	        cin>>num;       
	 	        addFront(head, tail, num);
	 	        show(L, head); break;
	 	case 3: num=delAtFront(head, L, tail);
		        cout<<"\nThe number deleted is: "<<num;
				show(L, head); break;
		case 4: num=delAtEnd(head, L, tail);
				 cout<<"\nThe number deleted is: "<<num;
				show(L, head);
				break;
		case 5: break;		       
	 }
	}while(ch!=5);
	return 0;
}















