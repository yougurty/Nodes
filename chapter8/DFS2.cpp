#include <iostream>

using namespace std;

int a[25];
int n , k , x , maxpsum = 0;
vector<int> temp,ans ; //用vector比较好，可以直接等于

void DFS(int index ,int num, int sum, int psum)
{
	// 边界
	if(num == k)
	{
		if(sum == x && psum >maxpsum){
			ans = temp;
			psum = maxpsum;
		}
			return ;
	}
	//边界条件
	if(sum > x || num > k || index == n ) return ;
	
	//选
	temp.push_back(a[index]);
	DFS(index+1 , num+1 , sum+a[index] , psum+ a[index]*a[index]);
	//不选
	temp.pop_back();
	DFS(index+1 , num , sum , psum);
}
int main(int argc, char *argv[]) {
	
}