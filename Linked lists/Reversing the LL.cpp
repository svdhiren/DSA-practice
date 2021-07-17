#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
typedef struct node* LPTR;

void addEnd(LPTR &head,LPTR &tail, int x)	// Addition at the END
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

void revLL(LPTR &head, LPTR &tail){
	LPTR T, tmp;
	T=tail;
	while(1){
		tmp=head;
		while(tmp->next!=T) tmp=tmp->next;
		T->next=tmp;
		T=tmp;
	if(T==head) {
		T->next=NULL;
		break;
	}	
	}
head=tail;
tail=tmp;	
}
int main() {
	LPTR L, head, tail;
	head=NULL;
	tail=NULL;
	L=NULL;
	int ar[50], size;
	cout<<"Enter the number of elements: ";
	cin>>size;
	for(int i=0;i<size;i++) {
		cout<<"\nEnter: ";
		cin>>ar[i];
		addEnd(head, tail, ar[i]);
	}
	cout<<"\nThe LL before reversal is: ";
	show(L, head);
	revLL(head, tail);
	cout<<"\nThe LL after reversal is: ";
	show(L, head);
	return 0;
}
