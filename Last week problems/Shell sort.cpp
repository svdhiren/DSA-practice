#include<iostream>
using namespace std;


void shell_sort(int ar[], int n)
{
    int c=0, k=n/2;
    while(k!=1)
    {
        for(int i=0;i+k<n;i++)
        {
            if(ar[i+k] < ar[i])
                {
                    swap(ar[i+k], ar[i]);
                    c++;
                }

        }
        k=k/2;
    }

    for(int i=1;i<n;i++)
    {
    for(int j=i;ar[j]<ar[j-1] && j>0;j--)
        {
            swap(ar[j], ar[j-1]);
            c++;
        }
    }
    cout<<"\nNumber of comparisons = "<<c;
}

int main()
{
    int ar[]={18, 7, 12, 5, 10, 9, 4, 15};
    int n=sizeof(ar)/sizeof(ar[0]);
    cout<<"The unsorted array is: ";
    for(int i=0;i<n;i++) cout<<ar[i]<<" ";
    shell_sort(ar, n);
    cout<<"\nThe sorted array is: ";
    for(int i=0;i<n;i++) cout<<ar[i]<<" ";
    return 0;
}
