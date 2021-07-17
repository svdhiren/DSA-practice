#include<iostream>
using namespace std;
struct bstnodeinfo {
	int data;
	bstnodeinfo* lchild;
	bstnodeinfo* rchild;
	int min, max;
};
typedef struct bstnodeinfo* BSTPTR;
struct queue {
	int front;
	int rear;
	BSTPTR ele[50];
	int size;
};
void enque(queue &q, BSTPTR x) {
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
BSTPTR dequeue(queue &q){
	BSTPTR t;
	if(q.rear==-1){
		q.front=-1;
		cout<<"\nThe queue is empty. ";
		t= new bstnodeinfo;
		t->data=-1;
		t->min=t->max=0;
		t->lchild=NULL;
		t->rchild=NULL;
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
void printLDR(BSTPTR T){
	if(T==NULL) return;
	printLDR(T->lchild);
	cout<<T->data<<"  ";
	printLDR(T->rchild);
}

 void construct_level_order(queue &q, int ar[], int n){
    int i=1;
 	BSTPTR T;
 	while(q.rear!=-1 && i!=n){
 		T=dequeue(q);
 		if((ar[i] >= T->min) && (ar[i] < T->data))
		 {
 			BSTPTR tmp= new bstnodeinfo;
 			tmp->data=ar[i];
 			tmp->min=T->min;
 			tmp->max=T->data - 1;
 			tmp->lchild=tmp->rchild=NULL;
 			enque(q, tmp);
 			T->lchild=tmp;
 			i++;
		 }
		
		if((ar[i] <= T->max) && (ar[i] > T->data) && i!=n)
		{
			BSTPTR tmp= new bstnodeinfo;
 			tmp->data=ar[i];
 			tmp->min=T->data+1;
 			tmp->max=T->max;
 			tmp->lchild=tmp->rchild=NULL;
 			enque(q, tmp);
 			T->rchild=tmp;
 			i++;
		} 
	 }
 }

int main() {
  queue Q;
  Q.front=Q.rear=-1;
  Q.size=30;
  int a[50], size;
  cout<<"Enter the number of elements: ";
  cin>>size;
  for(int i=0;i<size;i++){
  	cout<<"\nEnter: ";
  	cin>>a[i];
  }
  BSTPTR root = new bstnodeinfo;
  root->data=a[0];
  root->min=0;
  root->max=1000;
  root->lchild=NULL;
  root->rchild=NULL;
  enque(Q, root);
  construct_level_order(Q, a, size);
  printLDR(root);
  return 0;
}


