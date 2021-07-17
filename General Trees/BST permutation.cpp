#include<iostream>
using namespace std;
struct bstnode {
	int data;
	bstnode *lc, *rc;
};
typedef struct bstnode* BSTPTR;
BSTPTR insert(BSTPTR T, int key) {
	if(T==NULL){
		BSTPTR Tmp = new bstnode;
		Tmp->data = key;
		Tmp->lc = Tmp->rc = NULL;
		return Tmp;
	}
	if( key < T->data) T->lc = insert(T->lc, key);
	else T->rc = insert(T->rc, key);
	return T;
}

void print(BSTPTR T){
	if(T==NULL) return;
	print(T->lc);
	cout<<T->data<<" ";
	print(T->rc);
}

void storeposs(BSTPTR t, BSTPTR poss[], int &ps, BSTPTR par[], int p, int res[], int rs)
{  // static int call=0;
   // call++;
    int x, fl;
    for(int i=0;i<p;i++){
        fl=1;
		if(par[i]->lc!=NULL){
        x=par[i]->lc->data;
        for(int j=0;j<rs;j++)
            if(x==res[j]) { fl=0; break;}
        if(fl) poss[ps++]=par[i]->lc;
        }
        fl=1;
        if(par[i]->rc!=NULL){
         x=par[i]->rc->data;
        for(int j=0;j<rs;j++)
            if(x==res[j]) { fl=0; break;}
        if(fl) poss[ps++]=par[i]->rc;
        }

    }
    fl=1;
    if(t->lc!=NULL){
     x=t->lc->data;
      for(int j=0;j<rs;j++)
            if(x==res[j]) { fl=0; break;}
        if(fl) poss[ps++]=t->lc;
    }
    fl=1;
    if(t->rc!=NULL){
     x=t->rc->data;
      for(int j=0;j<rs;j++)
            if(x==res[j]) { fl=0; break;}
        if(fl) poss[ps++]=t->rc;
    }

}
void BST_permute(BSTPTR T, int res[], int rs, BSTPTR par[], int p, int call){
    static int ct=1;
    res[rs++]=T->data;
    BSTPTR poss[20];int ps=0;
    storeposs(T, poss, ps, par, p, res, rs);
    if(ps==0){
        cout<<ct<<".) ";
        for(int i=0;i<rs;i++) cout<<res[i]<<" ";
        ct++;
        cout<<"\n";
        return;
    }
    par[p++]=T;
    for(int i=0;i<ps;i++){
        BST_permute(poss[i], res, rs, par, p, call+1);
    }

}

int main(){
	BSTPTR root = NULL;
	cout<<"Enter the number of elements you want to enter: ";
	int n, k;
	cin>>n;
	cout<<"\nStart entering: \n";
	for(int i=0;i<n;i++){
		cout<<"Enter: ";
		cin>>k;
		root = insert(root, k);
	}
	cout<<"\nTHe inorder of the BST is: ";
	print(root);
	cout<<"\n";
	int res[20];
	BSTPTR par[20];
	BST_permute(root, res, 0, par, 0, 1);
	return 0;
}

