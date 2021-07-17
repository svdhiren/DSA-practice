#include<iostream>
#include<ctype.h>
using namespace std;
struct stack{
		int size;
		int ele[50];
		int top;
	
	};
	void push(stack &s, int x){
		if(s.top!=s.size-1) s.ele[++s.top]=x;
		else cout<<"Stack overflow!";
		
	}
	int pop(stack &s) {
      if(s.top!=-1)
        return(s.ele[s.top--]);
      else {
      	cout<<"Stack is empty";
      	return (-1);
	  }
	}
	int calc(char op, int x, int y) {
		
		switch(op) {
			case '+': return (y+x);
			case '-': return (y-x);
			case '*': return (y*x);
			case '/': return (y/x);
		}
	} 
	
	int main() {
		char ar[50];
		stack s1;
		s1.top=-1;
		int a, i, n1, n2, res;
		cout<<"Enter the size of the expression to be evaluated: ";
		cin>>s1.size;
		s1.size++;
		cout<<"\nEnter the expression: ";
		for( i=0;i<s1.size-1;i++) {
			cin>>ar[i];
		}
		ar[i]=')';
		for(i=0;i<s1.size;i++) {
			if(isdigit(ar[i])) {
				a=(int)ar[i]-48;
				push(s1, a);
					}
			else{ if(ar[i]!=')') {
			
				n1=pop(s1);
				n2=pop(s1);
				res=calc(ar[i], n1, n2);
				push(s1, res);
			}
			else cout<<"The result is "<<pop(s1);
				
			}		
		}
		
		
		
		return 0;
		
		
	}
