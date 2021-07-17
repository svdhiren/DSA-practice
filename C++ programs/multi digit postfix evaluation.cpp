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
struct stack {
	int top;
	int size;
	int ele[50];
};
void push(stack &s, int x){
		if(s.top!=s.size-1) s.ele[++s.top]=x;
		else cout<<"Stack overflow!";
	}
int pop(stack &s) 
{
      if(s.top!=-1)
        return(s.ele[s.top--]);
      else return(-1);
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
	stack s1;
	s1.top=-1;
	cout<<"Enter the size of the expression: ";
    cin>>s1.size;
    int n1, n2, res, i;
    struct var ar[50];
	    for( i=0; i<s1.size;i++)
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
    	
	    }
	    s1.size++;
	    ar[i].flag=0;
	    ar[i].obj.ch=')';
	   
		for(i=0;i<s1.size;i++) {
			if(ar[i].flag==1) {
			  push(s1, ar[i].obj.num);
					}
			else{ if(ar[i].obj.ch!=')') {
			
				n1=pop(s1);
				n2=pop(s1);
				res=calc(ar[i].obj.ch, n1, n2);
				push(s1, res);
			}
			else cout<<"The result is "<<pop(s1);
				
			}		
		}
		return 0;
	}    

