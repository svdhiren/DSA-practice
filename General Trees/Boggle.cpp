#include<iostream>
using namespace std;
struct trnode
{
    trnode* ptr[26];
    int endword;
};
typedef trnode* TPTR;

TPTR newnode()
{
    TPTR tmp = new trnode;
    for(int i=0;i<26;i++)
        tmp->ptr[i]=NULL;
    tmp->endword=0;
}

int main()
{
    int bog[][]={}
}

