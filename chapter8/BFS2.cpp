#include <iostream>

using namespace std;

int a[25];
int n , k , x , maxpsum = 0;
vector<int> temp,ans ; //��vector�ȽϺã�����ֱ�ӵ���

void DFS(int index ,int num, int sum, int psum)
{
	// �߽�
	if(num == k)
	{
		if(sum == x && psum >maxpsum){
			ans = temp;
			psum = maxpsum;
		}
			return ;
	}
	//�߽�����
	if(sum > x || num > k || index == n ) return ;
	
	//ѡ
	temp.push_back(a[index]);
	DFS(index+1 , num+1 , sum+a[index] , psum+ a[index]*a[index]);
	//��ѡ
	temp.pop_back();
	DFS(index+1 , num , sum , psum);
}
int main(int argc, char *argv[]) {
	
}