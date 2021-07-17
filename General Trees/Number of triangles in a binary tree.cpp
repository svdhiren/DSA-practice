#include<iostream>
#include<cmath>
using namespace std;
struct btnode {
	int data;
	btnode* lc;
	btnode* rc;
	int l, r;
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
	T->l=T->r=0;
	i++;
	T->lc=create(ar, n);
	i++;
	T->rc=create(ar,  n);

	return T;
}

void print(BTPTR t){
	if(t==NULL) return;
	cout<<t->data<<" - l= "<<t->l<<", r= "<<t->r<<"\n";
	print(t->lc);
	print(t->rc);
}

int tricount(BTPTR T, BTPTR P, int &ct1, int &ct2, int &ct3){
   if(T==NULL)
       return 0;
   int m1 = tricount(T->lc, T, ct1, ct2, ct3);
   int m2 = tricount(T->rc, T, ct1, ct2, ct3);
   T->l=m1;
   T->r=m2;
   if(m1>=1 && m2>=1)
    ct1 += (m1>=m2)?m2:m1;
    BTPTR tmp=T;
   for(int i=1;i<=T->r;i++){
     tmp=tmp->rc;
     if(i<=tmp->l) ct2++;
   }
   tmp=T;
   for(int i=1;i<=T->l;i++){
     tmp=tmp->lc;
     if(i<=tmp->r) ct3++;
   }
   if(P==NULL)
     return 0;
   if(P->lc==T)
      return m1+1;
   else
      return m2+1;
}

int main(){
BTPTR root = NULL;
int ar[]={10,1,3,7,0,0,0,4,8,0,0,9,0,0,2,5,0,0,6,0,0};
int n=21, ct1=0, ct2=0, ct3=0;
root = create(ar, n);
int yo = tricount(root, NULL, ct1, ct2, ct3);
print(root);
cout<<"\nTotal number of triangles = "<<ct1<<" "<<ct2<<" "<<ct3;;
return 0;
}
