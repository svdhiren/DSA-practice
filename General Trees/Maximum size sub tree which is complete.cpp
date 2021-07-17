#include<iostream>
#include<cmath>
using namespace std;
struct btnode {
	int data;
	btnode* lc;
	btnode* rc;
};
typedef struct btnode* BTPTR;

BTPTR newnode(int k)
{
    BTPTR tmp = new btnode;
    tmp->data=k;
    tmp->lc=tmp->rc=NULL;
    return tmp;
}

bool search_(int in[], int l, int h, int ele){
  for(int i=l;i<=h;i++)
     if(ele==in[i])
        return true;
  return false;
}

BTPTR create(int lev[], int in[], int l, int h, int n){
if(l > h) return NULL;
int i;
for(i=0;i<n;i++)
    if(search_(in, l, h, lev[i]))
        break;
BTPTR T = newnode(lev[i]);
int j;
for(int a=l;a<=h;a++)
    if(in[a]==T->data){
        j=a;
        break;
    }
T->lc=create(lev, in, l, j-1, n);
T->rc=create(lev, in, j+1, h, n);
return T;
}

void print(BTPTR t){
	if(t==NULL) return;
	cout<<t->data<<" ";
	print(t->lc);
	print(t->rc);
}


int main(){
BTPTR root = NULL;
int lev[]={20,8,22,4,12,10,14};
int in[]={4,8,10,12,14,20,22};
int n=sizeof(in)/sizeof(in[0]);
cout<<n<<endl;
root = create(lev, in, 0, n-1, n);
print(root);
return 0;
}

