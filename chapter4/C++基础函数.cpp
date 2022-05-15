#include <iostream>
#include <algorithm>
using namespace std;
/*
 * next_permutation() 给出一个序列在全排列中的下一个序列
 *
*/
int main(int argc, char *argv[]) {
	int a[10] = {1,2,3,4};
	
	cout << "学习reverse()函数" << endl;
	reverse(a+1, a+4);
	for(int i = 0 ; i < 10 ; i ++){
		cout << a[i] << " ";
	}
	cout <<endl;

	cout << "学习next_permutation()函数" << endl;
	do{
		printf("%d%d%d\n" , a[0] , a[1] , a[2]);
	}while(next_permutation(a, a+3));
	//使用循环是因为next_permutation在已经到达全排列的最后一个时会返回false，这样会方便退出循环。
	
	cout << "学习fill()函数" << endl;
	//fill()函数可以把数组或容器中的某一段区间赋为数组类型对应范围中的任意值。
	//和memset不同，这里的赋值可以是数组类型对应范围中的任意值。
	//因为memset函数按照字节填充，所以一般memset只能用来填充char型数组，（因为只有char型占一个字节）。如果填充int型数组，只能填充0、-1 和 inf（正负都行）。因为00000000 = 0，-1同理，如果我们把每一位都填充“1”，会导致变成填充入“11111111”。如果我们将inf设为0x3f3f3f3f，0x3f3f3f3f的每个字节都是0x3f！所以要把一段内存全部置为无穷大，我们只需要memset(a,0x3f,sizeof(a))。无穷小可以将-INF设为0x8f。
	fill(a+4,a+9,10);	//a[4]-a[8]
	for(int i = 0 ; i < 10 ; i ++){
		cout << a[i] << " ";
	}
	cout << endl;
	cout << endl;
	cout << "学习sort()函数，详见算法笔记，很详细了。" << endl;
	cout << endl;
	
	cout << "学习lower_bound()、upper_bound()函数，详见算法笔记，很详细了。" << endl;
	
	
	return 0;
}