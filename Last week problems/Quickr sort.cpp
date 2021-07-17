#include <bits/stdc++.h>
using namespace std;

int part(int ar[], int l, int h)
{
    int p=l++;
    while(l<=h)
    {
        while(ar[l] < ar[p])
             l++;
        while(ar[h] > ar[p])
             h--;
        if(l <= h) swap(ar[l], ar[h]);

    }
    swap(ar[h], ar[p]);
    return h;
}

void quickSort(int ar[], int low, int high)
{
    if(low > high)
        return;
    int j = part(ar, low, high);
    quickSort(ar, low, j-1);
    quickSort(ar, j+1, high);
}




int main()
{
    int ar[] = {12, 7, 6, 19, 3, 5, 4, 14};
    int n = sizeof(ar) / sizeof(ar[0]);
    quickSort(ar, 0, n - 1);
    cout << "Sorted array: ";
    for(int i=0;i<n;i++) cout<<ar[i]<<" ";
    return 0;
}
