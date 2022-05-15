#include <iostream>

using namespace std;
//快速排序，某up主
//分治思想
//自己可以写写画画过一遍
int n = 10;
int a[10]={4,8,1,5,2,3,9,7,6,0};

int partition(int low , int high){
	int pivot = a[high];
	int i = low;
	for(int j = low ; j <= high ; j++){			//注意这里是j = low，不是j = low + 1
		if(a[j] < pivot){
			swap(a[j] , a[i]);
			i++;
		}
	}
	swap(a[i] , a[high]);
	return i;
}
void output(){
	for(int i = 0 ; i < n ; i++){
		cout << a[i] <<" ";
	}
	cout << endl;
}
void quickS(int low , int high){
	if(low < high){
		int mid = partition(low , high);
		output();
		quickS(low , mid-1 );
		quickS(mid+1 , high);
	}
}


int main(int argc, char *argv[]) {
	quickS(0, 9);
	
}