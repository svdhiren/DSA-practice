#include<iostream>
using namespace std;
struct bstnode
{
	bstnode* lchild;
	int data;
	bstnode* rchild;
};
typedef struct bstnode* BSTPTR;
struct stack{
		int size;
		BSTPTR ele[50];
		int top;
	
	};
	void push(stack &s, BSTPTR x){
		if(s.top!=s.size-1) s.ele[++s.top]=x;
		else cout<<"Stack overflow!";
		
	}
	BSTPTR pop(stack &s) {
      if(s.top!=-1)
        return(s.ele[s.top--]);
      else {
      	
      	BSTPTR del=new bstnode;
      	del->data=-1;
      	del->lchild=del->rchild=NULL;
      	return del;
	  }
}
	  
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
		 t=new bstnode;
      	t->data=-1;
      	t->lchild=t->rchild=NULL;
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
	
	void zigzag(stack &s, queue &q, int flag){
		if(s.top==-1) return;
		while(s.top!=-1) enque(q, pop(s));
		int r=q.rear-q.front+1;
		for(int i=0;i<r;i++){
			BSTPTR T=dequeue(q);
			
			if(flag==0){
				
				if(T->lchild!=NULL) push(s, T->lchild);
				if(T->rchild!=NULL) push(s, T->rchild);
			}
			else{
				
				if(T->rchild!=NULL) push(s, T->rchild);
				if(T->lchild!=NULL) push(s, T->lchild);
			}
		enque(q, T);
		}
		while(q.front!=-1) {
			BSTPTR yo=dequeue(q);
			if(yo->data!=-1 )cout<<yo->data<<" ";
		}
		cout<<endl;
		if(flag==0) flag=1;
		else flag=0;
	   zigzag(s, q, flag);	
	}
	void printLDR(BSTPTR T) {
		if(T==NULL) return;
		printLDR(T->lchild);
		cout<<T->data<<" ";
		printLDR(T->rchild);
		}
	
	int main() {
	int num, flag=0;
	cout<<"Enter the root number: ";
	cin>>num;
	BSTPTR root=new bstnode;
	root->data=num;
	root->lchild=NULL;
	root->rchild=NULL;
	BSTPTR tmp= new bstnode;
    cout<<"\nStart entering the child numbers: ";
	cin>>tmp->data;
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	create_BST(root, root, tmp);
	stack s1;
	s1.top=-1;
	s1.size=30;
	queue Q;
	Q.front=Q.rear=-1;
	Q.size=30;
	cout<<endl;
	printLDR(root);
	cout<<"\n\n";
	push(s1, root);
	zigzag(s1, Q, flag);
	return 0;
}

	
	
	
	
