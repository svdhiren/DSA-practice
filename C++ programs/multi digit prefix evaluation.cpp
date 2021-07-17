#include<iostream>
using namespace std;
union u {
	int num;
	char ch;
};
struct var {
	int flag;
	union u obj;
};
struct queue {
	int front;
	int rear;
	var ele[50];
	int size;
};
void enque(queue &q, var x) {
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

var dequeue(queue &q){
	var t;
	if(q.rear==-1){
		q.front=-1;
		cout<<"\nThe queue is empty. ";
		var del;
		del.flag=-1;
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
   
   int calc(char op, int x, int y) {
		
		switch(op) {
			case '+': return (y+x);
			case '-': return (y-x);
			case '*': return (y*x);
			case '/': return (y/x);
		}
	}
   
  void prefix(queue &q){
  struct var T1, T2, T3;	
while(1) 
{
if(q.ele[q.front].flag==1)
        enque(q, dequeue(q));
else{ 
T1=dequeue(q);
   if(q.ele[q.front].flag==0)  enque(q, T1);
   else{
	     T2=dequeue(q);
		 if(q.ele[q.front].flag==0)
		 {
		 	enque(q, T1);
		 	enque(q, T2);
		 } 
		 else {
		 	T3=dequeue(q);
		 	var result;
		 	result.flag=1;
		 	result.obj.num=calc(T1.obj.ch, T2.obj.num, T3.obj.num);
		 	if(q.rear==-1) { cout<<"\nThe result is = "<<result.obj.num; break; }
		 	else enque(q, result);
			 
		      }					   
       }
    }			   	  
}
  } //End of the function.

int main() {
	queue Q;
	Q.front=Q.rear=-1;
	cout<<"Enter the size of the prefix expression: ";
	cin>>Q.size;
	struct var ar[50];
	for( int i=0; i<Q.size;i++)
		{
    	cout<<"\nOperator or digit (1-digit/0-operator): ";
    	cin>>ar[i].flag;
    	if(ar[i].flag==0) 
		{
			cout<<"\nEnter the operator: ";
			cin>>ar[i].obj.ch;
		}
		else
		{
		    cout<<"\nEnter the number: ";
			cin>>ar[i].obj.num;	
		}
		enque(Q, ar[i]);
    	
	    }
	    
	 prefix(Q);
	 return 0;   
	    
	    
}


