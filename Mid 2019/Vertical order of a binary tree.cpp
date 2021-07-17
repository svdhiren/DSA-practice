#include<iostream>
using namespace std;
struct btnode {
	int data;
	int hd, vd;
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
void cal(BTPTR T, int hd, int vd){
	if(T==NULL) return;
	T->hd = hd;
	T->vd = vd;
	cout<<T->data<<": hd = "<<T->hd<<" vd = "<<T->vd<<endl;
	cal(T->lc, hd-1, vd+1);
	cal(T->rc, hd+1, vd+1);
}

void vertical(BTPTR T, BTPTR ar[], int &n){
	if(T==NULL) return;
	int pos;
	if(n==0) { ar[n] = T; n++;}
	else{
		for(int i=0; i<n;i++){
			if(T->hd > ar[i]->hd) pos = i+1;
			if(T->hd==ar[i]->hd)
			    if(T->vd > ar[i]->vd) pos=i+1;
			    else pos = i;
		}
	
	for(int i=n;i>pos;i--) ar[i]=ar[i-1];
	ar[pos]=T;
	n++;
        }
    vertical(T->lc, ar, n);
	vertical(T->rc, ar, n);    
}

int main() {
	BTPTR root = new btnode;
	root=NULL;
	int size;
	size =13 ;
	int arr[]={5,1,2,0,0,3,0,0,7,6,0,0,0};
	root = create(arr, size);
	cal(root, 0, 0);
	BTPTR ar[50]; int n=0;
	vertical(root, ar, n);
	cout<<"The vertical order is: ";
	for(int i=0;i<n;i++) cout<<ar[i]->data<<" ";
	return 0;
}
