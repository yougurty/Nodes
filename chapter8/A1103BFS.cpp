#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

int n, k, p , maxfac = -1;
vector<int> temp , ans, fac;

//难点要设立一个数组、自创的
void init()
{
	int index = 0;
	while( pow(index,p) <= n ){
		fac.push_back(pow(index,p));
		index++;
	}
		
}
//DFS访问fac[index]
void DFS(int index, int num, int sum , int facsum){
	//边界
	if(sum == n && num == k){
		if(facsum > maxfac){
			maxfac = facsum;
			ans = temp;
			}
	}
	if(sum > n || num > k )
		return ;
	//倒着来
	if(index - 1 >= 0){
	//选
		temp.push_back(index);
		DFS(index , num+1 , sum+fac[index] , facsum+index);
		//不选
		temp.pop_back();
		DFS(index-1 , num , sum , facsum);
	}
}
int main(int argc, char *argv[]) {
	cin >> n >> k >> p;
	init();
	DFS(fac.size()-1 , 0, 0, 0);
	if(maxfac == -1) cout <<"Impossible" <<endl;
	else{
		cout << n << " = " << ans[0] << '^' << p;
		for(int i = 1 ; i < ans.size() ; i++){
			 cout <<" + " << ans[i] << '^' << p;
		}
		cout << endl;
	}
}