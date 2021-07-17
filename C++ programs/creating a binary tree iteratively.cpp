#include<iostream>
#include<stack>
using namespace std;
struct btnode {
	int data;
	btnode* lc;
	btnode* rc;
};
typedef struct btnode* BTPTR;

BTPTR newnode(int k){
	BTPTR tmp = new btnode;
	tmp->data=k;
	tmp->lc=tmp->rc=NULL;
	return tmp;
}

void create(BTPTR T) {
	stack<BTPTR> s;
	int ans, num;
	while(1){
	   cout<<"\nDo you want a left child for "<<T->data<<" ? ";
	   cin>>ans;
	   if(ans==1)
	   {
	   	   s.push(T);
		   cout<<"\nEnter the left child: ";
	   	   cin>>num;
	   	   BTPTR temp = newnode(num);
	   	   T->lc=temp;
	   	   T=temp;
	   }
	   else
	   {
	   	  cout<<"\nDo you want a right child for "<<T->data<<" ? ";
	   	  cin>>ans;
	   	  if(ans==1)
	   	  {
	   	  	 cout<<"\nEnter the right child: "; 
	   	  	 cin>>num;
	   	  	 BTPTR temp = newnode(num);
	   	  	 T->rc=temp;
	   	  	 T=temp;
		  }
		  else
		  {
		  	if(s.empty()==true) break;
		  	else{
		  		while(!s.empty() && ans!=1){
		  			T=s.top();
		  			s.pop();
		  			cout<<"\nDo you want a right child for "<<T->data<<" ? ";
		  			cin>>ans;
		  			}
		  			if(s.empty()==true && ans==0) break;
		  			cout<<"\nEnter the right child: ";
		  			cin>>num;
		  			BTPTR temp = newnode(num);
					T->rc=temp;
					T=temp;  			  
			    }
		  }
	   } 
	}
}

void print(BTPTR t){
	if(t==NULL) return;
	cout<<t->data<<" ";
	print(t->lc);
	print(t->rc);
}

int main() {
    int n;
	cout<<"Enter the root element: ";
	cin>>n;
	BTPTR root= newnode(n);
	create(root);
	cout<<endl;
	print(root);
	return 0;
}
