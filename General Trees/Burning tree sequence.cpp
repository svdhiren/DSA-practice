#include<iostream>
#include<queue>
using namespace std;
struct btnode {
	char data;
	int done;
	btnode* p;
	btnode* lc;
	btnode* rc;
};
typedef struct btnode* BTPTR;
BTPTR create(char ar[], int n){
	static int i=0;
	if(i==n || ar[i]=='.')
	{
		return NULL;
	}
	BTPTR T= new btnode;
	T->data=ar[i];
	T->lc=T->rc=T->p=NULL;
	T->done=0;
	i++;
	T->lc=create(ar, n);
	i++;
	T->rc=create(ar,  n);

	return T;
}

void print(BTPTR t){
	if(t==NULL) return;
	cout<<t->data<<" ";
	print(t->lc);
	print(t->rc);
}

void assign_parent(BTPTR T, BTPTR P)
{    if(T==NULL)
       return;
    T->p=P;
    assign_parent(T->lc, T);
    assign_parent(T->rc, T);

}

void find_target(BTPTR r, BTPTR &T, char t){
if(r==NULL) return;
if(r->data==t) T=r;
find_target(r->lc, T, t);
find_target(r->rc, T, t);
}

void burn(queue<BTPTR> q)
{
    if(q.empty()) return;

    int n = q.size();
    for(int i=0;i<n;i++)
    {
        BTPTR T=q.front(); q.pop();
        T->done=1;
        cout<<T->data<<" ";
        if(T->p!=NULL)
            if(T->p->done!=1)
               q.push(T->p);
        if(T->lc!=NULL)
            if(T->lc->done!=1)
               q.push(T->lc);
        if(T->rc!=NULL)
            if(T->rc->done!=1)
               q.push(T->rc);
    }
    cout<<"\n";
    burn(q);
}





int main(){
BTPTR root = NULL;
char ar[50], target;
int n;
BTPTR tar;
cout<<"Enter the size of the array: ";
cin>>n;
cout<<"Enter the preorder serialization: ";
for(int i=0;i<n;i++) cin>>ar[i];
root = create(ar, n);
cout<<"Enter the target node: ";
cin>>target;
assign_parent(root, NULL);
find_target(root, tar, target);
queue<BTPTR> q;
cout<<"\nThe sequence in which the nodes burn are: \n";
q.push(tar);
burn(q);
return 0;
}

