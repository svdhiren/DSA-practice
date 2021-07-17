#include<iostream>
#include<ctype.h>
using namespace std;
struct stack{
		int size;
		char ele[50];
		int top;
	
	};
	void push(stack &s, char x){
		if(s.top!=s.size-1) s.ele[++s.top]=x;
		else cout<<"Stack overflow!";
		
	}
	char pop(stack &s) {
      if(s.top!=-1)
        return(s.ele[s.top--]);
      else {
      	cout<<"Stack is empty";
      	return (-1);
	  }
	}
	char peek(stack s) {
		return s.ele[s.top];
	}
	void prt_stack(stack s) {
		for(int i=0;i<=s.top;i++) cout<<s.ele[i];
		cout<<endl;
	}
	int main() {
		stack s1;
		s1.top=-1;
		char ar[50], ans[50], c;
		int i, k=0, flag=1, j;
		cout<<"Enter the size of the expression";
		cin>>s1.size;
		cout<<"\nEnter the expression: ";
		for(i=0;i<s1.size;i++) cin>>ar[i];
		for(j=1;j<=s1.size+1;) {
			if(j==1)  {   push(s1, j); prt_stack(s1);j++; }
			else {
				    if(peek(s1)==ar[k]){
				    	 c=pop(s1);
				    	 prt_stack(s1);
				    	 ans[k]=c;
				    	 k++;
				        
					                   }
					else {
						push(s1, j);j++;
						
						prt_stack(s1);
					     }                
			     }
		                       }
		for(i=0; ; i++){
			if(ans[i]!=ar[k])  { flag=-1; break ; }
		}      
		if(flag==-1) cout<<"\nThe given sequence is not achievable.";
		else cout<<"\nThe given sequence is achievable. ";
		return 0;                 
		
	           }
