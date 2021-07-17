#include<iostream>
using namespace std;
struct btnode {
	int data, isit, mi, ma;
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
	T->isit=0;
	T->mi=T->ma=0;
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

void checkBST(BTPTR T){

if(T==NULL) return;
checkBST(T->lc);
checkBST(T->rc);
if(T->lc==NULL && T->rc==NULL){
    print(T);
    cout<<"\n";
    T->isit=1;
    T->mi=T->data;
    T->ma=T->data;
}
else{
    if(T->lc!=NULL && T->rc!=NULL){
        if(T->lc->isit==1 && T->rc->isit==1){
        if(T->data > T->lc->ma && T->data < T->rc->mi){
            print(T);
            cout<<"\n";
            T->isit=1;
            T->mi=T->lc->ma;
            T->ma=T->rc->mi;
        }
        }
    }
    else if(T->lc==NULL && T->rc!=NULL){
        if(T->rc->isit==1){
            if(T->data < T->rc->mi){
                print(T);
                cout<<"\n";
                T->isit=1;
                T->mi=T->data;
                T->ma=T->rc->mi;
            }
        }
    }
    else{
        if(T->lc->isit==1){
            if(T->data > T->lc->ma){
                print(T);
                cout<<"\n";
                T->isit=1;
                T->ma=T->data;
                T->mi=T->lc->ma;
            }
        }
    }
}

}

int main(){
BTPTR root= new btnode;
	root=NULL;
	int ar[]={11, 8, 5, 4, 0, 0, 6, 0, 0, 9, 0, 0, 13, 12, 0, 0, 0};
	int n=17;
	root = create(ar, n);
	print(root);
	cout<<"\n";
	checkBST(root);
	return 0;

}
