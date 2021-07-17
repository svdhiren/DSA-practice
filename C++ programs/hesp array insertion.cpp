#include<iostream>
using namespace std;
void perup(int H[], int &n, int k){
	H[n]=k;
	int i=n;
	n++;
	while(H[i] < H[(i-1)/2]  && i>0){
		int tmp = H[i];
		H[i]=H[(i-1)/2];
		H[(i-1)/2]=tmp;
		i=(i-1)/2;
	}
}
int main() {
	int H[50], n;
	cout<<"Enter the size: ";
	cin>>n;
	cout<<"\nEnter the heap array: ";
	for(int i=0; i<n;i++) cin>>H[i];
	int k;
	cout<<"\nEnter the element to be added: ";
	cin>>k;
	perup(H, n, k);
	cout<<"\nThe heap array after additon is: ";
	for(int i=0; i<n; i++) cout<<H[i]<<" ";
	return 0;
	
}
