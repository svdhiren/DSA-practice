#include<iostream>
using namespace std;
void perup(int H[], int &s, int k){
	if(s==0){
		H[0]=k;
		s++;
		return;
	}
	H[s]=k;
	int i = s;
	while(H[i] < H[(i-1)/2]  && i>0){
		int tmp = H[i];
		H[i]=H[(i-1)/2];
		H[(i-1)/2]=tmp;
		i=(i-1)/2;
	}
	s++;
}

int perdown(int H[], int &s){
	int res=H[0];
	H[0]=H[--s];
	int i=0;
	while(2*i+1 < s){
		if(2*i+2 < s)
		{
			if(H[i] > H[2*i+1] || H[i] > H[2*i+2]){
				if(H[2*i+1] < H[2*i+2])
				{
					int tmp = H[2*i+1];
					    H[2*i+1] = H[i];
					    H[i]=tmp;
					    i = 2*i+1;
				}
				else
				{
					int tmp = H[2*i+2];
					    H[2*i+2] = H[i];
					    H[i]=tmp;
					    i = 2*i+2;
				}
			}
			else break;
		}
		else{
			if(H[i] > H[2*i+1])
			{
				int tmp = H[2*i+1];
					H[2*i+1] = H[i];
					H[i]=tmp;
					i = 2*i+1;
			}
			else break;
		}
	}
	return res;
}
void heapsort(int H[], int s, int sort[]){
	static int j=0;
	while(s!=0){
	sort[j++] = perdown(H, s);
}
}

int main() {
	int H[50], ar[50], n, hsize;
	cout<<"Enter the size: ";
	cin>>n;
	cout<<"\nEnter the array elements: ";
	for(int i=0; i<n;i++){
		cin>>ar[i];
		perup(H, hsize, ar[i]);
	}
	cout<<"\nThe heap array is now: ";
	for(int i=0; i<hsize; i++) cout<<H[i]<<" ";
	int sort[50];
	heapsort(H, hsize, sort);
	cout<<"\nThe sorted elements are: ";
	for(int i=0; i< hsize; i++) cout<<sort[i]<<" ";
	return 0;
}
