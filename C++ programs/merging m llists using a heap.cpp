#include<iostream>
using namespace std;
struct node{
	int data;
    node* next;
};
typedef struct node* LPTR ;
struct heap {
	int num;
	int index;
};
LPTR newnode(int k){
	LPTR tmp = new node;
	tmp->data=k;
	tmp->next=NULL;
	return tmp;
}
LPTR create(int ar[], int n,int i){
	
	if(i==n) return NULL;
	LPTR L = newnode(ar[i++]);
    L->next = create(ar, n, i);
	
	return L;	
}

void perup(heap H[], int &s, int ele, int index){
	if(s==0){
		H[0].num = ele;
		H[0].index = index;
		s++;
		return;
	}
	H[s].num=ele;
	H[s].index=index;
	int i=s;
	while(H[i].num < H[(i-1)/2].num  && i>0){
		heap temp=H[(i-1)/2];
		H[(i-1)/2]=H[i];
		H[i]=temp;
	}
	s++;
}

int perdown(heap H[], int &s, LPTR head[]){
	int res = H[0].num;
	if(head[H[0].index]->next !=NULL){
		head[H[0].index] = head[H[0].index]->next;
		H[0].num = head[H[0].index]->data;
	}
	else{
		H[0]=H[--s];
	}
	int i=0;
	while(2*i+1 < s){
		if(2*i+2 < s)
		{
			if(H[i].num > H[2*i+1].num || H[i].num > H[2*i+2].num)
			{
				if(H[2*i+1].num < H[2*i+2].num)
				{
					heap tmp = H[2*i+1];
					    H[2*i+1] = H[i];
					    H[i]=tmp;
					    i = 2*i+1;
				}
				else
				{
					heap tmp = H[2*i+2];
					    H[2*i+2] = H[i];
					    H[i]=tmp;
					    i = 2*i+2;
				}
			}
			else break;
		}
		else{
			if(H[i].num > H[2*i+1].num)
			{
				heap tmp = H[2*i+1];
					H[2*i+1] = H[i];
					H[i]=tmp;
					i = 2*i+1;
			}
			else break;
		}
	}
	return res;
}

void sort_mlists(heap H[], int s, int sort[], LPTR head[]){
	static int j=0;
	while(s!=0){
		sort[j++]= perdown(H, s, head);
	}
	
}
void print(LPTR T){
	if(T==NULL) return;
	cout<<T->data<<" ";
	print(T->next);
}

int main() {
	heap H[50];
	int m, size, hsize=0, a[50], total=0;
/*	cout<<"Enter the size of the array: ";
	cin>>size;
	for(int j=0;j<size;j++) cin>>a[j];
	LPTR head = create(a, size);
	cout<<"\nThe list is: ";
	print(head);
	cout<<"\n"<<head->next->next->data<<"\n"<<head->next->next->next->next->data;
*/	cout<<"Enter the number of lists: ";
	cin>>m;
	LPTR head[50];
	for(int i=0;i<m;i++){
		cout<<"\nEnter the number of elements of list "<<i+1<<" : ";
		cin>>size;
		total+=size;
		cout<<"\nEnter...";
		for(int j=0;j<size;j++) cin>>a[j];
		cout << "\n";
		for(int j=0;j<size;j++) cout<<a[j];
		head[i] = create(a, size,0);
		cout<<"\n";
		print(head[i]);
	}
	for(int i=0; i<m;i++){   //Adding the first elements of every list to the heap.
		perup(H, hsize, head[i]->data, i);
	}
	int sort[50];
	sort_mlists(H, hsize, sort, head);
	
	cout<<"\nThe sorted list is given by: ";
	for(int i=0; i<total; i++) cout<<sort[i]<<" ";
	return 0;
}

