#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct gtnode {
	int data;
	gtnode* c[10];
	int flo;
	int cnt;
	int info;
	int child;
};
typedef struct gtnode* GTPTR;

GTPTR newnode(int k) {
	GTPTR tmp = new gtnode;
	tmp->data=k;
	tmp->info=0;
	tmp->flo=0;
	tmp->cnt=0;
	tmp->child=0;
	for(int i=0;i<10;i++)
	    tmp->c[i]=NULL;
	return tmp;
}

void create(stack<GTPTR> s){
	if(s.size()==0) return;
	GTPTR T = s.top(); s.pop();
	int n, num;
	cout<<"\nEnter the number of children for "<<T->data<<" : ";
	cin>>n;
	T->child=n;
	for(int i=0; i<n;i++){
		cout<<"Enter the child "<<i+1<<" of "<<T->data<<" : ";
		cin>>num;
		T->c[i] = newnode(num);
	}
	for(int i = n-1;i>=0;i--) s.push(T->c[i]);
	create(s);
}

int height(GTPTR T){
   if(T==NULL) return -1;
   int h[10];
   for(int i=0;i<10;i++){
    h[i]=1+height(T->c[i]);
   }
   int maxi=h[0];
   for(int i=1;i<10;i++){
    if(h[i] > maxi) maxi=h[i];
   }
   return maxi;

}

void childcount(GTPTR T, int& ct){
   if(T==NULL) return;
   ct++;
   for(int i=0;i<10;i++)
     childcount(T->c[i], ct);
}

void calc(GTPTR T) {
	if(T==NULL) return;
	int ct=-1;
	childcount(T, ct);
	T->cnt=ct;
	T->flo=T->cnt + height(T);
	for(int i=0; i<10; i++)
    	calc(T->c[i]);
}

void arrange(GTPTR C, int ar[]) {
    for(int i=0;i<C->child;i++) ar[i]=i;
    for(int i=0;i<C->child;i++){
        for(int j=0;j<C->child-1;j++){
            if(C->c[ar[j]]->flo < C->c[ar[j+1]]->flo)
                swap(ar[j], ar[j+1]);
            else if(C->c[ar[j]]->flo == C->c[ar[j+1]]->flo)
                   if(C->c[ar[j]]->cnt < C->c[ar[j+1]]->cnt)
                     swap(ar[j], ar[j+1]);
        }
    }

}

void giveinfo(GTPTR T){
   queue<GTPTR> q;
   q.push(T);
   GTPTR tmp;
   while(!q.empty()){
    tmp = q.front(); q.pop();
    for(int i=0;i<10;i++)
        if(tmp->c[i]!=NULL) q.push(tmp->c[i]);
       int ar[20];
      // n=tmp->child;
       arrange(tmp, ar);
    for(int i=0;i<tmp->child;i++)
         tmp->c[ar[i]]->info=tmp->info+(i+1);
   }

}

void print(GTPTR T) {
	if(T==NULL) return;
	cout<<T->data<<" ";
	cout<<"Info = "<<T->info<<endl;
	for(int i=0; i<10; i++)
    	print(T->c[i]);
}
int main(){
    int num;
	cout<<"Enter the root: ";
	cin>>num;
	GTPTR root = newnode(num);
	stack<GTPTR> s;
	s.push(root);
	create(s);
	calc(root);
	giveinfo(root);
	cout<<endl; print(root);
	//cout<<"\nThe height of the tree is: "<<height(root);
	//int ct=0;
	//childcount(root, ct);
	//cout<<"\nThe number of nodes = "<<ct;
	return 0;
}

