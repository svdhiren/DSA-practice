#include<iostream>
#include<cmath>
 int ar[50];
int k=0;
using namespace std;
struct e {
	int n;
	char r;
};
struct queue{
	int front;
	int rear;
	e ele[50];
	int size;
};
void enqueue(queue &q, e x) {
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
e dequeue(queue &q) {
	e t;
	if(q.rear==-1) {
		q.front=-1;
		e el;
		el.n=-1;
		return el;
		
	}
	else {
		if(q.rear>=0){
			 t=q.ele[0];
			for(int i=0;i<q.rear;i++)
			     q.ele[i]=q.ele[i+1];
			     q.rear--;
	}
	return t;
}
}
void conv(int num, char ch) {
	if(num==0) return;
	if(ch=='p') {
		int len=0;
		int n=num;
		while(n!=0) {
			len++;
			n/=10;
		}
		len--;
		n=num;
		for(int t; len>=0;len--){
			int p=pow(10, len);
			t=n/p;
			n=n%p;
			switch(t){
				case 0 : cout<<"Zero "; break;
				case 1 : cout<<"One "; break;
				case 2 : cout<<"Two "; break;
				case 3 : cout<<"Three "; break;
				case 4 : cout<<"Four "; break;
				case 5 : cout<<"Five "; break;
				case 6 : cout<<"Six "; break;
				case 7 : cout<<"Seven "; break;
				case 8 : cout<<"Eight "; break;
				case 9 : cout<<"Nine "; break;
			}
		}
	}
else{
	int rad;
	if(ch=='b') rad=2;
	else if(ch=='o')rad=8;
	else if(ch=='h') rad=16;
	if(num%rad>=10) ar[k++]=char(rad+55);
	else ar[k++]=num%rad;
	num/=rad;
	conv(num, ch);
	
}	
return ;
}
int main() {

	queue Q;
	Q.front=Q.rear=-1;
	e inp;
	cout<<"Enter the size of the queue: ";
	cin>>Q.size;
	for(int i=0; i<Q.size;i++) {
		cout<<"\nEnter the first element:  ";
		cin>>inp.n;
		cout<<" ";
		cin>>inp.r;
		enqueue(Q, inp);
	}
	char ch='y';
	while(ch=='y'){
		e x;
		cout<<endl;
		x=dequeue(Q);
		conv( x.n, x.r);
		int i=0;
		if(x.r!='p') for(;i<Q.size; i++) {
			cout<<ar[i]<<" ";
		}
		cout<<"\nMore?";
		cin>>ch;
	}
	return 0;
}











