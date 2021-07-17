#include<iostream>
#include<stack>
using namespace std;
union u {
	int num;
	char ch;
};
struct btnode{
	int flag;
	union u obj;
	btnode* lc;
	btnode* rc;
	int lh, rh;
};
typedef struct btnode* BTPTR;

BTPTR create(stack<BTPTR> &st, btnode ar[], int n){
	static int i=0;
	if(i==n)
	return st.top();
	if(ar[i].flag==1){
		BTPTR T = &ar[i];
		T->lc=NULL;
		T->rc=NULL;
		st.push(T);
		i++;
	}
	else{
		BTPTR T = &ar[i];
		T->lc=T->rc=NULL;
		T->rc=st.top(); st.pop();
		T->lc=st.top(); st.pop();
		st.push(T);
		i++;
	}
   return  create(st, ar, n);
}

void print(BTPTR T){
	if(T==NULL) return;
	print(T->lc);
	if(T->flag==1) cout<<T->obj.num<<" ";
	else cout<<T->obj.ch<<" ";
	print(T->rc);
}
  int calc(char op, int x, int y) {

		switch(op) {
			case '+': return (y+x);
			case '-': return (y-x);
			case '*': return (y*x);
			case '/': return (y/x);
		}
	}
int eval(BTPTR T){
	if(T->lc==NULL && T->rc==NULL)
	 return T->obj.num;
	int m=eval(T->lc);
	int n=eval(T->rc);
	int result=calc(T->obj.ch, n, m);

	return result;
}

 int height(BTPTR T){
 	if(T==NULL) return -1;
 	T->lh=(1+height(T->lc));
 	T->rh=(1+ height(T->rc));
 	int high = (T->lh > T->rh) ? T->lh : T->rh;

 	return high;
 }

int main() {
   btnode s[30];
   int size;
   cout<<"Enter the size of the expression: ";
   cin>>size;
   cout<<"\nEnter the expression: ";
   for(int i=0;i<size;i++){
   	cout<<"\nEnter (operator-0, operand-1) : ";
   	cin>>s[i].flag;
   	if(s[i].flag==0)
   	{
   		cout<<"\nEnter operator : ";
   		cin>>s[i].obj.ch;
	}
	else{
		cout<<"\nEnter operand : ";
		cin>>s[i].obj.num;
	}
   }
   stack<BTPTR> st;
   BTPTR root = new btnode;
   root=NULL;
   root=create(st, s, size);
   cout<<endl;
   print(root);
   int res = eval(root);
   cout<<"\nThe result is: "<<res;
   int h = height(root);
   cout<<"\nThe height of the tree is: "<<h;

   return 0;
}
