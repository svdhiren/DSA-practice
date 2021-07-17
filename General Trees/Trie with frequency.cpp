#include<iostream>
using namespace std;

struct trnode {
   char ch;
   trnode* fc;
   trnode* ns;
   int num;
};
typedef struct trnode* TPTR;

  TPTR newchar(char c){
      TPTR tmp = new trnode;
      tmp->ch = c;
      tmp->num=0;
      tmp->fc=tmp->ns=NULL;
      return tmp;
  }

TPTR insertword(TPTR T, char key[], int n, int &i, int num){
       if(i>n){
        return T;
       }
       if(T==NULL){
        TPTR yo;
        if(i==n){
            yo = newchar('#');
            yo->num=num;
        }
        else yo = newchar(key[i]);
        yo->fc=insertword(yo->fc, key, n, ++i, num);
        return yo;
       }
       else if(T->ch==key[i] || T->ch=='#'){
        if(i+1==n && T->fc!=NULL){
            TPTR t = newchar('#');
            t->num=num;
            t->fc=T->fc;
            T->fc=t;
        }
        T->fc=insertword(T->fc, key, n, ++i, num);
        return T;
       }
       T->ns=insertword(T->ns, key, n, i, num);
       return T;
}

void print(TPTR T, char ar[], int n){
     if(T==NULL) return;
     if(T->ch=='#') {
       cout<<endl;
       for(int i=0;i<n;i++) cout<<ar[i];
       cout<<" - "<<T->num;
     }
     if(T->ch!='#') ar[n++]=T->ch;
     print(T->fc, ar, n);
     n--;
     print(T->ns, ar, n);
}

int main(){
    char ar[50];
    int n, num;
    TPTR root = NULL;
    cout<<"Start entering the keys...\n";
    while(1){
        cout<<"Enter the size of the key: ";
        cin>>n;
        if(n==0) break;
        cout<<"Enter the word: ";
        for(int i=0;i<n;i++) cin>>ar[i];
        cout<<"Enter the frequency: ";
        cin>>num;
        int i=0;
        root = insertword(root, ar, n, i, num);
    }
     char path[20];
     print(root, path, 0);
     return 0;

}

