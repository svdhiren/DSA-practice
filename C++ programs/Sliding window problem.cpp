#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
int k;
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
      
      	return (-1);
	  }
	}
	
	void stack_print(stack s){
	static int t=0;
	t=pop(s);
	if(t==-1) return;
	cout<<t<<" ";
	    
		stack_print(s);
	
		
	}
	
	void slider_window(stack &s, int ar[] ){
		int max, c;
		for(int i=0;i<=s.size-k;i++){
			max=ar[i];
			push(s, ar[i]);
			for(int j=i+1;j<k+i;j++){
				if(ar[j]>max){
					max=ar[j];
					c=pop(s);
					push(s, ar[j]);
				}
			}
		}
		stack_print(s);
		
	}
	int main() {
		stack s1;
		s1.top=-1;
		int a[50];
		cout<<"Enter the number of elements: ";
		cin>>s1.size;
		cout<<"\nEnter the elements: ";
		for(int i=0; i<s1.size;i++){
			cout<<"\nEnter: ";
			cin>>a[i];
		
		}
		cout<<"\nEnter the size of the group: ";
	    cin>>k;
	    cout<<endl;
	    slider_window(s1, a);
	
	return 0;
	    
		
	}
