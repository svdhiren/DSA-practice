#include<iostream>
#include<queue>
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
void strictly(BTPTR T, BTPTR &a, BTPTR &b)
{
    if(T==NULL) return;
    strictly(T->lc, a, b);
    strictly(T->rc, a, b);
    if(T->lc==NULL && T->rc!=NULL){
        if(a==NULL && b==NULL){
            a=T;
            b=T->rc;
        }
        else{
            T->lc=b;
            if(a->lc==b) a->lc=NULL;
            else a->rc=NULL;
            a=b=NULL;
        }
    }
    else if(T->lc!=NULL && T->rc==NULL){
        if(a==NULL && b==NULL){
            a=T;
            b=T->lc;
        }
        else{
           T->rc=b;
            if(a->lc==b) a->lc=NULL;
            else a->rc=NULL;
            a=b=NULL;
        }
    }
}

int main(){
BTPTR root = NULL;
char ar[50];
int n;
cout<<"Enter the size of the array: ";
cin>>n;
cout<<"Enter the preorder serialization: ";
for(int i=0;i<n;i++) cin>>ar[i];
root = create(ar, n);
cout<<"\nThe predorder before the conversion is: "; print(root);
BTPTR a=NULL, b=NULL;
strictly(root, a, b);
cout<<"\nThe predorder after the conversion is: "; print(root);
return 0;
}


