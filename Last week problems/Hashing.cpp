#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
    node* next;
};
typedef struct node* LPTR ;

LPTR newnode(int k){
	LPTR tmp = new node;
	tmp->data=k;
	tmp->next=NULL;
	return tmp;
}
LPTR create(LPTR L, int k){

	if(L==NULL) return newnode(k);
    L->next = create(L->next, k);

	return L;
}



int  main()
{

}
