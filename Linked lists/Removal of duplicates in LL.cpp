#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
typedef struct node* LPTR;
void addend(LPTR &head,LPTR &tail,LPTR &L,int x)	// Addition at the END
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

void display(LPTR L,LPTR head)	
{
	cout<<endl;
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
	L=NULL;
	head=NULL;
	tail=NULL;
	int size, num;
	cout<<"Enter the number of elements: "; cin>>size;
	for(int i=0;i<size;i++) {
		cout<<"\nEnter: ";
		cin>>num;
		addend(head, tail, L, num);
		display(L, head);
	}
	LPTR J;
	for(LPTR I=head;I!=NULL; I=I->next){
		for( J=I->next;J!=NULL;J=J->next){
			cout<<"J= "<<J->data;
			cout<<"I= "<<I->data;
			if(J->data==I->data) {
				
				LPTR t, tmp;
				t=I->next;
				while(t->next->data!=J->data  &&  t->next->next!=NULL)   t=t->next;
				t->next=J->next;
				tmp=J;
				delete tmp;
				display(L, head);
			}
			
		}
		
	}
	
	display(L, head);
	return 0;
}

