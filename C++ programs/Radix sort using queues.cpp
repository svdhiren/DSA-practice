#include<iostream>
#include<cmath>
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
void radsort(int ar[], int n) {
	queue Q[10];
	int temp , tmp[50];
	for(int i=0;i<n;i++) tmp[i]=ar[i];
	for(int i=0;i<10;i++)  {
	 Q[i].front=Q[i].rear=-1; 
	 Q[i].size=n;
}
	
	for(int j=1;j<=3;j++) {    // loop runs three times for a 3-digit number.
		for(int i=0;i<n;i++) {
			temp=tmp[i]%10;
			enque(Q[temp], ar[i]);
			
			
			
		}
		int t, k=0, l=0;
			while(l<10){
				t=dequeue(Q[l]);
				if(t!=-1) { ar[k]=t; tmp[k]=ar[k]; tmp[k]/=pow(10,j); k++;}
				else l++;
			}
	}
	
  }
  int main() {
  	
  	int a[50], i, n;
  	cout<<"Enter the size of the array: ";
  	cin>>n;
  	cout<<"\nEnter the array elements: ";
  	for(i=0;i<n;i++) cin>>a[i];
  	radsort(a, n);
  	cout<<endl;
  	for( i=0; i<n;i++) cout<<a[i]<<" ";
  	return 0;
  }
