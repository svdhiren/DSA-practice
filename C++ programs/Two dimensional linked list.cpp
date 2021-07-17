#include<iostream>
using namespace std;
struct rnode;
struct snode {
	int snum;
	rnode* cnext;
};
struct cnode{
	int cnum;
	rnode* snext;
};
union rs{
	rnode* r1;
	snode* s;
};
union rc{
	rnode* r2;
	cnode* c;
};
struct rnode{
	int flagrs;
	int flagrc;
	rs objrs;
	rc objrc;
};
int main() {
	
snode S[5];
cnode C[5];
int n, cno, sno;
for(int i=0;i<5;i++) {
	S[i].cnext=NULL;
	S[i].snum=i+1;
}
for(int i=0;i<5;i++) {
	 C[i].snext=NULL;;
	 C[i].cnum=i+1;
}
rnode* head=NULL;
rnode* head2=NULL;
for(int i=0;i<5;i++){
   cout<<"Enter the number of courses for student  S"<<i+1<<": ";
   cin>>n;
   for(int j=1;j<=n;j++) 
   {
   	cout<<"Enter the course number: ";
   	cin>>cno;
   	cno--;
   	if(C[cno].snext==NULL){
   		rnode* T= new rnode;
   		T->flagrc=-1;
		C[cno].snext=T;
   	
   		if(head==NULL) head=T;
   		else{
   			head->flagrs=1;
   			head->objrs.r1=T;
   			head=T;
		   }
	  if(S[i].cnext==NULL) S[i].cnext=T;
	   }
   else {
   if(S[i].cnext==NULL){
   	rnode* T= new rnode;
   	T->flagrc=-1;
   	S[i].cnext=T;
   	head2=C[cno].snext;
   	while(head2->flagrc!=-1) head2=head2->objrc.r2;
   	head2->flagrc=1;
   	head2->objrc.r2=T;
   	head=T;
   }
   else{
   
   	rnode* T= new rnode;
   	T->flagrc=-1;
   	head2=C[cno].snext;
   	while(head2->flagrc!=-1) head2=head2->objrc.r2;
   	head2->flagrc=1;
   	head2->objrc.r2=T;
   	head->flagrs=1;
   	head->objrs.r1=T;
   	head=T;
   }
}
   if(j==n){
   	head->flagrs=0;
   	head->objrs.s=&S[i];
   }
    }
	 }

for(int i=0;i<5;i++){
	head2=C[i].snext;
	while(head2->flagrc!=-1) head2=head2->objrc.r2;
	head2->flagrc=0;
	head->objrc.c=&C[i];
}


cout<<"\nEnter the student number to know his courses: ";
cin>>sno;
head=S[sno-1].cnext;
cout<<endl;
/*while(1){
	cout<<"yo";
    if(head->flagrs==0){
	head2=head;
	while(head2->flagrc!=0) head2=head2->objrc.r2;
	cout<<head2->objrc.c->cnum<<" ";
	break;
}
	head2=head;
	while(head2->flagrc!=0) head2=head2->objrc.r2;
	cout<<head2->objrc.c->cnum<<" ";
	head=head->objrs.r1;
} */
cout<<head->objrc.c->cnum;
   return 0;  	
}	
	
	
	


