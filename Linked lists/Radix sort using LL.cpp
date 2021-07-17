#include<iostream>
#include<cmath>
using namespace std;
struct node{
	int data;
	struct node* next;
};
typedef struct node* LPTR;
void addEnd(LPTR &head,LPTR &tail,LPTR &L,int x)	// Addition at the END
{
LPTR T = new(struct node);

if(head==NULL)
{
T->data = x;
T->next = NULL;
head = T;
tail = T;
}
else
{
T->data=x;
T->next=NULL; 
tail->next = T;
tail = T;
}

}

int delAtFront(LPTR &head,LPTR &L,LPTR &tail)	// Deletion at the FRONT
{
int x;
if(head == NULL)
{

x =-1;
}
else
{
if(head == tail)
{
x = head->data;
head = tail = NULL;
}
else
{
x = head->data;
head = head->next;
}
}
return x;
}

int main() {
	LPTR head[10], tail[10], L;
	for(int i=0;i<10;i++) {
		head[i]=NULL;
		tail[i]=NULL;
	}
	L=NULL;
	int ar[50], size;
	int temp , tmp[50];
	cout<<"Enter the number of elements: "; cin>>size;
	for(int i=0; i<size;i++) {
		cout<<"\nEnter: "; cin>>ar[i];
		tmp[i]=ar[i];
	}
	for(int i=1;i<=3;i++){
		
		for(int j=0;j<size;j++) {
			temp=tmp[j]%10;
			addEnd(head[temp], tail[temp], L, ar[j] );
		}
		int t, k=0, l=0;
			while(l<10){
				t=delAtFront(head[l], L, tail[l]);
				if(t!=-1) { ar[k]=t; tmp[k]=ar[k]; tmp[k]/=pow(10,i); k++;}
				else l++;
			}
		}
	cout<<"\nThe sorted list is: ";
	for(int i=0;i<size;i++) cout<<ar[i]<<" ";
	return 0;	
}
