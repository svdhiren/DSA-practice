#include<iostream>
#include<queue>
using namespace std;
struct mstnode {
	int cnt;
	int key[10];
	mstnode* c[10];
};
typedef struct mstnode* MSTPTR;

MSTPTR newnode(int key){
	MSTPTR tmp = new mstnode;
	tmp->cnt = 1;
	tmp->key[0]=key;
	for(int i=0;i<10;i++) tmp->c[i]=NULL;
	return tmp;
}

MSTPTR create(MSTPTR T, int key, int m) {
	if(T == NULL)  return newnode(key);
	if(T->cnt < (m-1)){
		T->key[T->cnt] = key;
		T->cnt++;
		for(int i=0; i<T->cnt;i++)
		{
			for(int j=0;j<T->cnt-1;j++)
			{
				if(T->key[j] > T->key[j+1])
				{
					int t = T->key[j];
					T->key[j] = T->key[j+1];
					T->key[j+1] = t;
				}
			}
		}
		return T;
	}
	else
	{  int i;
	   for(i=0; i<(m-1);i++)
	        if(key < T->key[i])
			{
	        	T->c[i] = create(T->c[i], key, m);
	        	break;
			}
		if(i == m-1) T->c[i] = create(T->c[i], key, m);
		return T;	
	}
	
}

void level_order(queue<MSTPTR> q){
	if(q.size()==0) return;
	MSTPTR tmp = q.front(); q.pop();
	for(int i=0;i<tmp->cnt;i++) cout<<tmp->key[i]<<"-";
	
	cout<<"\b\t";
	for(int i=0;i<=tmp->cnt;i++){
		if(tmp->c[i]!=NULL) q.push(tmp->c[i]);
	}
	if(q.front()->key[0]==0){
		cout<<"\n";
		MSTPTR t = q.front();
		q.pop();
		if(q.size()!=0) q.push(t);
	}
	level_order(q);
}

int main() {
	MSTPTR root = NULL;
	int n, k, m;
	cout<<"Enter the value of \'m\' : ";
	cin>>m;
	cout<<"\nEnter the number of elements: ";
	cin>>n;
	cout<<"\nStart entering: \n";
    for(int i=0;i<n;i++){
    	cout<<"Enter: ";
    	cin>>k;
    	root = create(root, k, m);
	}
	queue<MSTPTR> q;
	q.push(root);
	MSTPTR t = newnode(0);
	q.push(t);
	level_order(q);
}
