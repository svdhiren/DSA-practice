#include<iostream>
using namespace std;
void bubblesort(int a[], int i, int j, int n)
{
    if(i>=n)
       return;
    if(j>=n-1)
    {
        i++;
        j=0;
    }
    if(a[j] > a[j+1])
        swap(a[j], a[j+1]);
    bubblesort(a, i, j+1, n);
}
int main()
{
    int a[]={4, 6, 9, 5, 1, 2, -2, 0, 15, 7};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    bubblesort(a, 0, 0, n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
