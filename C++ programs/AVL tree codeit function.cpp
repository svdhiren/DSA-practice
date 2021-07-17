#include <iostream>
using namespace std;
#include <string>


struct node
{
    int data;
    node *lc;
    node *rc;
};
typedef struct node *LPTR;

LPTR newNode(int x)
{
    LPTR R = new(struct node);
    R->data = x;
    R->lc=R->rc= NULL;
    return R;
}

LPTR rotateleft(LPTR k1,LPTR k2,LPTR k3)
{
    
   
    k1->rc = k2->lc;
    k2->lc = k1;
   
    return k2;
}

void print(LPTR L)
{
    if(L==NULL)
        return;
    else
    {
        cout << L->data << " ";
        print(L->lc);
        print(L->rc);
    }
}

int main()
{
    LPTR L = new(struct node);
    L=newNode(1);
    L->rc=newNode(2);
    L->rc->rc=newNode(3);
    print(L);
    int x;
    cin >> x;
    L = rotateleft(L,L->rc,L->rc->rc);
    print(L);
   
    return 0;
}
