#include<iostream>
#include<queue>
using namespace std;
struct gtnode {
	int data;
	gtnode* c[10];
};
typedef struct gtnode* GTPTR;

GTPTR newnode(int k) {
	GTPTR tmp = new gtnode;
	tmp->data=k;
	for(int i=0;i<10;i++)
	    tmp->c[i]=NULL;
	return tmp;
}

void create(queue<GTPTR> q){
	if(q.size()==0) return;
	int n, num;
	GTPTR tmp = q.front(); q.pop();
	cout<<"\nEnter the number of children for "<<tmp->data<<" : ";
	cin>>n;
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
	for(int i=0; i<10; i++)
    	print(T->c[i]);

}

int main() {
	int num;
	cout<<"Enter the root: ";
	cin>>num;
	GTPTR root = newnode(num);
	queue<GTPTR> q;
	q.push(root);
	create(q);
	cout<<endl; print(root);
	return 0;
}
