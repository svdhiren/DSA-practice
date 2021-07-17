#include<iostream>
#include<queue>
using namespace std;
struct stnode {
	int data;
	stnode* lc;
	stnode* rc;
};
typedef stnode* STPTR;

int getsum(int ar[], int l, int h){
	int s=0;
	for(int i=l;i<=h;i++) s+=ar[i];
	return s;
}

STPTR newnode_St(int k){
	STPTR tmp = new stnode;
	tmp->data = k;
	tmp->lc = tmp->rc = NULL;
	return tmp;
}

STPTR construct_St(int ar[], int s, int e){
	STPTR T = newnode_St(getsum(ar, s, e));
	if(s==e) return T;
	T->lc = construct_St(ar, s, s + (e-s)/2);
	T->rc = construct_St(ar, s + (e-s)/2 + 1, e);
	return T;
}

int sumofrange(STPTR T, int s, int e, int i1, int i2){
	if(T == NULL) return 0;
	else if((s==e) || ((i1==s)&&(i2==e))) return T->data;
	
	else if(i2 <= s+(e-s)/2)
	   return sumofrange(T->lc, s, s+(e-s)/2, i1, i2);
	else if(i1 >= s+(e-s)/2+1)
	   return sumofrange(T->rc, s+(e-s)/2+1, e, i1, i2);
	else return (sumofrange(T->lc, s, s+(e-s)/2, i1, s+(e-s)/2) + sumofrange(T->rc, s+(e-s)/2+1, e, s+(e-s)/2+1,i2));   
}

void levelwise(queue<STPTR> q){
	if(q.empty()) return;
	STPTR tmp = q.front(); q.pop();
	cout<<tmp->data<<" ";
	if(tmp->lc!=NULL) q.push(tmp->lc);
	if(tmp->rc!=NULL) q.push(tmp->rc);
	if(q.front()->data == 0){
		cout<<"\n";
		STPTR t = q.front(); q.pop();
		if(!q.empty()) q.push(t);
	}
	levelwise(q);
}



int main() {
	STPTR root = NULL;
	int n, ar[20];
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Start entering...\n";
	for(int i=0;i<n;i++){
		cout<<"Enter: ";
		cin>>ar[i];
	}
	root = construct_St(ar, 0, n-1);
	STPTR t = newnode_St(0);
	queue<STPTR> q;
	q.push(root);
	q.push(t);
	levelwise(q);
	int i1, i2;
	cout<<"\nEnter the range: ";
	cin>>i1>>i2;
	cout<<"\nThe sum of the given range is: "<<sumofrange(root, 0, n-1, i1, i2);
	return 0;
	
}
