#include<iostream>
using namespace std;
struct btnode {
	char data;
	btnode* lc;
	btnode* rc;
	int yo;
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
	T->lc=T->rc=NULL;
	T->yo=0;
	i++;
	T->lc=create(ar, n);
	i++;
	T->rc=create(ar,  n);

	return T;
}

void alternate(BTPTR T1, BTPTR T2){
  if(T1==NULL) return;
  alternate(T1->lc, T2->rc);
  alternate(T1->rc, T2->lc);
  if(T1->yo!=1 && T2->yo!=1)
  {

      if(T1==T2) cout<<T1->data;
      else
      {
      cout<<T1->data<<" "<<T2->data<<" ";
      T1->yo=1;
      T2->yo=1;
      }
  }

}

void print(BTPTR t){
	if(t==NULL) return;
	cout<<t->data<<" ";
	print(t->lc);
	print(t->rc);
}

int main(){
BTPTR root = NULL;
char ar[50];
int n;
cout<<"Enter the size of the array: ";
cin>>n;
cout<<"Enter the preorder serialization: ";
for(int i=0;i<n;i++) cin>>ar[i];
root = create(ar, n);
alternate(root, root);
return 0;
}



