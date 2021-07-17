#include<iostream>
using namespace std;
struct heap {
	int num;
	int index;
};

void perup(heap H[], int &s, int ele, int index) {
	if(s==0){
		H[0].num = ele;
		H[0].index = index;
		s++;
		return;
	}
	H[s].num=ele;
	H[s].index=index;
	int i=s;
	while(H[i].num < H[(i-1)/2].num  && i>0){
		heap temp=H[(i-1)/2];
		H[(i-1)/2]=H[i];
		H[i]=temp;
	}
	s++;
}

int perdown(heap H[], int &s, int ar[][30]){
    int res = H[0].num;
    int i = H[0].index;
	if(ar[i][0]==0)  {
		s=0;
		return res;
	}
	else{
	    H[0].num = ar[i][1];
		for(int j=1; j<ar[i][0]; j++)
		    ar[i][j] = ar[i][j+1];
		ar[i][0]--;
	}
	i=0;
	while(2*i+1 < s){
		if(2*i+2 < s)
		{
			if(H[i].num > H[2*i+1].num || H[i].num > H[2*i+2].num)
			{
				if(H[2*i+1].num < H[2*i+2].num)
				{
					heap tmp = H[2*i+1];
					    H[2*i+1] = H[i];
					    H[i]=tmp;
					    i = 2*i+1;
				}
				else
				{
					heap tmp = H[2*i+2];
					    H[2*i+2] = H[i];
					    H[i]=tmp;
					    i = 2*i+2;
				}
			}
			else break;
		}
		else{
			if(H[i].num > H[2*i+1].num)
			{
				heap tmp = H[2*i+1];
					H[2*i+1] = H[i];
					H[i]=tmp;
					i = 2*i+1;
			}
			else break;
		}
	}
	return res;
}


void range(heap H[], int s, int &l, int  &h, int ar[][30]){
   while(s!=0){
   	   int min = perdown(H, s, ar);
   	   	int max = H[0].num;
   	   for(int i=1; i<s; i++){
   	   	if(H[i].num > max) max = H[i].num;
		  }
		if((h-l) > (max-min)) {
			l=min;
			h=max;
		}
   }
}

int main(){
	int ar[10][30];
	int m, hsize=0;
	heap H[50];
	cout<<"Enter the number of arrays: ";
	cin>>m;
	for(int i=0;i<m;i++){
		cout<<"\nEnter the number of elements of the array "<<i+1<<" : ";
		cin>>ar[i][0];
		cout<<"\nStart entering the elements: ";
		for(int j=1; j<=ar[i][0];j++)
		    cin>>ar[i][j];

	}
	//Adding the first element of every array to the heap.
	for(int i=0; i<m;i++){
		perup(H, hsize, ar[i][1], i);
		for(int j=1; j<ar[i][0]; j++)
		     ar[i][j]=ar[i][j+1];
		ar[i][0]--;
	}
	int l=0, h=100;
	range(H, hsize, l, h, ar);
	cout<<"\nThe minimum range is : "<<l<<"-"<<h;
	return 0;
}
