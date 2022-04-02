#include <iostream>
#include <cstdio>
#include <algorithm>

// 直接插入排序、堆排序
using namespace std;
const int maxn = 110;
int n;
int origin[maxn],tempOri[maxn];
int changed[maxn];

bool isSame(int A[] , int B[]){
	for(int i = 1 ; i <= n ; i++){
		if(A[i] !=B[i]) return false;
	}
	return true;
}
bool insertSort(){
	bool flag = false;
	for(int i = 2 ; i <= n; i++){		//	进行n-1趟排序
		if(i != 2 && isSame(tempOri , changed) ){
			flag = true;
		}
		sort(tempOri , tempOri +i +1);
		if(flag == true) return true;
	}
	return false;
}

// 对heap进行范围上的调整，从下往上，
void downAdjust(int low , int high){
	int i = low;
	int j = i*2;
	while(j <= high){
		if(j+1 <= high && tempOri[j+1] > tempOri[j]){
			j = j + 1;
		}
		if(tempOri[j] > tempOri[i]){
			swap(tempOri[j] , tempOri[i]);
			i = j;
			j = i *2;
		}else break;
	}
}
bool showArray(int A[]){
	for(int i = 1 ;i <= n ;i++){
		cout << A[i];
		if(i < n) cout << " ";
	}
	cout << endl;
}
void heapSort(){
	bool flag = false;
	for(int i = n/2 ; i >= 1 ; i--){
		downAdjust(i, n);
	}
	for(int i = n ; i > 1; i--){
		if(i != n && isSame(tempOri , changed)){
			flag = true;
		}
		swap(tempOri[i] , tempOri[1]);		//交换堆顶和heap[i]
		downAdjust(1, i - 1);
		if(flag == true ){
			showArray(tempOri);	//以达到目标数组
			return;
		}
	}
}

int main(int argc, char *argv[]) {
	cin >> n;
	for( int i = 1 ; i <= n ; i++){
		cin >> origin[i];
		tempOri[i] = origin[i];
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> changed[i];
	}
	if(insertSort()){
		cout << "Insertion Sort" << endl;
		showArray(tempOri);
	}else{
		cout << "Heap Sort" << endl;
		for(int i = 1; i <= n ;i++) tempOri[i] = origin[i];
		heapSort();
	}
	return 0;
}
