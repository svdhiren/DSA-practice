#include<iostream>
using namespace std;
struct gbtnode {
    char data;
	gbtnode* fc;
	gbtnode* ns;
};
typedef struct gbtnode* GBTPTR;

GBTPTR newnode(char k) {
	GBTPTR tmp = new gbtnode;
	tmp->data = k;
	tmp->fc = tmp->ns = NULL;
	return tmp;
}

GBTPTR create(char ch) {
	if(ch == '0') return NULL;
	
	GBTPTR T = newnode(ch);
	cout<<"\nEnter the first child of "<<T->data<<" : ";
	cin>>ch;
    T->fc = create(ch);
	cout<<"\nEnter the sibling of "<<T->data<<" : ";
	cin>>ch;
	T->ns = create(ch);
	return T;
}

void print(GBTPTR T, int s){
	if(T==NULL) return;
	for(int i=0;i<s;i++) cout<<" ";
	cout<<T->data<<"\n";
	print(T->fc, s+1);
	print(T->ns, s);
}



int main() {
	GBTPTR root = NULL;
	char ch;
	cout<<"Enter the root of the tree: ";
	cin>>ch;
	root = create(ch);
	print(root, 0);
	return 0;
}


