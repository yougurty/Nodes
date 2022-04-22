#include <iostream>
#include <algorithm>
using namespace std;
int n = 10;
int a[10]={4,8,1,5,2,3,9,7,6,0};

//从小到大 ,选择排序
void selectSort(){
	for(int i = 0 ; i < n ; i ++){
		for(int j = i+1 ; j < n ; j++){
			if(a[i] > a[j]) swap(a[i] , a[j]);
		}
	}
}
//冒泡排序
void BubbleSort(){
	for(int i = 0 ; i < n-1 ; i++){
		for(int j = 0 ; j < n-i-1 ; j++){
			if(a[j] > a[j+1]) swap(a[j] , a[j+1]);
		}	
	}
}

//插入排序
void InsertSort(){
	int p , insert_value;
	for(int i = 0 ; i < n-1 ; i++){
		p = i;
		insert_value = a[i];
		while(insert_value < a[p-1]){
			a[p] = a[p-1];
			p--;
		}
		a[p] = insert_value;
	}
}

//快速排序
void quickSort(int low , int high){
	int i = low; 	//	标杆
	int j = high;	
	if( i >= j){
		return;
	}
	int temp = a[low];
	while(i != j ){
		while(a[j] >= temp && i < j) j--;
		while(a[i] <= temp && i < j) i++;
		if( i < j ) swap(a[i] , a[j]);
	}
	swap(a[low] , a[i]);
	quickSort(low, i-1);
	quickSort(i+1 , high);
}
//

void output(){
	for(int i = 0 ; i < n ; i++){
		cout << a[i] <<" ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	selectSort();
	output();
	BubbleSort();
	output();
	quickSort(0 , n-1);
	output();
}