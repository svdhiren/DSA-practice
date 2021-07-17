#include<iostream>
#include<queue>
using namespace std;
struct gtnode {
	int data, cnt;
	gtnode* c[10];
};
typedef struct gtnode* GTPTR;

struct btnode {
   int data;
   btnode* fc;
   btnode* ns;
};
typedef btnode* BTPTR ;

GTPTR newnode(int k) {
	GTPTR tmp = new gtnode;
	tmp->data=k;
	for(int i=0;i<10;i++)
	    tmp->c[i]=NULL;
	return tmp;
}

BTPTR new_btnode(int k){
  BTPTR tmp = new btnode;
  tmp->data = k;
  tmp->fc=tmp->ns=NULL;
  return tmp;
}


void create(queue<GTPTR> q){
	if(q.size()==0) return;
	int n, num;
	GTPTR tmp = q.front(); q.pop();
	cout<<"\nEnter the number of children for "<<tmp->data<<" : ";
	cin>>n;
	tmp->cnt=n;
	for(int i=0; i<n; i++) {
		cout<<"\nEnter the child "<<i+1<<" of "<<tmp->data<<" : ";
		cin>>num;
		tmp->c[i] = newnode(num);
		q.push(tmp->c[i]);
	}
	create(q);
}

void print(GTPTR T) {
	if(T==NULL) return;
	cout<<T->data<<" ";
	for(int i=0; i<T->cnt; i++)
    	print(T->c[i]);

}

BTPTR gen2bin(GTPTR G, GTPTR P){
  if(G==NULL) return NULL;
  BTPTR T = new_btnode(G->data);
  T->fc = gen2bin(G->c[0], G);
  if(P!=NULL) {
   int i;
   for(i=0;i<P->cnt;i++)
     if(P->c[i]==G)
      break;

    int j=i+1;
    if(j<P->cnt)
      T->ns = gen2bin(P->c[j], P);
  }
  return T;

}

void print_bt(BTPTR T){
 if(T==NULL) return;
 cout<<T->data<<" ";
 print_bt(T->fc);
 print_bt(T->ns);
}

int main() {
	int num;
	cout<<"Enter the root: ";
	cin>>num;
	GTPTR root = newnode(num);
	queue<GTPTR> q;
	q.push(root);
	create(q);
	cout<<"\n"; print(root);
	BTPTR T = NULL;
	T = gen2bin(root, NULL);
	cout<<"\n"; print_bt(T);
	return 0;
}


