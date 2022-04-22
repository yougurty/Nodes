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
	//����,Ҫ���������ѡ�
	for(int i = (n-1)/2 ; i > 0 ; i--){
		heapify(n, i);
	}
	//����
	for(int i = n-1 ; i > 0 ; i--){
		//���Ƚ����Ѷ������һ��Ԫ��
		swap(arr[0] , arr[i]);
		//���ŵ����Ѷ���
		heapify(i, 0);				//����Ԫ����һ��������дi ,������i-1.�����������������ǵ�����������
		output();
	}
	
}


int main(int argc, char *argv[]) {
	heapSort();
	output();
}