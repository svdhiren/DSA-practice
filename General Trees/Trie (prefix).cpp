#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
struct trnode;
struct str {
  char s[10];
  int si;
  int p;
};
union u
{
    trnode* ptr[10];
    str S;
};
struct trnode
{
    int fl;
    u obj;
};
typedef trnode* TPTR;
char A[10];
int n;

TPTR newnode(int f){

  TPTR tmp = new trnode;
  tmp->fl=f;
  if(f==1){
    for(int i=0;i<10;i++){
        tmp->obj.ptr[i]=NULL;
    }
  }
  else {
    tmp->obj.S.p=0;
    tmp->obj.S.si=0;
  }
  return tmp;
}

int findindex(char al)
{
    for(int i=0;i<9;i++)
        if(al==A[i])
         return i;
}

TPTR new_leafnode(char key[], int k, int a){
  TPTR t = newnode(0);
      for(int i=0;i<k;i++)
          t->obj.S.s[i] = key[i];
      t->obj.S.si=k;
      t->obj.S.p=a;
      return t;
}

TPTR insertstring(TPTR T, char key[], int k, int &a){
   if(T==NULL){
      T = newnode(1);
      int in = findindex(key[a]);
      T->obj.ptr[in] = new_leafnode(key, k, a);
      return T;
   }
   if(T->fl==1){
    int in;
    if(a==k) in = 9;
    else
    in = findindex(key[a]);
    if(T->obj.ptr[in]==NULL){
      T->obj.ptr[in] = new_leafnode(key, k, a);
      return T;
    }
    else {
        T->obj.ptr[in] = insertstring(T->obj.ptr[in], key, k, ++a);
        return T;
    }
   }
   else{
    TPTR temp = T;
    T = newnode(1);
    int j = ++temp->obj.S.p;
    int in;
    if (j == temp->obj.S.si) in = 9;
    else in = findindex(temp->obj.S.s[j]);
    T->obj.ptr[in] = temp;
    in = findindex(key[a]);
    if(T->obj.ptr[in]==NULL){
      T->obj.ptr[in] = new_leafnode(key, k, a);
      return T;
    }
    else {
        T->obj.ptr[in] = insertstring(T->obj.ptr[in], key, k, ++a);
        return T;
    }
   }

  }

void deletestring(TPTR T, TPTR P, char key[], int siz, int i)
{
    if(T->fl==0 || i==siz){
        cout<<"\nWord found!";
        P->obj.ptr[i-1]=NULL;
    }
    else{
        deletestring(T->obj.ptr[i], T, key, siz, i+1);
    }
    if(T->fl==0){ delete T; return;}
    int ct=0;
    for(int j=0;j<10;j++)
        if(T->obj.ptr[j]!=NULL)
           ct++;
    if((ct>=2) || (ct==1 && P==NULL)) return;
    for(int j=0;j<10;j++);

}

  void printstring(TPTR T){
  if(T==NULL) return;
  if(T->fl==0){
    for(int i=0;i<T->obj.S.si;i++)
         cout<<T->obj.S.s[i];
         cout<<"\n";
    return ;
  }
  for(int i=0;i<10;i++)
     printstring(T->obj.ptr[i]);
  }

int main()
{
    TPTR root = NULL;
    cout<<"Enter the number of letters: ";
    cin>>n;
    cout<<"Enter the letters: ";
   for(int i=0;i<n;i++) cin>>A[i];
   char key[10];
   int k;
   cout<<"Start entering the keys...\n";
   while(1){
    cout<<"Enter the size of the key: ";
        cin>>k;
        if(k==0) break;
        cout<<"Enter the key: ";
        gets(key);
        int i=0;
     root = insertstring(root, key, k, i);
     cout<<"\n";
   }
   cout<<"\nThe strings in the trie are: \n";
   printstring(root);
}
