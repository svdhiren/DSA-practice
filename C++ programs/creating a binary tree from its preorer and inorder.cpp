#include<iostream>
using namespace std;
struct btnode {
	char data;
	btnode* lc;
	btnode* rc;
	int x;
	int y;
};
typedef struct btnode* BTPTR;

BTPTR create(char pre[], char in[], int n, int l, int h){
	static int i=0;
	if(i==n || l > h) return NULL;
	BTPTR T=new btnode;
	T->data=pre[i];
	T->lc=T->rc=NULL;
	int j;
	for(j=l; j<=h; j++)
	     if(in[j]==pre[i]) break;
	i++;
	T->lc=create(pre, in, n, l, j-1);
	T->rc=create(pre, in, n, j , h);

	return T;
}

 void print(BTPTR t){
 	if(t==NULL) return;
 	cout<<t->data<<" ";
 	print(t->lc);
 	print(t->rc);
 }
 // Functions required for printing level order.
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
	static int k=0;
	if(q.rear==-1) return;
	else {
		for(int i=1; i<=(T->x - k); i++) cout<<"  ";
		cout<<T->data;
		k=T->x;
		if(T->lc!=NULL) enque(q, T->lc);
		if(T->rc!=NULL) enque(q, T->rc);
		T=dequeue(q);
		if(T->data=='*'){
			cout<<endl;
			enque(q, T);
			T=dequeue(q);
			k=0;
		}
	  multilevelorder(T, q);
	}
}

void x_axis(BTPTR T){
	static int l=1;
	if(T==NULL) return;
	x_axis(T->lc);
	T->x=l;
	l++;
	x_axis(T->rc);
}

void leftview(BTPTR T,int l, int &max){
	if(T==NULL) return ;
	if(l > max) {
		cout<<T->data<<" ";
        max=l;
	}

    leftview(T->lc, l+1, max);
	leftview(T->rc, l+1, max);
}

int main() {
	BTPTR root=NULL;
	int size=10;
	char p[]={'A','P','C','E','J','M','Q','K','D','G'};
	char inorder[]={'C','P','J','E','M','A','K','Q','G','D'};
	int low=0, high=size-1, i=0;  //Declared this just for understanding purpose.
	root=create(p, inorder, size, low, high);
	cout<<"\nThe preorder is: \n";
	//print(root);
	cout<<endl;
// Statements for printing level order.
	x_axis(root);
	queue Q;
	Q.front=-1;
	Q.rear=-1;
	Q.size=30;
	for(int i=0; i<30; i++) {
		Q.ele[i]=new btnode;
		Q.ele[i]=NULL;
	}
	BTPTR t = new btnode;
	t->data='*';
	t->lc=t->rc=NULL;
	enque(Q, t);
	//multilevelorder(root, Q);
    cout<<endl;
    int m=0;
   // leftview(root, 1, m);
//	cout<<root->lc->rc->lc->x<<endl;
//	cout<<root->rc->rc->lc->x;
	return 0;
}
