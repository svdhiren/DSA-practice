#include<iostream>
#include<stack>
using namespace std;
struct gtnode {
	char data;
	gtnode* c[10];
	int cnt;
};
typedef struct gtnode* GTPTR;

GTPTR newnode(char k) {
	GTPTR tmp = new gtnode;
	tmp->data=k;
	tmp->cnt=0;
	for(int i=0;i<10;i++)
	    tmp->c[i]=NULL;
	return tmp;
}

void create(stack<GTPTR> s){
	if(s.size()==0) return;
	GTPTR T = s.top(); s.pop();
	int n;
	char num;
	cout<<"\nEnter the number of children for "<<T->data<<" ";
	cin>>n;
	T->cnt=n;
	for(int i=0; i<n;i++){
		cout<<"Enter the child "<<i+1<<" of "<<T->data<<" : ";
		cin>>num;
		T->c[i] = newnode(num);
	}
	for(int i = n-1;i>=0;i--) s.push(T->c[i]);
	create(s);
}

void print(GTPTR T) {
	if(T==NULL) return;
	cout<<T->data<<" ";
	for(int i=0; i<10; i++)
    	print(T->c[i]);

}


int main(){
    char num;
	cout<<"Enter the root: ";
	cin>>num;
	GTPTR root = newnode(num);
	stack<GTPTR> s;
	s.push(root);
	create(s);
	cout<<endl; print(root);
	return 0;
}
