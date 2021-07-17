#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct btnode
{
    int data;
    btnode *lc, *rc, *next;
};
typedef btnode* BTPTR;

BTPTR newnode(int k){

 BTPTR tmp = new btnode;
 tmp->data=k;
 tmp->lc=tmp->rc=tmp->next=NULL;
 return tmp;

}

void populated_creation(queue<BTPTR> q)
{
    if(q.empty())
        return;

    BTPTR T =  q.front(); q.pop();
    int k;
    cout<<"Enter the left child for "<<T->data<<" : ";
    cin>>k;
    if(k!=-1){ T->lc=newnode(k); q.push(T->lc);}
    cout<<"Enter the right child for "<<T->data<<" :";
    cin>>k;
    if(k!=-1) { T->rc=newnode(k); q.push(T->rc);}
    if(q.front()->data==0){
        T=q.front(); q.pop();
        if(!q.empty()) q.push(T);
    }
    else
     T->next=q.front();
     populated_creation(q);
}

int main()
{
    BTPTR root=NULL;
    int n;
    cout<<"Enter the root: ";
    cin>>n;
    root=newnode(n);
    queue<BTPTR> q;
    q.push(root);
    q.push(newnode(0));
    populated_creation(q);
    //Statements for checking.
    BTPTR T=root->lc->lc;
    while(T!=NULL){
        cout<<T->data<<" ";
        T=T->next;
    }

}
