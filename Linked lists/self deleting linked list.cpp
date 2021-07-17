#include<iostream>
using namespace std;
struct dlnode{
	int data;
	dlnode* left;
	dlnode* right;
};
typedef struct dlnode* DPTR;
int size;

 DPTR addnode(DPTR head, int ar[], int i){
 	if(i==size){
 		return NULL;
	 }
	 else{
	 	DPTR T=new dlnode;
	 	T->data=ar[i];
	 	T->left=NULL;
	 	T->right=NULL;
	 	if(head==NULL) head=T;
	 	else{
	 		head->right=T;
	 		T->left=head;
	 		head=T;
		 }
	 }
	 head->right=addnode(head, ar, ++i);
 	
 }
  void print(DPTR head){
  	if(head==NULL) return;
  	cout<<head->data<<" ";
  	print(head->right);
  	
  }

void mark(DPTR h, int ar[], int i){
	if(i==size) return;
	DPTR L=h;
	if(ar[i]<=size){
		for(int j=1;j<ar[i];j++)  L=L->right;
		L->data=-1;
	}
	mark(h, ar, ++i);
}

void del(DPTR prev, DPTR cur, DPTR next, DPTR &h ){
	
if(cur==NULL) return;
else{
	if(cur->data==-1 && prev == NULL)
	{
		next->left=NULL;
		prev=NULL;
		cur=next;
		h=next;
	}
    else{
	if(cur->data==-1 && next == NULL)
	{
		prev->right=NULL;
		cur=NULL;
	}
else  {
	if(cur->data==-1){
		
	 next->left=prev;
	 prev->right=next;
	 cur=next;
	}
	else {
		prev=cur;
		cur=next;
	}
}
}
}

if(cur==NULL) del(prev, cur, cur, h);
else del(prev, cur, cur->right,h);


}

int main() {
	DPTR head;
	head=NULL;
	
	int a[50];
	cout<<"Enter the number of elements: ";
	cin>>size;
	for(int i=0;i<size;i++){
		cout<<"\nEnter: ";
		cin>>a[i];
	}
	head=addnode(head, a, 0);
	print(head);
	
	mark(head, a, 0); 
	cout<<endl;
	print(head);
	
	del(NULL, head, head->right, head);
	cout<<endl;
	print(head);
	
	
	return 0;
	
}
