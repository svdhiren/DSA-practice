#include<iostream>
#include<queue>
using namespace std;
struct btnode {
	int data;
	btnode* lc;
	btnode* rc;
	int x;
	int y;
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

bool iscomplete(queue<BTPTR> q) {
	static int flag = 1;
	if(q.size()==0) return true;
	BTPTR tmp = q.front(); q.pop();
	if(tmp->lc!=NULL) q.push(tmp->lc);
	if(tmp->rc!=NULL) q.push(tmp->rc);
	if(flag==0){
		if(tmp->lc!=NULL || tmp->rc!=NULL)
		 return false;
	}
	if(tmp->lc==NULL && tmp->rc!=NULL)
	    return false;
	if((tmp->lc==NULL && tmp->rc==NULL) || (tmp->lc!=NULL && tmp->rc==NULL))
	    flag=0;
	return iscomplete(q);
}

bool isheap(BTPTR T){
	if(T==NULL) return true;
	if(T->lc!=NULL && T->rc!=NULL)
	{
		if((T->lc->data > T->data) && (T->rc->data > T->data))
	        ;
	    else return false;
	}
	else
	{
		if(T->lc!=NULL && T->rc==NULL )
	     {
	        if(T->lc->data > T->data)
			;
	        else return false;
		 }
	}
	return (isheap(T->lc)  && isheap(T->rc));
}

int main() {
	queue<BTPTR> q;
	BTPTR root= new btnode;
	root=NULL;
	int size = 15;
	int arr[]={5,6,10,0,0,8,0,0,9,12,0,0,15,0,0};
	root = create(arr, size);
	cout<<"Preorder is: ";
	print(root);
	q.push(root);
	bool res = (iscomplete(q) && isheap(root));
	if(res) cout<<"\nThe given tree is a heap tree.";
	else cout<<"\nThe given tree is not a heap tree. ";
//cout<<endl;
//cout<<root->lc->rc->data;
	return 0;
}
