#include<iostream>
#include<stack>
using namespace std;
struct gtnode {
	char data;
	gtnode* c[10];
	int cnt;
	int done;
};
typedef struct gtnode* GTPTR;

struct btnode{
  char num;
  btnode* lc;
  btnode* rc;
};
typedef btnode* BTPTR;

BTPTR new_bnode(char k){
  BTPTR t = new btnode;
  t->num = k;
  t->lc=t->rc=NULL;
  return t;
}

GTPTR newnode(char k) {
	GTPTR tmp = new gtnode;
	tmp->data=k;
	tmp->cnt=0;
	tmp->done=0;
	for(int i=0;i<10;i++)
	    tmp->c[i]=NULL;
	return tmp;
}

void create(stack<GTPTR> s){
	if(s.size()==0) return;
	GTPTR T = s.top(); s.pop();
	int n;
	char num;
	cout<<"\nEnter the number of children for "<<T->data<<" ";
	cin>>n;
	T->cnt=n;
	for(int i=0; i<n;i++){
		cout<<"Enter the child "<<i+1<<" of "<<T->data<<" : ";
		cin>>num;
		T->c[i] = newnode(num);
	}
	for(int i = n-1;i>=0;i--) s.push(T->c[i]);
	create(s);
}

void print(GTPTR T) {
	if(T==NULL) return;
	cout<<T->data<<" ";
	for(int i=0; i<10; i++)
    	print(T->c[i]);

}

void breaktree(GTPTR G, BTPTR B){

 int a=-1, b=-1, ct=0;
 for(int i=0;i<G->cnt;i++){
    if(G->c[i]->done!=1)
    {
      if(ct==0)
          a=i;
      if(ct==1)
          b=i;
      ct++;
    }
    if(ct==2) break;
 }
 if(a!=-1) {
    G->c[a]->done=1;
    B->lc = new_bnode(G->c[a]->data);
    breaktree(G->c[a], B->lc);
 }
 if(b!=-1) {
    G->c[b]->done=1;
    B->rc = new_bnode(G->c[b]->data);
    breaktree(G->c[b], B->rc);
 }
 for(int i=0;i<G->cnt;i++)
     if(G->c[i]->done!=1)
         G->done=0;

}

void print_bt(BTPTR T){
 if(T==NULL)
    return;
 cout<<T->num<<" ";
 print_bt(T->lc);
 print_bt(T->rc);

}

int main(){
    char num;
	cout<<"Enter the root: ";
	cin>>num;
	GTPTR root = newnode(num);
	stack<GTPTR> s;
	s.push(root);
	create(s);
	cout<<endl; print(root);
	while(root->done!=1){
        root->done=1;
        BTPTR T = new_bnode(root->data);
        breaktree(root, T);
        cout<<"\nThe binary tree is: ";
        print_bt(T);
	}
	return 0;
}

