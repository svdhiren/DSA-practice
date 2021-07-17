#include<iostream>
using namespace std;
struct bstnode{
	int data;
	bstnode* lc;
	bstnode* rc;
};
typedef struct bstnode* BSTPTR;
BSTPTR root = NULL;
int height(BSTPTR yo)  
{  
    if (yo == NULL)  
        return -1;  
    else
    {  
        /* compute the depth of each subtree */
        int lh = height(yo->lc);  
        int rh = height(yo->rc);  
      
        /* use the larger one */
        if (lh > rh)  
            return(lh + 1);  
        else return(rh + 1);  
    }  
} 
int code[50], s; //Global array which stores the code.
void codeit(BSTPTR T, int ar[], int n, int k){
	int change = 0;
	if(T==NULL) return;
	if(T->data == k)
	{
		for(int i=0; i<n; i++) code[i]=ar[i];
		
	}
	if(T->lc!=NULL) {
		ar[n++]=0;
		change = 1;
	}
		codeit(T->lc, ar, n, k);
		if(change == 1) n--;
		if(T->rc !=NULL) ar[n++]=1;
		codeit(T->rc, ar, n, k);
} 
void insert(BSTPTR T, int k, BSTPTR p ) {
	  if(k < T->data){
		if(T->lc == NULL){
			BSTPTR tmp = new bstnode;
			tmp->data=k;
			tmp->lc=tmp->rc=NULL;
			T->lc=tmp;
		}
		else insert(T->lc, k, T);
	}
	else{
		if(T->rc == NULL){
			BSTPTR tmp = new bstnode;
			tmp->data=k;
			tmp->lc=tmp->rc=NULL;
			T->rc=tmp;
		}
		else insert(T->rc, k, T);
	}  
//Insertion is over at this point.
  int h1 = height(T->lc);
  int h2 = height(T->rc);
  if(h1-h2 >= -1 && h1-h2 <= 1)	{ root=T; return;  }   // Height comparison of left and right subtrees.
  int ar[50];                                          // Control reaches here when the node is unbalanced.
  codeit(T, ar, 0, k);
  if(code[0] == 0 && code[1]==0){
  	BSTPTR x, y, t;
  	y=T->lc;
  	x=y->lc;
  	if(p!=NULL) {
  		if(p->lc == T) p->lc = y;
  		else p->rc = y;
		root=p;
	  }
	else root=y;
	t=y->rc;
	y->rc=T;
	T->lc=t;  }
  if(code[0]==0 && code[1]==1){
  	BSTPTR x, y, t1, t2;
  	y=T->lc;
  	x=y->rc;
  	t1=x->lc;   //.
  	x->lc=y;    //.
  	y->rc=t1;   //.
  	T->lc=x;    //Left rotation.
  	if(p!=NULL) {
  		if(p->lc == T) p->lc = x;
  		else p->rc = x;
  		root=p;
	  }
	else root=x;
	t2=x->rc; //.
	x->rc=T;  //.
	T->lc=t2; // Right rotation.
	  
  }
  if(code[0]==1 && code[1]==1){
  	BSTPTR x, y, t;
  	y=T->rc;
  	x=y->rc;
  	if(p!=NULL){
  		if(p->lc == T) p->lc = y;
  		else p->rc = y;
  		root=p;
	  }
	else root=y;
	t=y->lc;
	y->lc=T;
	T->rc=t;
  }
  if(code[0]==1 && code[1]==0){
  	BSTPTR x, y, t1, t2;
  	y=T->rc;
	x=y->lc;
	t1=x->rc;
	x->rc=y;
	y->lc=t1;
	if(p!=NULL){
		if(p->lc == T) p->lc = x;
  		else p->rc = x;
		root=p;
	}   
	else  root=x;
	t2=x->lc;
	x->lc=T;
	T->rc=t2;
	 
  }
 
}
void print(BSTPTR T){
	if(T==NULL) return;
	cout<<T->data<<" ";
	print(T->lc);
	print(T->rc);
}

int main() {
	BSTPTR head = new bstnode;
	head->lc=head->rc=NULL;
	cout<<"Enter the number of elements: ";
	int n, k,a[50];
	cin>>n;
	cout<<"\nEnter the elements: ";
	for(int i=0;i<n;i++){
		cin>>k;
		if(i==0) {
			head->data=k;
			root = head;
		}
		else  {
			insert(root, k, NULL);
		//	codeit(root,a, 0, k);
		//	cout<<"\n"<<code[0]<<code[1];
		}
		}
	cout<<"\nThe preorder of the tree is: ";
	print(root);
	cout<<"\nVOILA!!";
    return 0;
}
