#include<iostream>
using namespace std;
struct mlnode{
	int data;
	int count;
	mlnode* ptr[5];
};
typedef struct mlnode* MLPTR;

struct queue {
	int front;
	int rear;
	MLPTR ele[50];
	int size;
};
void enque(queue &q, MLPTR x) {
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
		MLPTR del= new mlnode;
		del->data=-1;
		return del;
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


MLPTR newnode(int d, int ct){
	MLPTR t=new mlnode;
	t->data=d;
	t->count=ct;
	for(int i=0;i<5;i++) t->ptr[i]=NULL;
	return t;
}
MLPTR create(int c) {
	static int num;
	static int ctr;
	if(c==0) return NULL;
	cout<<"\nEnter the data: "; cin>>num; 
	cout<<"\nEnter the number of pointers: "; cin>>ctr;
	MLPTR head=newnode(num, ctr);
	if(ctr==0) head->ptr[0]=create(head->count);
	for(int i=0; i<head->count; i++){
		cout<<"\nEnter the branch "<<i+1<<" of the node containing "<<head->data;
		head->ptr[i]=create(head->count);
	}
	     
	     
	     return head;  //Program control will reach here only after all branches have been created.
	}
	
	

	void print(MLPTR t, int ar[], int n , queue &Qu){
	
		if(t==NULL){
			for(int i=0; i<n; i++) cout<<ar[i]<<" ";
			cout<<endl;
			return;
		}
		if(t->count > 1) 
		    for(int i=1; i < t->count; i++) enque(Qu, t->ptr[i]);
		
		ar[n++]=t->data;
		print(t->ptr[0], ar, n, Qu);
		if(t->count < 2) return;
		if(Qu.rear==-1) return;
		MLPTR tmp=dequeue(Qu);
		print(tmp, ar, n, Qu);    
		
	}
	int main() {
		MLPTR head=NULL;
		queue Q;
		Q.front=Q.rear=-1;
		Q.size=30;
		cout<<"Start entering the numbers: \n";
		head=create(1);
		cout<<"\n"<<head->ptr[0]->ptr[0]->ptr[0]->ptr[1]->data;
		cout<<endl;
		int a[50];
		print(head, a, 0, Q);
		return 0;
	}
