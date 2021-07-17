#include<iostream>
using namespace std;
struct ftnode {
	int data;
	ftnode* lc;
	ftnode* rc;
};
typedef struct ftnode* FTPTR;

bool isPrime(int n){
	if(n==2) return true;
	for(int i=2;i<n/2;i++)
	   if(n%i == 0)  return false;

	return true;
}

FTPTR factor(int n){

	FTPTR T = new ftnode;
	T->data = n;
	T->lc= T->rc=NULL;
	if(isPrime(n)) return T;
	int i;
	for(i=2;i<n/2;i++)
	    if(n%i==0) break;
    T->lc = factor(i);
	T->rc = factor(n/i);
	return T;
}

void print_factor(FTPTR T){
	if(T==NULL) return;
	cout<<T->data<<" ";
	print_factor(T->lc);
	print_factor(T->rc);
}

int main() {
	int n;
	FTPTR root = NULL;
	cout<<"Enter the root of the factor tree: ";
	cin>>n;
	root = factor(n);
	cout<<"\nThe preorder of the factor tree is: ";
	print_factor(root);
	//cout<<"\n"<<root->rc->lc->data;
	//cout<<"\n"<<root->rc->data;
	return 0;
}
