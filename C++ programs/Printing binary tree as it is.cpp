#include<iostream>
using namespace std;
struct btnode {
	int data;
	btnode* lc;
	btnode* rc;
	int x;
	int y;
};
typedef struct btnode* BTPTR;
BTPTR create(int ar[], int n){
	static int i=0;
	if(i==n || ar[i]==0)
	{
		return NULL;
	}
	BTPTR T= new btnode;
	T->data=ar[i];
	T->lc=T->rc=NULL;
	i++;
	T->lc=create(ar, n);
	i++;
	T->rc=create(ar,  n);
	
	return T;
}

void x_axis(BTPTR T){
	static int l=0;
	if(T==NULL)
	x_axis(T->lc);
	T->x=l++;
	x_axis(T->rc);
}

struct queue {
	int front;
	int rear;
	BTPTR ele[25];
	int size;
};
 void enque(queue &q,BTPTR x) {
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

BTPTR dequeue(queue &q){
	BTPTR t;
	if(q.rear==-1){
		q.front=-1;
	
		BTPTR temp=new btnode;
		temp->data=-1;
		temp->lc=NULL;
		temp->rc=NULL;
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

 
  void multilevelorder(BTPTR T, queue &q) {
	
	if(q.rear==-1) return;
	else {
		cout<<T->data<<" ";
		if(T->lc!=NULL) enque(q, T->lc);
		if(T->rc!=NULL) enque(q, T->rc);
		T=dequeue(q);
		if(T->data==0){
			cout<<endl;
			enque(q, T);
			T=dequeue(q);
		}
	  multilevelorder(T, q);	
	}
}

void print(BTPTR t){
	if(t==NULL) return;
	cout<<t->data<<" ";
	print(t->lc);
	print(t->rc);
}




int main() {
	BTPTR root= new btnode;
	root=NULL;
	int a[50];
	int size;
	cout<<"Enter the size of the expression: ";
	cin>>size;
	cout<<"\nEnter preorder serialization expression: ";
	for(int i=0; i<size; i++) cin>>a[i];
	root=create(a, size);
	x_axis(root); // function to calculate the distance along x axis.
	
	//Statements to print multi level order.
	queue Q;
	Q.front=-1;
	Q.rear=-1;
	Q.size=30;
	for(int i=0; i<30; i++) {
		Q.ele[i]=new btnode;
		Q.ele[i]=NULL;
	}
	BTPTR t = new btnode;
	t->data=0;
	t->lc=t->rc=NULL;
	enque(Q, t);
	multilevelorder(root, Q); 
	
}
