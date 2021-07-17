#include<iostream>

using namespace std;
struct node{
	int data;
	struct node* next;
};
typedef struct node* LPTR;
int  ele, pos=0;
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
void LLsearch(LPTR &head){
	if(head==NULL) return;
//	if(head->next==NULL){
//.	if(head->data==ele) return;
//	else {
//		pos=-1;
//		return;
//	}
//}
	if(head->data==ele){
		cout<<"pos = "<<pos+1;
	 return;
}
	pos++;
	LLsearch(head->next);
	
}
int main(){
	LPTR head, tail, L;
	head=NULL;
	tail=NULL;
	L=NULL;
	int ar[50], size;
	cout<<"Enter the number of elements: ";
	cin>>size;
	for(int i=0;i<size;i++){
		cout<<"\nEnter: ";
		cin>>ar[i];
		addEnd(head, tail, L, ar[i]);
	}
	cout<<"\nEnter the element to be searched: ";
	cin>>ele;
	
	LLsearch(head);
	if(pos!=-1) cout<<"\n"<<ele<<" found at position "<<pos+1;
	else cout<<"\nElement not found!";
	return 0;
	
}

