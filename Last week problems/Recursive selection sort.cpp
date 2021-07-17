#include <bits/stdc++.h>
using namespace std;

void Selection_sort(int ar[], int i, int j, int n, int mini)
{
   if(i==n-1)
    return;

   if(j==n)
   {
       swap(ar[i], ar[mini]);
        i++;
        mini=i;
        j=i+1;
   }
   if(i!=n)
      if(ar[j] < ar[mini])
        mini=j;
   Selection_sort(ar, i, j+1, n, mini);
}


int main()
{
    int ar[] = {12, 7, 6, 19, 3, 5, 4, 14, 2, 42, 17};
    int n = sizeof(ar) / sizeof(ar[0]);
    Selection_sort(ar, 0, 1, n, 0);
    cout << "Sorted array: ";
    for(int i=0;i<n;i++) cout<<ar[i]<<" ";
    return 0;
}
