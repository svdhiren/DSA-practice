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

void vd_cal(BTPTR T, int vd) {
	if(T==NULL) return;
	T->vd=vd;
	cout<<"\nThe value of vd for "<<T->data<<" is "<<T->vd;
	vd_cal(T->lc, vd+1);
	vd_cal(T->rc, vd+1);
}

void topview(BTPTR T, int k, int flag){
	if(T!=NULL){
		if(abs(T->hd) > abs(k)){
			cout<<T->data<<" ";
			k=T->hd;
		}
		else if(flag==1){
			cout<<T->data<<" ";
			k=T->hd;
		}
	}
	else if(T==NULL) return;
	topview(T->lc, k, 0);
	topview(T->rc, k, 0);
}

void bottomview(BTPTR T, BTPTR ar[], int &n){
	
	if(T==NULL) return;
	bottomview(T->lc, ar, n);
	if(n==0) ar[n++]=T;
	else
	{   int i, flag=1;
		for(i=0; i<n; i++)
		{
			  if(T->hd == ar[i]->hd)
			  { flag=0;
			  	 if(T->vd >= ar[i]->vd)
			  	    {
			  	       ar[i]=T;
					   break;	
					} 
			  }
		}
		if(i==n  && flag!=0) ar[n++]=T;
	}
	bottomview(T->rc, ar, n);
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
	cout<<endl;
	vd_cal(root, 0);
	cout<<"\nThe top view is: ";
	topview(root, 0, 1);
	int n=0;
	BTPTR bottom[30];
	cout<<"\nThe bottom view is: ";
	bottomview(root, bottom, n);
	for(int i=0; i<n; i++) cout<<bottom[i]->data<<" ";
//	cout<<"\n"<<n;
	return 0;
}
