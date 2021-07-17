#include<iostream>
using namespace std;
struct gtnode {
	char data;
	gtnode* c[10];
};
typedef struct gtnode* GTPTR;

GTPTR newnode(char k) {
	GTPTR tmp = new gtnode;
	tmp->data=k;
	for(int i=0;i<10;i++)
	    tmp->c[i]=NULL;
	return tmp;
}

GTPTR create(char ar[]) {
	static int i=0;
	GTPTR T = newnode(ar[i++]);
	if(ar[i]==')') return T;
	for(int j=0; j<10;j++){
		T->c[j] = create(ar);
		i++;
		if(ar[i]==')') return T;
	}

}

void print(GTPTR T) {
	if(T==NULL) return;
	cout<<T->data<<" ";
	for(int i=0; i<10; i++)
    	print(T->c[i]);

}

int main() {
	char ar[] = {'A','M','B',')','D','Q',')','R',')',')','E',
	')',')','J','H',')',')','P','S','U',')','V',')','G',')',')','T',')',')',')'};
	GTPTR root = create(ar);
	cout<<endl; print(root);
	cout<<"\n"<<root->c[2]->c[0]->c[1]->data;
	return 0;
}
