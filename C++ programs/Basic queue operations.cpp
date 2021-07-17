// Basic operations on queues.
#include<iostream>
using namespace std;
struct queue {
	int front;
	int rear;
	int ele[50];
	int size;
};
void enque(queue &q, int x) {
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
int dequeue(queue &q){
	int t;
	if(q.rear==-1){
		q.front=-1;
		cout<<"\nThe queue is empty. ";
		return (-1);
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
int main() {
	queue Q;
	char ch='y';
	int a, n;
	Q.rear=Q.front=-1;
	cout<<"Enter the size of the queue: ";
	cin>>Q.size;
	do{
		cout<<"\n\n1. Insert. \n2. Delete. \n3. exit.";
		cin>>n;
		switch(n) {
			
		
case 1:	cout<<"\nEnter the element: "; cin>>a;
		enque(Q, a);
		cout<<endl;
		cout<<"The queue is now: ";
		for(int i=0; i<=Q.rear;i++) cout<<Q.ele[i]<<" ";
		break;
		
case 2: a=dequeue(Q);
        cout<<"\nThe deleted element is "<<a;
		cout<<"\nThe queue is now: ";
		for(int i=0; i<=Q.rear;i++) cout<<Q.ele[i]<<" ";
		break;
case 3: ch='n';		
		

}
		
	}while(ch=='y');
	return 0;
	
}
