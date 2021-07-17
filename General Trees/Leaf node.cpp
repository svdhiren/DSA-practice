#include<iostream>
using namespace std;
struct btnode {
int data;
btnode* lc;
btnode* rc;
};
typedef btnode* BTPTR;

BTPTR create(int ar[], int i){
BTPTR T = new btnode;
T->data = ar[i];
T->lc=T->rc=NULL;
if(ar[i]==1) return T;
T->lc=create(ar, i-1);
T->rc=create(ar, i-2);
return T;
}

void print(BTPTR T){
if(T==NULL)
    return;
cout<<T->data<<" ";
print(T->lc);
print(T->rc);
}

int main(){
BTPTR root = NULL;
int ar[]={1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
int i;
cout<<"Enter the index of the root :";
cin>>i;
root = create(ar, i);
cout<<"\nThe preorder is: ";
print(root);

return 0;

}
