#include <iostream>

using namespace std;

const int maxn = 110;
int heap[maxn];			//完全二叉树
int n ;

//low是在变的，high是n
void downAdjust(int low , int high){
	int i = low;
	int j = i*2;
	while(j <= high){
		if(j + 1 <= high){
			if(heap[j] < heap[j+1]) j = j+1;
		}
		if(heap[i] < heap[j]) {
			swap(heap[i],heap[j]);
			i = j;
			j = i*2;
		}else break;
	}
}
void createHeap(){
	for(int i = n/2 ; i>=1 ;i--){
		downAdjust(i, n);
	}
}
void heapSort(){
	createHeap();
	for(int i = n ; i > 1 ; i--){
		swap(heap[i],heap[1]);
		downAdjust(1,i-1);
	}
}
int main(int argc, char *argv[]) {
	
}