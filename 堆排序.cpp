#include <iostream>
#include <algorithm>
using namespace std;
int n = 10;
int arr[10]={4,8,1,5,2,3,9,7,6,0};

void output(){
	for(int i = 0 ; i < n ; i++){
		cout << arr[i] <<" ";
	}
	cout << endl;
}

void heapify( int n , int i){
	int lson = i*2 + 1;
	int rson = i*2 + 2;
	int largest = i;
	if(lson < n && arr[lson] > arr[i]){
		largest = lson;
	}
	if(rson < n && arr[rson] > arr[lson]){
		largest = rson;
	}
	if(largest != i){
		swap(arr[i] , arr[largest]);
		heapify(n , largest);
	}
}
void heapSort(){
	//建堆,要倒着来建堆。
	for(int i = (n-1)/2 ; i > 0 ; i--){
		heapify(n, i);
	}
	//排序
	for(int i = n-1 ; i > 0 ; i--){
		//首先交换堆顶和最后一个元素
		swap(arr[0] , arr[i]);
		//接着调整堆顶。
		heapify(i, 0);				//整体元素少一个，这里写i ,而不是i-1.正着来调整，建堆是倒着来调整。
		output();
	}
	
}


int main(int argc, char *argv[]) {
	heapSort();
	output();
}