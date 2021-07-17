#include<iostream>
#include<queue>
using namespace std;
struct bdnode {
	int cnt;
	int key[50];
	bdnode* p;
	bdnode* ptr[50];
};
typedef bdnode* BDPTR;
int d;

BDPTR newnode(int key) {
	BDPTR tmp = new bdnode;
	tmp->cnt=1;
	tmp->key[0] = key;
	for(int i=0;i<50;i++) tmp->ptr[i]=NULL;

	return tmp;
}

bool isleaf(BDPTR T){
	for(int i=0; i<=T->cnt;i++)
	   if(T->ptr[i]!=NULL)
	      return false;
	return true;
}

void sort(BDPTR t){
	for(int i=0;i<t->cnt;i++){
		for(int j=0;j<t->cnt-1;j++){
			if(t->key[j] > t->key[j+1]){
				int tmp = t->key[j];
				t->key[j] = t->key[j+1];
				t->key[j+1] = tmp;
			}

		}
	}
}

void addnode(BDPTR T, int k, BDPTR p, BDPTR &root, int call) {

	if(T==NULL){
		T = newnode(k);
		root = T;
		return;
	}

	if(isleaf(T)){
		T->key[T->cnt] = k;
	    T->cnt++;
	    sort(T);
	}

	else{
		int i;
		for(i = 0; i<T->cnt;i++)
		{
		if(k < T->key[i])
		    {
		    	addnode(T->ptr[i], k, T, root, call+1);
		    	break;

			}

	    }
	    if(i==T->cnt) addnode(T->ptr[i], k, T, root, call+1);
	}

	if(T->cnt > 2*d)
	{

		if(isleaf(T) && p==NULL){

		//Splitting the node.
		BDPTR t = newnode(T->key[d]);
		int j=1;
			for(int i=d+1; i<2*d+1;++i, ++j){
				t->key[j] = T->key[i];
				t->cnt++;
			}
			int med = T->key[d];
			T->cnt = d;
			BDPTR tmp = newnode(med);
			tmp->ptr[0] = T;
			tmp->ptr[1] = t;
			root = tmp;
		//	T->ptr[2*d+1]=t;
	    }
	    else if(isleaf(T) && p!=NULL){
	    //Splitting the node and adding the median to the parent pointer.
		BDPTR t = newnode(T->key[d]);
		int j=1;
			for(int i=d+1; i<2*d+1;++i, ++j){
				t->key[j] = T->key[i];
				t->cnt++;
			}
			int med = T->key[d];
			T->cnt = d;
			int pos = -1;
			for(int i=0; i<p->cnt;i++){
				if(med < p->key[i]) {
					pos = i;
					break;
				}
			}
			if(pos==-1) pos = p->cnt;
			for(int i=p->cnt;i>pos;i--){
			p->key[i] = p->key[i-1];
			p->ptr[i+1] = p->ptr[i];
		}
		p->key[pos] = med;
		p->ptr[pos] = T;
		p->ptr[pos+1] = t;
		p->cnt++;
	//	t->ptr[2*d+1]=T->ptr[2*d+1];
	//	T->ptr[2*d+1]=t;

		}
		else if(!isleaf(T) && p==NULL){
			//Splitting the node and adjusting the pointers and then creating a new parent node.
			BDPTR t = newnode(T->key[d+1]);
			t->cnt--;
			int j=0, i;
			for(i=d+1; i<2*d+1;++i, ++j){
				t->key[j] = T->key[i];
				t->ptr[j] = T->ptr[i];
				t->cnt++;
			}
			t->ptr[j] = T->ptr[i];
			int med = T->key[d];
			T->cnt = d;
			BDPTR tmp = newnode(med);
			tmp->ptr[0] = T;
			tmp->ptr[1] = t;
			root = tmp;

		}
		else if(!isleaf(T)  && p!=NULL){
			//Splitting the node and adjusting the pointers and then adding median to the parent node.
			BDPTR t = newnode(T->key[d+1]);
			t->cnt--;
			int j=0, i;
			for(i=d+1; i<2*d+1;++i, ++j){
				t->key[j] = T->key[i];
				t->ptr[j] = T->ptr[i];
				t->cnt++;
			}
			t->ptr[j] = T->ptr[i];
			int med = T->key[d];
			T->cnt = d;
			int pos = -1;
			for(int i=0; i<p->cnt;i++){
				if(med < p->key[i]) {
					pos = i;
					break;
				}
			}
			if(pos==-1) pos = p->cnt;
			for(int i=p->cnt;i>pos;i--){
			p->key[i] = p->key[i-1];
			p->ptr[i+1] = p->ptr[i];
		}
		p->key[pos] = med;
		p->ptr[pos] = T;
		p->ptr[pos+1] = t;
		p->cnt++;

		}

	}


}
int l;
void level_order(queue<BDPTR> q){
	if(q.size()==0) return;
	BDPTR tmp = q.front(); q.pop();
	for(int i=0;i<tmp->cnt;i++) cout<<tmp->key[i]<<"-";

	cout<<"\b\t";
	for(int i=0;i<=tmp->cnt;i++){
		if(tmp->ptr[i]!=NULL) q.push(tmp->ptr[i]);
	}
	if(q.front()->key[0]==0){
		cout<<"\n";
		l++;
		BDPTR t = q.front();
		q.pop();
		if(q.size()!=0) q.push(t);
	}
	level_order(q);
}

void link(queue<BDPTR> q){

  if(q.size()==0) return;
	BDPTR tmp = q.front(); q.pop();

	for(int i=0;i<=tmp->cnt;i++){
		if(tmp->ptr[i]!=NULL) q.push(tmp->ptr[i]);
	}
	if(l==1){
	    if(q.front()->key[0]!=0)  {
            tmp->ptr[2*d+1]=q.front();

	    }
	}
	if(q.front()->key[0]==0){
		l--;
		BDPTR t = q.front();
		q.pop();
		if(q.size()!=0) q.push(t);
	}
	link(q);
}

int main() {
	int k;
	BDPTR r = NULL;
	cout<<"Enter the value of d: ";
	cin>>d;
	cout<<"Start entering...\n";
	while(1){
		cout<<"Enter: ";
		cin>>k;
		if(k==-1) break;
		addnode(r, k, NULL, r, 1);
	l=0;
	queue<BDPTR> q;
	q.push(r);
	BDPTR t = newnode(0);
	q.push(t);
	level_order(q);
	}

while(r->ptr[0]!=NULL) {
       r = r->ptr[0];
       }
while(r!=NULL){
    for(int i=0;i<r->cnt;i++) cout<<r->key[i]<<" ";
    r=r->ptr[2*d+1];
}



	return 0;
}



