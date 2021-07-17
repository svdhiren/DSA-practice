#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

struct btnode;
struct node;
struct bt
{
    int data;
    btnode* lc;
    btnode* rc;
};
union u
{
    bt info;
    node* L;
};
struct btnode
{
    int fl;
    u obj;
};
struct node{
int num;
node* next;
};
typedef btnode* BTPTR;
typedef node* LPTR;

LPTR addnode(int ar[], int n, int i)
{
   if(i==n)
     return NULL;
   LPTR h = new node;
   h->num=ar[i++];
   h->next=addnode(ar, n, i);
   return h;

}

BTPTR createwinner(LPTR H[], int l)
{
    queue<BTPTR> q;
    for(int i=0;i<l;i++){
        BTPTR tmp = new btnode;
        tmp->fl=0;
        tmp->obj.L=H[i];
        q.push(tmp);
    }
    BTPTR tmp;
    while(1){
        tmp = new btnode;
        tmp->fl=1;
        tmp->obj.info.lc=tmp->obj.info.rc=NULL;
        tmp->obj.info.data=0;
        tmp->obj.info.lc=q.front(); q.pop();
        tmp->obj.info.rc=q.front(); q.pop();
        if(q.empty()) return tmp;
        else q.push(tmp);
    }
}

void print(BTPTR T){
if(T->fl==0){
    if(T->obj.L!=NULL)
        cout<<T->obj.L->num<<" "<<T->fl<<endl;
    else cout<<-1<<" ";
    return;
}
cout<<T->obj.info.data<<" "<<T->fl<<endl;
print(T->obj.info.lc);
print(T->obj.info.rc);
}


void printLL(LPTR L){
if(L==NULL) return;
cout<<L->num<<" ";
printLL(L->next);

}

int pop(BTPTR T)
{
    if(T->fl==0){
        if(T->obj.L==NULL) return -1;
        int r = T->obj.L->num;
        T->obj.L=T->obj.L->next;
        return r;
    }
   int m1 = pop(T->obj.info.lc);
   int m2 = pop(T->obj.info.rc);
   if(m1==-1 && m2==-1)
        return -1;
   if(m1==-1 || m2==-1)
      return (m2!=-1?m2:m1);
   return (m1<m2?m1:m2);

}

int getmedian(BTPTR T, int siz)
{   cout<<siz<<"\n";
    int med;
    while(siz>0){
        med=pop(T);
        cout<<med<<" ";
        siz--;
    }
    return med;
}

int main()
{
    int l, n, m, siz=0, ar[20];
    BTPTR root=NULL;
    LPTR H[10];
    cout<<"Enter the number of linked lists: ";
    cin>>m;
    for(l=0;pow(2,l)<m;l++);
    l=pow(2,l);
    for(int i=0;i<l;i++) H[i]=NULL;
    cout<<"Start entering the lists in ascending order...\n";
    for(int i=0;i<m;i++){
        cout<<"Enter the size of the LL "<<i+1<<" : ";
        cin>>n;
        siz+=n;
        for(int j=0;j<n;j++){
            cout<<"Enter: ";
            cin>>ar[j];
        }
        H[i]=addnode(ar, n, 0);
        cout<<"\n";
       // printLL(H[i]);
    }
   root = createwinner(H, l);
   print(root);
   int med = getmedian(root, siz);
 //  cout<<"\nMedian is:"<<med;
   return 0;
}
