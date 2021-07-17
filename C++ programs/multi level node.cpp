#include<iostream>
using namespace std;
struct mlnode{
	int data;
	mlnode* dlink;
	mlnode* next;
};
typedef struct mlnode* MLPTR;

void enterdown(MLPTR &t, int y){
	MLPTR T2=new(struct mlnode);
	T2->data=y;
	T2->next=NULL;
	T2->dlink=NULL;
	t->dlink=T2;
	t=T2;
}

void enter(MLPTR &head, MLPTR &tail){
	int x, y, choice;
	while(1){
	MLPTR T1 = new(struct mlnode);
	cout<<"\nEnter horizontal element: ";
	cin>>x;
	if(x==-1) {   delete T1; return; }
	if(head==NULL){
		T1->data=x;
		T1->next=NULL;
		T1->dlink=NULL;
		head=T1;
		tail=T1;
	}
	else{
		T1->data=x;
		T1->next=NULL;
		T1->dlink=NULL;
		tail->next=T1;
		tail=T1;
	  }
	 cout<<"\nDo you want a downlink? (1-yes, 0-no) ";
	 cin>>choice;
	 if(choice==1){
	 	MLPTR tmp=T1;
	 	while(1){
	 	cout<<"\nEnter down: "; cin>>y;
	 	if(y==-1) break;
	 	enterdown(tmp, y);
	   }
	 } 
	 
	}
}

void display(MLPTR head){
	if(head==NULL) return;
	if(head->next==NULL){
		if(head->dlink==NULL) return;
		else{
			while(head!=NULL){
				cout<<head->data<<" ";
				head=head->dlink;
			}
			return ;
		}
	}
	else{
		cout<<head->data<<" ";
		if(head->dlink!=NULL){
			MLPTR tmp=head->dlink;
			while(tmp!=NULL){
				cout<<tmp->data<<" ";
				tmp=tmp->dlink;
			}
		}
		
	}
	display(head->next);
}

int main(){
	MLPTR head, tail;
	head=NULL;
	tail=NULL;
	
enter(head, tail);
display(head);
return 0;
	
}
