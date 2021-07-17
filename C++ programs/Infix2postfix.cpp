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
	int main() {
		stack s1;
		s1.top=-1;
		char ar[50], ans[50], c;
	int i, k=0;
		cout<< "Enter the size of the expression: ";
		cin>>s1.size;
		s1.size+=2;
		ar[0]='(';
		cout<<"\nEnter the expression: ";
		for(i=1;i<=s1.size-2;i++)  cin>>ar[i];
		ar[i]=')';
		for(i=0;i<s1.size;i++) {
			if(isdigit(ar[i])) ans[k++]=ar[i];
			else{
			     if(ar[i]=='(') push(s1, ar[i]);
			     else{
				       if(ar[i]=='+' || ar[i]=='-') {
					   
				           while(peek(s1)=='*' || peek(s1)=='/' || peek(s1)=='+' || peek(s1)=='-' )
				                   { c=pop(s1); ans[k++]=c; }
				             push(s1, ar[i]);
		        	                                }
		        	   else {
		        	   	     if(ar[i]=='*' || ar[i]=='/') {
		        	   	     	while(peek(s1)=='*' || peek(s1)=='/')
				                   { c=pop(s1); ans[k++]=c; }
				             push(s1, ar[i]);
								                          }
							 else {  
							 	     if(ar[i]==')') {
									  
							 	        while(peek(s1)!='(') { c=pop(s1); ans[k++]=c;}
							 	        c=pop(s1);
										
							                        }	                          
					              }                             
		                   }
		
	                }
	            }
	        }
	   for(int j=0; k>-1;++j, --k)  cout<<ans[j];
	   return 0;
}
