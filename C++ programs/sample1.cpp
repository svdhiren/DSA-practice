#include<iostream>
using namespace std;
char os[]={ '(','[', '{'};
char cs[]={')', ']', '}'};
int Findit(char a, char sym[]) {
	for(int j=0;j<3;j++) {
		if(a==sym[j]) return j;
	}
	return -1;
	
}

	struct stack{
		int size;
		char ele[50];
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
	int main() {
		char c;
		stack s1;
		s1.top=-1;
		char ar[50];
		int i, i1, i2, k=1;
		cout<<"Enter the size of the expression: ";
		cin>>s1.size;
		
		cout<<"\nEnter the expression";
		for(i=0;i<s1.size;i++) cin>>ar[i];
		for(i=0;i<s1.size;i++) {
			if(ar[i]=='('||ar[i]=='['||ar[i]=='{'){
				push(s1, ar[i]);
			}
			else {
				if(ar[i]==')'||ar[i]==']'||ar[i]=='}'){
				  c=pop(s1);
				  i1=Findit(ar[i], cs );
				  i2=Findit(c, os);
				  if(i1!=i2) {cout<<"The expression is not balanced!"; k=0; break; }
				  
				  
				}
			}
	   }
	   if(k!=0) {
	   
	   if(s1.top==-1) cout<<"\nThe expression is balanced";
	   else cout<<"\nThe expression is unbalanced";
	   
}
	   return 0;
	}
	
	
	
	
