#include <iostream>
//�鲢����
using namespace std;
int n = 10;
int A[10]={4,8,1,5,2,3,9,7,6,0};
const int maxn = 120;
void output(){
	for(int i = 0 ; i < n ; i++){
		cout << A[i] <<" ";
	}
	cout << endl;
}
void merge( int A[] , int left , int mid , int right){
	
	int i = left;
	int j = mid+1;
	int temp[maxn] , index = 0;
	while( i <= mid && j <= right){
		if(A[i] <= A[j]){					//��������Ԫ��ֵ��С
			temp[index++] = A[i++];
		}else{								//�Ұ������Ԫ��ֵ��С
			temp[index++] = A[j++];
		}
	} 
	while(i <= mid) temp[index++] = A[i++];
	while(j <= right) temp[index++] = A[j++];
	for(i = 0 ; i  < index ; i++){
		A[left + i] = temp[i];		//���ϲ�������и�ֵ������A
	}
	
}

void msort( int A[] , int left , int right){
	if(left < right){
		int mid = (left + right) / 2;
		msort(A, left, mid);
		msort(A,  mid+1 , right);
		merge(A , left , mid , right);
//		sort(A+left, A+right+1);				//���ֻ������鲢����ÿһ�˽���ʱ�����У�������sort����merge����
		output();
	}

}


int main(int argc, char *argv[]) {
	
	msort(A, 0, n-1);
	output();
}