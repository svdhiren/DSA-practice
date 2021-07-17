#include<iostream>
using namespace std;

struct trnode {
   char ch;
   trnode* fc;
   trnode* ns;
   int num;
   int fl;
};
typedef struct trnode* TPTR;

  TPTR newchar(char c){
      TPTR tmp = new trnode;
      tmp->ch = c;
      tmp->fl=0;
      tmp->fc=tmp->ns=NULL;
      return tmp;
  }

TPTR insertword(TPTR T, char key[], int n, int &i){
       if(i==n){
        return T;
       }
       if(T==NULL){
        TPTR yo = newchar(key[i]);
        if(i+1==n) yo->fl=1;
        yo->fc=insertword(yo->fc, key, n, ++i);
        return yo;
       }
       else if(T->ch==key[i]){
        if(i+1==n) T->fl=1;
        T->fc=insertword(T->fc, key, n, ++i);
        return T;
       }
       T->ns=insertword(T->ns, key, n, i);
       return T;
}

void print(TPTR T, char ar[], int n){
     if(T==NULL) return;
     ar[n++]=T->ch;
     if(T->fl==1) {
       cout<<endl;
       for(int i=0;i<n;i++) cout<<ar[i];
     }
     print(T->fc, ar, n);
     n--;
     print(T->ns, ar, n);
}

int main(){
    char ar[50];
    int n;
    TPTR root = NULL;
    cout<<"Start entering the keys...\n";
    while(1){
        cout<<"Enter the size of the key: ";
        cin>>n;
        if(n==0) break;
        cout<<"Enter the word: ";
        for(int i=0;i<n;i++) cin>>ar[i];
        int i=0;
        root = insertword(root, ar, n, i);
    }
     char path[20];
     print(root, path, 0);
     return 0;

}
