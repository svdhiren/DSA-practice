#include<iostream>
#include<cmath>
using namespace std;
struct btnode {
	int data;
	btnode* lc;
	btnode* rc;
	int hd, vd;
};
typedef struct btnode* BTPTR;
struct hd_sum{
	int sum;
	int hd;
};
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
	print(t->lc);
	cout<<t->data<<" ";
	print(t->rc);
}

void hd_cal(BTPTR T, int hd) {
	if(T==NULL) return;
	T->hd=hd;
	cout<<"\nThe value of hd for "<<T->data<<" is: "<<T->hd;
	hd_cal(T->lc, hd-1);
	hd_cal(T->rc, hd+1);
}   

void versum(BTPTR T, hd_sum ar[], int &n){
	if(T==NULL) return;
	versum(T->lc, ar, n);
	if(n==0)
	{
		ar[n].hd=T->hd;
		ar[n].sum=T->data;
		n++;
	}
	else{
		int i;
		for(i=0; i<n ; i++)
		{
			if(ar[i].hd == T->hd)
			  {
			  	ar[i].sum+=T->data;
			  	break;
			  }
		}
	    if(i==n)
	    {
	  	ar[i].hd=T->hd;
	  	ar[i].sum=T->data;
	  	n++;
	    }	
	   }
	versum(T->rc, ar, n);   
}

int main() {
	BTPTR root= new btnode;
	root=NULL;
	int size=21;
	int a[]={1,2,3,0,8,0,0,4,0,0,5,6,10,0,0,0,7,9,0,0,0};
	root = create(a, size);
	cout<<"\nThe inorder is: ";
	print(root);
	cout<<endl;
	hd_cal(root, 0);
	hd_sum s[30];
	int n=0;
	for(int i=0; i<30; i++) s[i].sum=0;
	versum(root, s, n);
	cout<<"\nThe vertical sum of the BT is: ";
	for(int i=0; i<n; i++)
		cout<<"\nSum with hd value "<<s[i].hd<<" is = "<<s[i].sum;
	
}
