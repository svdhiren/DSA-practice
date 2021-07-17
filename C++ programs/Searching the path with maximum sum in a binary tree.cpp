#include<iostream>
using namespace std;
struct btnode {
	int data;
	btnode* lc;
	btnode* rc;
};
typedef struct btnode* BTPTR;
BTPTR create(int ar[], int n){
	static int i=0;
	if(i==n || ar[i]==0)
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

 void search(BTPTR T, int ar[], int n, int k){
 	 
	 if(T!=NULL){
	 if(T->data==k){
 		ar[n++]=T->data;
 		int sum=0;
 		cout<<"\nThe path with maximum sum is : ";
 		for(int i=0;i<n;i++) {
 			cout<<ar[i]<<" ";
 			sum+=ar[i];
		 }
		cout<<" with a sum of "<<sum; 
 		return;
	 }
     }
	else if(T==NULL) return;
	ar[n++]=T->data;
	search(T->lc, ar, n, k);
	if(T->rc==NULL) return;
	search(T->rc, ar, n, k);
 }
 
 void search_max(BTPTR T, int ar[], int n, int &ele){
 	 static int max=0;
	 if(T!=NULL){
 		if(T->lc==NULL && T->rc==NULL){
 			ar[n++]=T->data;
 			int sum=0;
 			for(int i=0; i<n;i++) sum+=ar[i];
 			if(sum > max) {
 				max=sum;
 				ele=T->data;
			 }
		 }
	 }
    else if(T==NULL) return;	 
    ar[n++]=T->data;
	search_max(T->lc, ar, n, ele);
	if(T->rc==NULL) return;
	search_max(T->rc, ar, n, ele); 
 
 }
 
 void printpath(BTPTR T, int ar[], int n){
	if(T!=NULL){
		if(T->lc == NULL && T->rc==NULL)
	{   ar[n++]=T->data;
	    cout<<endl;
		for(int i=0;i < n;i++) cout<<ar[i]<<" ";
		return;
	}
	}
	else if(T==NULL) return;
	ar[n++]=T->data;
	printpath(T->lc, ar, n);
	if(T->rc==NULL) return;
	printpath(T->rc, ar, n);
}

int main() {
	BTPTR root= new btnode;
	root=NULL;
	int a[50], size;
	cout<<"Enter the size of the expression: ";
	cin>>size;
	cout<<"\nEnter preorder serialization expression: ";
	for(int i=0; i<size; i++) cin>>a[i];
	root=create(a, size);
	cout<<"\nAll the paths of the binary tree are: \n";
	printpath(root, a, 0); //This function prints all the paths.
	cout<<endl;
	int ele=0, b[50];
    search_max(root, b, 0, ele); //This function searches for the path with maximum sum
	                             // and stores the last element of the path.
	
	search(root, b, 0, ele);    //This function prints the path with maximum sum.
	return 0;
}
