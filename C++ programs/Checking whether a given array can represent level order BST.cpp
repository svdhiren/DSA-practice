#include<iostream>
using namespace std;


struct nodeinfo {
	int data;
	int min;
	int max;
};
struct queue {
	int front;
	int rear;
	nodeinfo ele[50];
	int size;
};
void enque(queue &q, nodeinfo x) {
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
nodeinfo dequeue(queue &q){
	nodeinfo t;
	if(q.rear==-1){
		q.front=-1;
		cout<<"\nThe queue is empty. ";
		t.data=-1;
		t.max=t.min=0;
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


int main( ){
	queue Q;
	Q.front=Q.rear=-1;
	Q.size=30;
	int size, ar[50], i;
	nodeinfo newnode, tmp;
	cout<<"Enter the size of the array: ";
	cin>>size;
	cout<<"\nEnter the elements: ";
	for( i=0; i<size;i++) cin>>ar[i];
    newnode.data=ar[0];
    newnode.max=INT_MAX;
    newnode.min=INT_MIN;
    enque(Q, newnode);
    i=1;
    while(i!=size && Q.rear!=-1){
    	tmp=dequeue(Q);
    	if(i<size && ar[i]<tmp.data && ar[i]>tmp.min) {
    		newnode.data=ar[i];
    		newnode.max=tmp.data;
    		newnode.min=tmp.min;
    		enque(Q, newnode);
    		i++;
		}
	 if(i<size && ar[i]>tmp.data && ar[i]<tmp.max){
		    newnode.data=ar[i];
		    newnode.min=tmp.data;
		    newnode.max=tmp.max;
		    enque(Q, newnode);
		    i++;
	}
	}
	if(i==size) cout<<"\nYes, this sequence is possible!";
	else cout<<"\nNooooo!";
	return 0;
	
	
	
}
