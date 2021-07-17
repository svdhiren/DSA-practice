#include<iostream>
using namespace std;

 struct mlnode{
	int data;
	mlnode* dlink;
	mlnode* next;
};
typedef struct mlnode* MLPTR;

MLPTR enter(MLPTR head, int k){
static int num;
	if(k==0){
	
		cout<<"\nEnter next: "; cin>>num;
		MLPTR T = new(struct mlnode);
		T->data=num;
		T->dlink=NULL;
		T->next=NULL;
		if(head==NULL) head=T;
		else{
			
			head->next=T;
			head=head->next;
		}
		}
	else if(k==1){
		
		cout<<"\nEnter down: ";
		cin>>num;
		MLPTR t=new(struct mlnode);
		t->data=num;
		t->dlink=NULL;
		t->next=NULL;
		head->dlink=t;
		head=head->dlink;
	
	}
	else if(k==2) return NULL;
	int ch;
	cout<<"\n\nWhat? 0-next 1-down,2-nothing for "<<head->data<<" : ";
	cin>>ch;
	if(ch==2) head->next = enter(head,ch);
	else{
	
		if(ch==1)	{
					head->dlink=enter(head, ch);
					cout<<"\n\nWant to enter next for "<<head->data<<" : ";
					cin>>ch;
				}
		head->next = enter(head, ch);
	}
		
}	
struct queue {
	int front;
	int rear;
	MLPTR ele[50];
	int size;
};
queue Q;

void enque(queue &q,MLPTR x) {
	if(q.front==q.rear && q.front==-1) {
		q.front=q.rear=0;
		q.ele[0]=x;
	}
	else{
		if(q.rear+1!=q.size)
		q.ele[++q.rear]=x;
		else
		cout<<"\nQueue is full. ";
	}
}

MLPTR dequeue(queue &q){
	MLPTR t;
	if(q.rear==-1){
		q.front=-1;
	
		MLPTR temp=new mlnode;
		temp->data=-1;
		temp->dlink=NULL;
		temp->next=NULL;
		return temp;
	}
	
	else{
		if(q.rear>=0){
			 t=q.ele[0];
			for(int i=0;i<q.rear;i++)
			     q.ele[i]=q.ele[i+1];
			     q.rear--;
		}
	}
	return t;
	
}
MLPTR p=NULL;
 void print(MLPTR head, queue q){
 
 
 cout<<"yoo";
 	if(head->dlink!=NULL){
 		enque( q, head->dlink);
	 }
	if(head->next==NULL){
		cout<<head->data<<" ";
		p=dequeue(q);
		
	if(p->data!=-1)	{  print(p,q );}
	else return;
	} 
	else cout<<head->data<<" ";
	print(head->next, q);
 }


int main() {
	MLPTR head;
	Q.front=Q.rear=-1;
Q.size=25;
for(int i=0; i<25;i++) {
	if(i==0)
	{
		cout << "\n YO0";
		
	Q.ele[i]=new mlnode;
    Q.ele[i]->data = 0;
			cout << "\n initialised";
		}
else	Q.ele[i]=NULL;
}
	head=NULL;
	head = enter(head,0);
	cout << "\n back to main";
//
	print(head, Q);
	return 0;
	
}
