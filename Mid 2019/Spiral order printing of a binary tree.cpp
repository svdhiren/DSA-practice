#include<iostream>
#include<queue>
#include<stack>
int l=0;
using namespace std;
struct btnode {
	int data;
	btnode* lc;
	btnode* rc;
};
typedef struct btnode* BTPTR;
BTPTR create(int ar[], int n){
	static int i=0;
	if(i==n || ar[i]==0)
	{
		return NULL;
	}
	BTPTR T= new btnode;
	T->data=ar[i];
	T->lc=T->rc=NULL;
	i++;
	T->lc=create(ar, n);
	i++;
	T->rc=create(ar,  n);
	
	return T;
}

void print(BTPTR t){
	if(t==NULL) return;
	cout<<t->data<<" ";
	print(t->lc);
	print(t->rc);
}

void store_the_levels(queue<BTPTR> q, stack<int> s[]){
    BTPTR T;
    
	while(!q.empty()){
	    T = q.front(); q.pop();
	    s[l].push(T->data);
	  cout<<T->data<<" ";
	    if(T->lc != NULL) q.push(T->lc);
	    if(T->rc != NULL) q.push(T->rc);
	    if(q.front()->data == 0){
	    	l++;
	    cout<<endl;
			BTPTR t = q.front(); q.pop();
	    	if(q.size()==0) {
	    		
	    		break;
			}
	    	else q.push(t);
		}
	    }
}
 void print_stack(stack<int> S[], int x, int a){
   	if(S[x].size()==0) return;
   	   int yo = S[x].top(); S[x].pop();
   	   if(a==0){
   	      print_stack(S, x, a);
   	      cout<<yo<<" ";
		  }
       else{
   	      cout<<yo<<" ";
   	      print_stack(S, x, a);
	   }
   }

void print_spiral(stack <int> s[]){
	int i, j;
	cout<<"\n";
	for(i=0, j=l-1; i<=j ; ++i, --j){
		print_stack(s, i, 0);
		if(i==j) break;
		print_stack(s, j, 1);
	}

	
}

int main() {
	BTPTR root = new btnode;
	root=NULL;
	int size;
	size =13 ;
	int arr[]={5,1,2,0,0,3,0,0,7,6,0,0,0};
	root = create(arr, size);
//	print(root);
	queue<BTPTR> q;
	BTPTR t = new btnode;
	t->data = 0;
	t->lc=t->rc=NULL;
	q.push(root);
	q.push(t);
	stack <int> s[10];
	store_the_levels(q, s);
	cout<<"\nNumber of levels = "<<l<<endl;
	while(s[2].size()!=0){
		cout<<s[2].top()<<" ";
		s[2].pop();
	}
//	cout<<endl; print(root); cout<<endl;
//	cout<<root->lc->lc->rc->lc->data;
	print_spiral(s);
//	cout<<"\nThe last element of level 4 is: "<<s[1].top();
	
}
