#include<iostream>
using namespace std;

struct trnode {
    trnode* ptr[26];
    int yo[26];
};
typedef struct trnode* TPTR ;

TPTR newnode(){
    TPTR tmp = new trnode;
    for(int i=0;i<26;i++) {
        tmp->ptr[i]=NULL;
        tmp->yo[i]=0;
    }
}

TPTR addword(TPTR T, char ar[], int n, int &i){
    if(i==n) return T;
    if(T==NULL){
        T = newnode();
        int a = ar[i];
        a=a-97;
        if(i+1==n) T->yo[a]=1;
        T->ptr[a]=addword(T->ptr[a], ar, n, ++i);
        return T;
    }
    int b = ar[i];
    b=b-97;
    if(i+1==n) T->yo[b]=1;
    T->ptr[b]=addword(T->ptr[b], ar, n, ++i);
    return T;
 }

bool allNull(TPTR T){
 for(int i=0;i<26;i++)
     if(T->ptr[i]!=NULL)
        return false;
 return true;

}

 void NO_prefix(TPTR T, char ar[], int n){
     //if(T==NULL) return ;
     for(int k=0;k<26;k++)
    {
        if(T->yo[k]==1)
        {
          if(allNull(T)){
          ar[n++]=char(k+97);
          for(int i=0;i<n;i++) cout<<ar[i];
          cout<<endl;
          n--;
          }
        }
    }
     for(int i=0;i<26;i++)
     {
       if(T->ptr[i]!=NULL)
        {
         ar[n++] = char(97+i);
         NO_prefix(T->ptr[i], ar, n);
         n--;
       }

     }

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
    cout<<"\n";
    NO_prefix(root, ar, 0);
     return 0;
}

