#include<iostream>
#include<queue>
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

void sort_print(BTPTR t, int sort[], int &n, int choice){
	if(t==NULL) return;
	 sort_print(t->lc, sort, n, choice);
     if(choice==2) cout<<t->data<<" ";
     else sort[n++]=t->data;
	 sort_print(t->rc, sort, n, choice);
}

void put_it_back(BTPTR T, int sort[], int n){
	static int i=0;
	if(T==NULL || i==n) return;
	T->data=sort[i++];
	put_it_back(T->lc, sort, n);
	put_it_back(T->rc, sort, n);
}

void preorder(BTPTR T){
	if(T==NULL) return;
	cout<<T->data<<" ";
	preorder(T->lc);
	preorder(T->rc);
}

BTPTR reconstruct(int sort[], int n, int i){
	if(i>=n) return NULL;
	BTPTR H = new btnode;
	H->data = sort[i];
	H->lc=H->rc=NULL;
	H->lc=reconstruct(sort, n, 2*i+1);
	H->rc=reconstruct(sort, n, 2*i+2);
	
	return H;
}

int main() {
	queue<BTPTR> q;
	BTPTR root= new btnode;
	root=NULL;
	int size = 17;
	int arr[]={5,3,1,0,0,4,0,0,10,6,0,0,12,0,15,0,0};
	root = create(arr, size);
	cout<<"INorder is: ";
	sort_print(root, arr, size, 2);
	q.push(root);
	bool res = iscomplete(q);
	if(res){  //Just put it back into the BST in preorder fashion.
		cout<<"\nPUTTING it back.";
		int sort[50], n=0;
		sort_print(root, sort, n, 1);
		cout<<endl;
    	for(int i=0;i<n;i++) cout<<sort[i]<<" ";
		put_it_back(root, sort, n);
		cout<<"\nThe preorder of the heap is: ";
		preorder(root); 
	}
	else{
		cout<<"\nRECONSTRUTING a new heap tree.";
		int sort[50], n=0;
		sort_print(root, sort, n, 1);
	//	cout<<endl;
    //	for(int i=0;i<n;i++) cout<<sort[i]<<" ";
		BTPTR H = reconstruct(sort, n, 0);
		cout<<"\nThe preorder of the heap is: ";
		preorder(H); 
	}
	return 0;
}
