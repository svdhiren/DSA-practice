#include<iostream>
using namespace std;
struct queue {
	int rear;
	int front;
	int ele[100];
	int size;
};
void enqueue(queue &q, int ar[], int n){
	if(q.rear==-1 && q.rear==q.front){
		q.front=0;
		q.ele[0]=n;
		for(int i=1;i<=n;i++) q.ele[i]=ar[i-1];
		q.rear=n;
		
	}
	else{
		if(q.rear+n+1 > q.size-1) cout<<"\nQueue overflow!";
		else{
			int i=q.rear+1;
			q.ele[i] = n;
			for(int j=i+1;j<=n+i;j++) q.ele[j]=ar[j-(i+1)];
			q.rear+=n+1;
			
		}
	}
}

void dequeue(queue &q, int ar[], int &n){
	if(q.rear==-1){
		q.front=-1;
		cout<<"\nThe queue is empty...";
	}
	else{
		n=q.ele[0];
		for(int i=1;i<=n;i++) ar[i-1]=q.ele[i];
		for(int i=0; i+n+1<=q.rear;i++){
			q.ele[i]=q.ele[i+n+1];
		}
		q.rear-=n+1;
		
	}	
	}


int main() {
	queue q;
	q.rear=q.front=-1;
	cout<<"Enter the total size of the queue: ";
	cin>>q.size;
	int ar[50], n, m;
	cout<<"Enter the number of arrays: ";
	cin>>m;
	cout<<"Start entering...";
	for(int i=0;i<m;i++){
		cout<<"\nEnter the number of elements of array "<<i+1<<" : ";
		cin>>n;
		for(int j=0;j<n;j++) {
			cout<<"Enter: ";
			cin>>ar[j];
		}
		enqueue(q, ar, n);
		
	}
//	for(int i=0;i<10;i++) cout<<q.ele[i]<<" ";
	cout<<"The dequeued arrays are: \n";
	for(int i=0;i<m;i++){
		dequeue(q, ar, n);
		for(int j=0;j<n;j++) cout<<ar[j]<<" ";
		cout<<endl;
	}
	return 0;
}
