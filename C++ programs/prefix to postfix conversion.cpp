#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;
struct stack {
	int top;
	int size;
	string ele[20];
};
void push(stack &s, string x){
 if(s.top!=s.size-1) s.ele[++s.top]=x;
		else cout<<"Stack overflow!";
}

string pop(stack &s){
	if(s.top!=-1)
        return(s.ele[s.top--]);
      else {
      	cout<<"Stack is empty";
      	return ("");
	  }
}

 void prefix2postfix(stack &s, string st, int n) {
 	if(n==-1) {
 		cout<<"\nThe postfix expression is: "<<pop(s);
 		return;
	 }
 	if(isdigit(st[n])) {
 		string tmp=""; tmp+=st[n];
 		push(s, tmp);
	 }
	else{
		string t1=pop(s);
		string t2=pop(s);
		string tmp="";
		tmp+=t1+t2+st[n];
		push(s, tmp);
	}
	prefix2postfix(s, st, --n);
 }

int main() {
	stack s1;
	s1.top=-1;
	cout<<"Enter the size of the expression: "; cin>>s1.size;
	string exp;
	cout<<"\nEnter the expression: ";
	cin>>exp;
	prefix2postfix(s1, exp, s1.size-1);
//	cout<<"\n"<<exp[6];
//	string tmp="";
//	tmp+=exp[6];
//	cout<<"\n"<<tmp;
	return 0;
}
