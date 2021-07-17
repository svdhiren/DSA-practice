#include<iostream>
using namespace std;

struct gnode{
int data;
gnode* down;
gnode* next;
};
typedef gnode* GPTR;

GPTR addvertex(GPTR G, int n)
{
    if(G==NULL){
        G = new gnode;
        G->data=n;
        G->down=G->next=NULL;
        return G;
    }
    G->down=addvertex(G->down, n);
    return G;
}

GPTR search_ver(GPTR G, int y)
{
   while(1){
    if(G->data==y)
        return G;
    else G=G->down;
   }
}

GPTR create_list(GPTR G, GPTR g, int x, int y, int fl)
{
    if(g==NULL){
        g=new gnode;
        g->data=0;
        g->next=NULL;
        g->down=search_ver(G, y);
        return g;
    }
    if(fl==1){
        if(g->data==x){
            fl=0;
            g->next=create_list(G, g->next, x, y, fl);
        }
        else g->down=create_list(G, g->down, x, y, fl);
    }
    else{
        g->next=create_list(G, g->next, x, y, fl);
    }
    return g;
}

void depthfirst(GPTR G, int ar[], int vis[])
{
    static int a=1;
    G=G->next;
    GPTR tmp;
    while(G!=NULL){
         tmp=G->down;
        if(vis[tmp->data]!=1){
        ar[a++]=tmp->data;
        vis[tmp->data]=1;
        depthfirst(tmp, ar, vis);
        }
        G=G->next;
    }
}

int main()
{
    GPTR G=NULL, g=NULL;
    int x, y, st, v, n;
    cout<<"Enter the number of vertices to create the vertex list: ";
    cin>>v;
    n=1;
    while(n<=v)
    {
       G=addvertex(G, n);
       n++;
    }

    cout<<"\nStart entering the edges...\n";
    while(1){
        cout<<"Enter x: ";
        cin>>x;
        if(x==-1) break;
        cout<<"Enter y: ";
        cin>>y;
        g=G;
        G=create_list(G, g, x, y, 1);
        cout<<"\n";
    }


    cout<<"Enter the starting vertex: ";
    cin>>st;
    GPTR S=search_ver(G, st);
    int vis[20], ar[20];
    for(int i=1;i<=v;i++) vis[i]=0;
    ar[0]=st;
    vis[st]=1;
    depthfirst(S, ar, vis);
    cout<<"The DFS is: ";
    for(int i=0;i<v;i++) cout<<ar[i]<<" ";
    return 0;
}
