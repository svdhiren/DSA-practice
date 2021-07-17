#include<iostream>
using namespace std;
struct btnode {
int data;
btnode* lc;
btnode* rc;
};
typedef btnode* BTPTR;

BTPTR newfibo(int k){
 BTPTR tmp = new btnode;
 tmp->data=k;
 tmp->lc=tmp->rc=NULL;
 return tmp;

}

void fibo_tree(BTPTR &root, BTPTR prev)
{
    if(root==NULL){
        BTPTR x = newfibo(1);
        BTPTR y = newfibo(1);
        root = newfibo(x->data+y->data);
        root->lc=x;
        root->rc=y;
        fibo_tree(root, x);
    }
    else{
      BTPTR tmp = newfibo(root->data+prev->data);
      tmp->lc=root;
      tmp->rc=prev;
      prev=root;
      root=tmp;
      if(root->data==8) return;
      fibo_tree(root, prev);

    }

}

void print(BTPTR T){
if(T==NULL)
    return;
cout<<T->data<<" ";
print(T->lc);
print(T->rc);
}

int main(){
BTPTR root=NULL;
fibo_tree(root, NULL);
print(root);
return 0;
}


