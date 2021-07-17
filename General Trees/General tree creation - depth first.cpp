#include<iostream>
using namespace std;
struct gtnode {
	int data;
	gtnode* c[10];
};
typedef struct gtnode* GTPTR;

GTPTR newnode(int k) {
	GTPTR tmp = new gtnode;
	tmp->data=k;
	for(int i=0;i<10;i++) 
	    tmp->c[i]=NULL;
	return tmp;    
}

GTPTR create() {
	int n, num;
	cout<<"\nEnter the number: ";
	cin>>num;
	cout<<"\nEnter the number of branches for "<<num<<" :";
	cin>>n;
	GTPTR T = newnode(num);
	if(n==0) return T;
	for(int i=0; i<n; i++){
		cout<<"\nEnter the child "<<i+1<<" of "<<T->data<<" :";
		T->c[i] = create();
	}
	return T;
}

void print(GTPTR T) {
	if(T==NULL) return;
	cout<<T->data<<" ";
	for(int i=0; i<10; i++)
    	print(T->c[i]);
    	
}

int main() {
	GTPTR root = NULL;
	root = create();
	cout<<endl;
	print(root);
	return 0;
}
