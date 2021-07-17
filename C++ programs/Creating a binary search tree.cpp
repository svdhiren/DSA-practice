#include<iostream>
using namespace std;
struct bstnode{
	bstnode* lchild;
	int data;
	bstnode* rchild;
};
typedef struct bstnode* BSTPTR;
void create_BST(BSTPTR T, BSTPTR root, BSTPTR tmp){
static int x;
if(tmp->data>T->data)  {
	if(T->rchild==NULL) {
		T->rchild=tmp;
		BSTPTR t= new bstnode;
	cout<<"\nEnter the number: ";
	cin>>x;
	if(x==-1) return;
	t->data=x;
	t->lchild=NULL;
	t->rchild=NULL;
	create_BST(root, root, t);
	}
	else create_BST(T->rchild, root, tmp );
}
else{
if(T->lchild==NULL) {
		T->lchild=tmp;
		BSTPTR t= new bstnode;
	cout<<"\nEnter the number: ";
	cin>>x;
	if(x==-1) return;
	t->data=x;
	t->lchild=NULL;
	t->rchild=NULL;
	create_BST(root, root, t);
	}
	else create_BST(T->lchild, root, tmp );	
}	
	}
	
	void printLDR(BSTPTR T) {
		if(T==NULL) return;
		printLDR(T->lchild);
		cout<<T->data<<" ";
		printLDR(T->rchild);
		}
	void printDLR(BSTPTR T){
		if(T==NULL) return;
		cout<<T->data<<" ";
		printDLR(T->lchild);
		printDLR(T->rchild);
		}
	void printLRD(BSTPTR T){
		if(T==NULL) return;
		printDLR(T->lchild);
		printDLR(T->rchild);
		cout<<T->data<<" ";
		}
		
	struct queue {
	int front;
	int rear;
	BSTPTR ele[25];
	int size;
};

void enque(queue &q,BSTPTR x) {
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
	
		BSTPTR temp=new bstnode;
		temp->data=-1;
		temp->lchild=NULL;
		temp->rchild=NULL;
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



void multilevelorder(BSTPTR T, queue &q) {
	
	if(q.rear==-1) return;
	else {
		cout<<T->data<<" ";
		if(T->lchild!=NULL) enque(q, T->lchild);
		if(T->rchild!=NULL) enque(q, T->rchild);
		T=dequeue(q);
		if(T->data==0){
			cout<<endl;
			enque(q, T);
			T=dequeue(q);
		}
	  multilevelorder(T, q);	
	}
}

void min_max(BSTPTR T, int &min, int &max){
	
	BSTPTR t=T;
	while(T->lchild!=NULL) T=T->lchild;
	min=T->data;
	while(t->rchild!=NULL) t=t->rchild;
	max=t->data;
}
	BSTPTR root= new bstnode;	
int main() {

	BSTPTR T=NULL;
	int num, min, max;
	cout<<"Enter the root number: ";
	cin>>num;
	root->data=num;
	root->lchild=NULL;
	root->rchild=NULL;
	BSTPTR tmp= new bstnode;
    cout<<"\nStart entering the child numbers: ";
	cin>>tmp->data;
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	create_BST(root, root, tmp);
	
//	cout<<"\nDamn!! "<<root->rchild->rchild->lchild->data;
//	cout<<"\nAgain damn!! "<<root->lchild->rchild->lchild->data;
//	cout<<"\nDaaamn!! "<<root->rchild->data;
	
	cout<<"\nElements in DLR order: ";
	printDLR(root);
	
	cout<<"\nElements in LDR order: ";
	printLDR(root);
	
	cout<<"\nElements in LRD order: ";
	printLRD(root);
	queue Q;
	Q.front=-1;
	Q.rear=-1;
	Q.size=20;
	for(int i=0; i<20; i++) {
		Q.ele[i]=new bstnode;
		Q.ele[i]=NULL;
	}
	cout<<endl;
	BSTPTR t = new bstnode;
	t->data=0;
	t->lchild=t->rchild=NULL;
	enque(Q, t);
	multilevelorder(root, Q);
	
	min_max(root, min, max);
	cout<<"\nMinimum = "<<min;
	cout<<"\nMaximum = "<<max;
	return 0;
	}
