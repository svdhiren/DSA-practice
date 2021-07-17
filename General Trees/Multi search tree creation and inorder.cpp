#include<iostream>
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
			
	}
	return T;
}


void inorder(MSTPTR T){
	if(T==NULL) return;
	int i;
	for(i=0;i<T->cnt;i++){
		inorder(T->c[i]);
		cout<<T->key[i]<<" ";
	}
	inorder(T->c[i]);
}

bool search(MSTPTR T, int key){
	if(T==NULL) return false;
	int i;
	for(i=0;i<T->cnt;i++){
		if(T->key[i] == key) return true;
		if(key < T->key[i]) return search(T->c[i], key);
	}
	if(i==T->cnt) return search(T->c[i], key);
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
//	cout<<"\n"<<root->key[2]<<endl;
//	cout<<root->c[0]->key[2];
    inorder(root);
    cout<<"\nEnter the value to be found: ";
    cin>>k;
    if(search(root, k)) cout<<"Found!";
    else cout<<"Not found...";
	return 0;	
}
