#include<iostream>
using namespace std;

struct trnode {
    trnode* ptr[26];
    int yo;
};
typedef struct trnode* TPTR ;

TPTR newnode(){
    TPTR tmp = new trnode;
    for(int i=0;i<26;i++) {
        tmp->ptr[i]=NULL;
    }
    tmp->yo=0;
}

TPTR addword(TPTR T, char ar[], int n, int &i){
    if(i==n) {
        TPTR t = newnode();
        t->yo=1;
        return t;
    }
    if(T==NULL){
        T = newnode();
        int a = ar[i];
        a=a-97;
        T->ptr[a]=addword(T->ptr[a], ar, n, ++i);
        return T;
    }
    int b = ar[i];
    b=b-97;
    T->ptr[b]=addword(T->ptr[b], ar, n, ++i);
    return T;
 }

 void printpath(TPTR T, char ar[], int n){
     //if(T==NULL) return ;
     if(T->yo==1){
        for(int i=0;i<n;i++) cout<<ar[i];
          cout<<endl;
     }
     for(int i=0;i<26;i++)
     {
       if(T->ptr[i]!=NULL)
        {
         ar[n++] = char(97+i);
         printpath(T->ptr[i], ar, n);
         n--;
       }

     }

 }

 bool search_string(TPTR T, char key[], int n, int &i){
    if(T==NULL) return false;
	if(i==n){
        if(T->yo==1) return true;
        else
            return false;
    }
    int b = key[i];
    b=b-97;
    return search_string(T->ptr[b], key, n, ++i);
 }

int main(){
    char ar[20];
    int n;
    TPTR root=NULL;
    cout<<"Start entering the keys...\n";
    while(1){
        cout<<"Enter the size of the key: ";
        cin>>n;
        if(n==0) break;
        cout<<"Enter the key: ";
        for(int i=0;i<n;i++) cin>>ar[i];
        int i=0;
       root = addword(root, ar, n, i);
    }
   printpath(root, ar, 0);
   cout<<"\nEnter the size of the key to be searched : ";
   cin>>n;
   cout<<"Enter the key: ";
   for(int i=0;i<n;i++) cin>>ar[i];
   int i=0;
   if(search_string(root, ar, n, i))
     cout<<"\nThe string is present!!";
   else cout<<"\nThe string couldn't be found...";
     return 0;
}
