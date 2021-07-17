#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (b==0)
        return a;
    return gcd(b, a%b);
}


int create_Starray(int st[], int ar[], int s, int e, int i){
     if(s==e){
        st[i]=ar[s];
        return ar[s];
     }

     st[i] = gcd(create_Starray(st, ar, s, s + (e-s)/2, 2*i+1)
                    ,create_Starray(st, ar, s + (e-s)/2 + 1, e, 2*i+2));
     return st[i];
}

int rangesum(int st[], int ar[], int s, int e, int i1, int i2, int i){
     if((s==e) || ((i1==s)&&(i2==e))) return st[i];
     else if(i2 <= s+(e-s)/2)
	   return rangesum(st, ar, s, s+(e-s)/2, i1, i2, 2*i+1);
	 else if(i1 >= s+(e-s)/2+1)
	   return rangesum(st, ar, s+(e-s)/2+1, e, i1, i2, 2*i+2);
	 else
        return gcd(rangesum(st, ar, s, s+(e-s)/2, i1, s+(e-s)/2, 2*i+1),
                  rangesum(st, ar, s+(e-s)/2+1, e, s+(e-s)/2+1,i2, 2*i+2) );
}


int main() {
    int st[50], ar[50], n, siz;
    cout<<"Enter the size of the array: " ;
    cin>>n;
    for(int i=1;   ;i++){
        if(pow(2, i) >= n){
           siz=pow(2, i);
           break;
        }
    }
    siz=2*siz -1;
    cout<<"Start entering...\n";
    for(int i=0;i<n;i++){
        cout<<"Enter: ";
        cin>>ar[i];
    }
    for(int i=0;i<siz;i++) st[i]=0;
    create_Starray(st, ar, 0, n-1, 0);
    cout<<"\nThe segment tree array is: ";
    for(int i=0;i<siz;i++) cout<<st[i]<<" ";
    cout<<"\nEnter the range to get the sum: ";
    int i1, i2;
    cin>>i1>>i2;
    cout<<"Sum of the given range is:  "<<rangesum(st, ar, 0, n-1, i1, i2, 0);
    return 0;
}
