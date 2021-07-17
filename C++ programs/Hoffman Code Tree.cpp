#include<iostream>
using namespace std;
struct hfcnode{
int flag, freq;
string str;
hfcnode* lc;
hfcnode* rc;
};
typedef struct hfcnode* HFPTR ;

HFPTR newnode(){
HFPTR h = new hfcnode;
h->str="";
h->flag=0;
h->freq=0;
h->lc = h->rc = NULL;
return h;
}

void perup(HFPTR ele, HFPTR H[], int &s){
if(s==0){
H[s]=ele;
s++;
return;
}
H[s]=ele;
int i=s;
while(H[i]->freq < H[(i-1)/2]->freq && i>0){
HFPTR tmp = H[i];
H[i]=H[(i-1)/2];
H[(i-1)/2] = tmp;
i=(i-1)/2;
}
s++;
}
HFPTR perdown(HFPTR H[], int &s){
HFPTR res = H[0];
H[0] = H[--s];
int i=0;
while(2*i+1 < s){
		if(2*i+2 < s)
		{
			if(H[i]->freq > H[2*i+1]->freq || H[i]->freq > H[2*i+2]->freq){
				if(H[2*i+1]->freq < H[2*i+2]->freq)
				{
					swap(H[2*i+1], H[i]);
					i = 2*i+1;
				}
				else
				{
					swap(H[2*i+2], H[i]);
					i = 2*i+2;
				}
			}
			else break;
		}
		else{
			if(H[i]->freq > H[2*i+1]->freq)
			{
				swap(H[2*i+1], H[i]);
				i = 2*i+1;
			}
			else break;
		}
	}
return res;
}

HFPTR create_tree(HFPTR H[], int s){
 HFPTR temp;
 while(s!=0){
 HFPTR T = newnode();
 temp = perdown(H, s);
 T->lc = temp;
 T->freq+=temp->freq;
 if(s!=0){
 temp = perdown(H, s);
 T->rc = temp;
 T->freq+=temp->freq;
 }
 if(s==0) return T;
 else perup(T, H, s);
 }
}

void print(HFPTR T, int ar[], int n){
	if(T==NULL) return;
	if(T->flag==1)
	{
		cout<<"\nCode for "<<T->str<<" is: ";
		for(int i=0; i<n; i++) cout<<ar[i];
	}
	if(T->lc!=NULL) ar[n++]=0;
		print(T->lc, ar, n);
		n--;
		if(T->rc !=NULL) ar[n++]=1;
		print(T->rc, ar, n);
	}
int main() {
HFPTR a[50], H[50];
int size, hsize=0;
cout<<"Enter the size of the code array: ";
cin>>size;
cout<<"\nEnter the elements: ";
for(int i=0; i<size; i++){
a[i] = newnode();
a[i]->flag=1;
cout<<"\nEnter character: ";
cin>>a[i]->str;
cout<<"\nEnter frequency: ";
cin>>a[i]->freq;
perup(a[i], H, hsize);
}
HFPTR root = create_tree(H, hsize);
int ar[50];
print(root, ar, 0);
return 0;
}
