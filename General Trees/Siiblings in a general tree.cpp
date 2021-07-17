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

 void sibling( GBTPTR T, char ch, GBTPTR ar[], int n) {
 	if(T==NULL) return;
 	if(T->data == ch){
 		ar[n++]=T;
 		int i;
 		for(i=n-2;i>=0;i--) if(ar[i]->ns != ar[i+1]) break;
 		i++;
 		while(T->ns != NULL) {
 			ar[n++]=T->ns;
 			T=T->ns;
		 }
		cout<<"\nSiblings of "<<ch<<" are: ";
		for(int j=i;j<n;j++) cout<<ar[j]->data<<" "; 
	 }
	 ar[n++]=T;
	 sibling(T->fc,ch, ar, n);
	 if(T->ns == NULL) return;
	 sibling(T->ns,ch, ar, n);
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
	cout<<endl;
	cout<<"\nEnter the character whose sibling is to be found: ";
	cin>>ch;
	GBTPTR ar[30];
	sibling(root,ch, ar, 0);
	return 0;
}
