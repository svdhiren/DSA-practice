#include<iostream>
using namespace std;
struct node{
	int n;
	int e;
	struct node* next;
};
struct exp{
	int num;
	int ex;
	
};
typedef struct node* LPTR;
void addEnd(LPTR &head,LPTR &tail,LPTR &L,exp term)	// Addition at the END
{
LPTR T = new(struct node);

if(head==NULL)
{
T->n = term.num;
T->e= term.ex;
T->next = NULL;
head = T;
tail = T;
}
else
{
T->n = term.num;
T->e= term.ex;
T->next=NULL; 
tail->next = T;
tail = T;
}

}
void poladd(LPTR &h1, LPTR &h2, LPTR &h3, LPTR &t3){
	LPTR tmp1, tmp2, L;
	struct exp fterm;
	tmp1=h1;
	tmp2=h2;
	 while(tmp1!=NULL && tmp2!=NULL) {
	 
	    if(tmp1->e>tmp2->e) {
		fterm.num=tmp1->n;
		fterm.ex=tmp1->e;
		addEnd(h3, t3, L, fterm);
		tmp1=tmp1->next;
		}
		if(tmp1->e<tmp2->e){
		fterm.num=tmp2->n;
		fterm.ex=tmp2->e;
		addEnd(h3, t3, L, fterm);
		tmp2=tmp2->next;
		}
		if(tmp1->e==tmp2->e){
		fterm.num=tmp2->n + tmp1->n;
		fterm.ex=tmp2->e;
		addEnd(h3, t3, L, fterm);
		tmp2=tmp2->next;
		tmp1=tmp1->next;
		}
                              }
        while(tmp1!=NULL || tmp2!=NULL) {
        	if(tmp1->next!=NULL){
        fterm.num=tmp1->n;
		fterm.ex=tmp1->e;
		addEnd(h3, t3, L, fterm);
		tmp1=tmp1->next;
			}
			if(tmp2->next!=NULL){
			fterm.num=tmp2->n;
		fterm.ex=tmp2->e;
		addEnd(h3, t3, L, fterm);
		tmp2=tmp2->next;	
			}
		}                     
                          }
 void show(LPTR L,LPTR head)	
{
if(head!=NULL)
{
L = head;
while(L->next != NULL)
{
cout << L->n << "x^"<<L->e<<" + ";
L = L->next;
}
cout << L->n << "x^"<<L->e;
}
else
cout << "\n LIST IS EMPTY";
} 
                          
int main() {
	LPTR h1, t1, h2, t2, L;
	L=NULL;
	h1=NULL;
	t1=NULL;
	h2=NULL;
	t2=NULL;
	struct exp term;
	int size;
	cout<<"How many terms do you want to enter in the first polynnomial?";
	cin>>size;
	for(int i=0;i<size;i++){
		cout<<"\nEnter the coeff and expt: ";
		cin>>term.num>>term.ex;
		addEnd(h1,t1,L,term);
	}
	cout<<"\nHow many terms do you want to enter in the second polynnomial?";
	cin>>size;
	for(int i=0;i<size;i++){
		cout<<"\nEnter the coeff and expt: ";
		cin>>term.num>>term.ex;
		addEnd(h2,t2,L,term);
	}
	LPTR h3, t3;
	h3=NULL;
	t3=NULL;
	poladd(h1, h2, h3, t3);
	show(L, h3);
	return 0;
	
}
