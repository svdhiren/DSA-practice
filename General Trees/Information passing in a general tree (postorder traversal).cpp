#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct gtnode {
	char data;
	gtnode* c[10];
	int cnt;
	int clik;
	int info;
};
typedef struct gtnode* GTPTR;

GTPTR newnode(char k) {
	GTPTR tmp = new gtnode;
	tmp->data=k;
	tmp->cnt=0;
	tmp->clik=0;
	tmp->info=0;
	for(int i=0;i<10;i++)
	    tmp->c[i]=NULL;
	return tmp;
}

void create(stack<GTPTR> s){
	if(s.size()==0) return;
	GTPTR T = s.top(); s.pop();
	int n;
	char num;
	cout<<"\nEnter the number of children for "<<T->data<<" : ";
	cin>>n;
	T->cnt=n;
	for(int i=0; i<n;i++){
		cout<<"Enter the child "<<i+1<<" of "<<T->data<<" : ";
		cin>>num;
		T->c[i] = newnode(num);
	}
	for(int i = n-1;i>=0;i--) s.push(T->c[i]);
	create(s);
}

int clicks(GTPTR T)
{
    if(T->c[0]==NULL){
        T->clik=0;
        return 0;
    }
    int m[10];
    for(int i=0;i<T->cnt;i++){
        m[i] = clicks(T->c[i]);
    }
    int maxi = m[0];
    for(int i=1;i<T->cnt;i++){
        if(m[i]>maxi) maxi = m[i];
    }
    T->clik = maxi>T->cnt ? maxi : T->cnt;
    return (T->clik+1);
}

void arrange(GTPTR C, int ar[]) {
    for(int i=0;i<C->cnt;i++) ar[i]=i;
    for(int i=0;i<C->cnt;i++){
        for(int j=0;j<C->cnt-1;j++){
            if(C->c[ar[j]]->clik < C->c[ar[j+1]]->clik)
                swap(ar[j], ar[j+1]);
            }
    }

}

void giveinfo(GTPTR T){
   queue<GTPTR> q;
   q.push(T);
   GTPTR tmp;
   while(!q.empty()){
    tmp = q.front(); q.pop();
    for(int i=0;i<10;i++)
        if(tmp->c[i]!=NULL) q.push(tmp->c[i]);
       int ar[20];
      // n=tmp->child;
       arrange(tmp, ar);
    for(int i=0;i<tmp->cnt;i++)
         tmp->c[ar[i]]->info=tmp->info+(i+1);
   }

}

void print(GTPTR T) {
	if(T==NULL) return;
	cout<<T->data<<" - "<<T->info<<"\n";
	for(int i=0; i<10; i++)
    	print(T->c[i]);

}

void Info(GTPTR T, GTPTR P, int yo){
  if(T==NULL) return;
  if(T->info==yo)
     cout<<P->data<<T->data<<"  ";
  for(int i=0;i<T->cnt;i++)
    Info(T->c[i], T, yo);

}

int main(){
    char num;
	cout<<"Enter the root: ";
	cin>>num;
	GTPTR root = newnode(num);
	stack<GTPTR> s;
	s.push(root);
	create(s);
	int cl = clicks(root)-1;
	giveinfo(root);
    print(root);
    cout<<"\nThe number of iterations = "<<cl;
    for(int i=1;i<=cl;i++){
        cout<<"\nThe pairs which got information in iteration "<<i<<" are: ";
        Info(root, NULL, i);
    }
	return 0;
}


