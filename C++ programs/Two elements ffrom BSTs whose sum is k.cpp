#include<iostream>
#include<stack>
using namespace std;
struct bstnode{
	int data;
	bstnode* lchild;
	bstnode* rchild;
};
typedef struct bstnode* BSTPTR;
BSTPTR newnode(int x){                 //Creation of a new node.
	BSTPTR tmp = new bstnode;
	tmp->data=x;
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	return tmp;
}
BSTPTR construct_BST(int ar[], int l, int h){    //Constructing BST using preorder by recursion.
	if(l>h) return NULL;
	BSTPTR T= newnode(ar[l]);
	int i=l+1;
	 while(T->data > ar[i] && i<=h) i++;
	 T->lchild=construct_BST(ar, l+1, i-1);
	 T->rchild=construct_BST(ar, i, h);
	 
	 //The control will reach here after the whole tree has been has been created.
	 return T; // THis 'T' contains the value of the root, i.e., the function has returned to its first call.
	 
}
//Storing LDR(increaing order) in s1 and RDL(decreasing order) in s2.
//So s1 contains its highest element at its top and s2 contains its lowest element at the top.
void push2stacks(BSTPTR T, stack<int> &s1, stack<int> &s2, int flag){ 
	if(T==NULL) return;
	(flag==1) ? push2stacks(T->lchild, s1, s2, flag) : push2stacks(T->rchild, s1, s2, flag);
	(flag==1) ? s1.push(T->data) : s2.push(T->data);
	(flag==1) ? push2stacks(T->rchild, s1, s2, flag) : push2stacks(T->lchild, s1, s2, flag);
}
//Finding 2 elements, one from each BST which sum upto k.
void findsum(int k, stack<int> s1, stack<int> s2){
	
	while(!s1.empty() && !s2.empty())
	{
		if(s1.top() + s2.top() == k)
		{
			cout<<s1.top()<<" + "<<s2.top()<<" = "<<k<<"\n";
			s1.pop();
			s2.pop();
		}
		else
		{
			if(s1.top() + s2.top() < k) s2.pop();
			else s1.pop();
		}
	
    }
}

void print(BSTPTR T) {
	if(T==NULL) return;
	print(T->lchild);
	cout<<T->data<<" ";
	print(T->rchild);
}

void printstack(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}
int main() {
	int size, a[50];
	cout<<"Enter the number of elements for 1st BST: ";
	cin>>size;
	cout<<"\nEnter 1st BST: ";
	for(int i=0; i<size; i++)
		    cin>>a[i];
	BSTPTR root1=construct_BST(a, 0, size-1);
	cout<<"Enter the number of elements for 2nd BST: ";
	cin>>size;
	cout<<"\nEnter 2nd BST: ";
	for(int i=0; i<size; i++)
		    cin>>a[i];
	BSTPTR root2=construct_BST(a, 0, size-1);
	stack<int> s1;
	stack<int> s2;
	push2stacks(root1, s1, s2, 1);
	push2stacks(root2, s1, s2, 2);
	printstack(s1);
	cout<<endl;
	printstack(s2);
	cout<<"\nEnter the sum: ";
	int k;
	cin>>k;
	findsum(k, s1, s2);
//    cout<<endl;
//    print(root1);
//    cout<<endl;
//    print(root2);
//    cout<<s1.top()<<"\n"<<s2.top();
	return 0;
	}

