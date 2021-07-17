#include<iostream>
using namespace std;
int size;
struct node{
	int data;
	struct node* next;
};
typedef struct node* LPTR;

void addEnd(LPTR &head,LPTR &tail, int ar[], int i)	// Addition at the END
{
LPTR T = new(struct node);
// Base case
if(i==size) return;
if(head==NULL) {
T->data = ar[i];
T->next = NULL;
head = T;
tail=T;
addEnd(head, T, ar, ++i);
}

T->data=ar[i];
T->next=NULL; 
tail->next = T;
tail=T;
addEnd(head, tail, ar, ++i);
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
	LPTR tail, head, L;
	head=NULL;
	tail=NULL;
	L=NULL;
	int ar[50];
	cout<<"Enter the number of elements: ";
	cin>>size;
	for(int i=0;i<size;i++) {
		cout<<"\nEnter: ";
		cin>>ar[i];
	}
	addEnd(head, tail, ar, 0);
	cout<<endl;
	show(L, head);
	return 0;
}
