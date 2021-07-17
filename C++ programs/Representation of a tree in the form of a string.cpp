#include<iostream>
using namespace std;
struct btnode {
	char data;
	btnode* lc;
	btnode* rc;
};
typedef struct btnode* BTPTR;
BTPTR create(char ar[], int n){
	static int i=0;
	if(i==n || ar[i]=='.')
	{
		return NULL;
	}
	BTPTR T= new btnode;
	T->data=ar[i];
	T->lc=T->rc=NULL;
	i++;
	T->lc=create(ar, n);
	i++;
	T->rc=create(ar,  n);
	
	return T;
}
void print(BTPTR t){
	if(t==NULL) return;
	cout<<t->data<<" ";
	print(t->lc);
	print(t->rc);
}
string s="";
void printstr(BTPTR T){
	if(T==NULL) return;
	s+=T->data;
    if(T->lc==NULL && T->rc == NULL)
        return;
    s+='(';
	printstr(T->lc);
	s+=')';
	if(T->rc !=NULL){
	s+='(';
	printstr(T->rc);
	s+=')';	
	}    
}

int main() {
	BTPTR root= new btnode;
	root=NULL;
	char a[50];
	int size;
	cout<<"Enter the size of the expression: ";
	cin>>size;
	cout<<"\nEnter preorder serialization expression: ";
	for(int i=0; i<size; i++) cin>>a[i];
	root=create(a, size);
	cout<<"\nThe preorder is: \n";
	print(root);
	printstr(root);
	cout<<"\n"<<s;
	return 0;
}
