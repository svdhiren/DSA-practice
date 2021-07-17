#include<iostream>
using namespace std;
struct bstnode{
bstnode* lchild;
int data;
bstnode* rchild;
};
typedef struct bstnode* BSTPTR;

struct stack{
int size;
BSTPTR ele[50];
int top;

};

void push(stack &s, BSTPTR x){
if(s.top!=s.size-1) s.ele[++s.top]=x;
else cout<<"Stack overflow!";

}
BSTPTR pop(stack &s) {
      if(s.top!=-1)
        return(s.ele[s.top--]);
      else {
      
      BSTPTR del=new bstnode;
      del->data=-1;
      del->lchild=del->rchild=NULL;
      return del;
 }
}

int peek(stack s) {
return s.ele[s.top]->data;
}

void constructDLR(BSTPTR T, stack &s, int ar[], int n){
int i=1;
while(i!=n){
while(ar[i] < peek(s) ){
BSTPTR tmp= new bstnode;
tmp->data=ar[i];
tmp->lchild=tmp->rchild=NULL;
T->lchild=tmp;
T=tmp;
push(s, tmp);
i++;
}
while(ar[i]> peek(s) && s.top!=-1) 
T=pop(s);
BSTPTR tmp=new bstnode;
tmp->data=ar[i];
tmp->rchild=tmp->lchild=NULL;
T->rchild=tmp;
T=tmp;
push(s, tmp); 
   i++;
}
}

void printLDR(BSTPTR T) {
if(T==NULL) return;
printLDR(T->lchild);
cout<<T->data<<" ";
printLDR(T->rchild);
}

int main() {
    stack s1;
    s1.top=-1;
    s1.size=30;
int a[50], size;
cout<<"Enter the number of elements: ";
cin>>size;
for(int i=0; i<size;i++) {
cout<<"\nEnter: ";
cin>>a[i];
}
BSTPTR root=new bstnode;
root->data=a[0];
root->lchild=root->rchild=NULL;
push(s1, root);
constructDLR(root, s1, a, size);
cout<<endl;
printLDR(root);
return 0;

}  
