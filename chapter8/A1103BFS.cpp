#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

int n, k, p , maxfac = -1;
vector<int> temp , ans, fac;

//�ѵ�Ҫ����һ�����顢�Դ���
void init()
{
	int index = 0;
	while( pow(index,p) <= n ){
		fac.push_back(pow(index,p));
		index++;
	}
		
}
//DFS����fac[index]
void DFS(int index, int num, int sum , int facsum){
	//�߽�
	if(sum == n && num == k){
		if(facsum > maxfac){
			maxfac = facsum;
			ans = temp;
			}
	}
	if(sum > n || num > k )
		return ;
	//������
	if(index - 1 >= 0){
	//ѡ
		temp.push_back(index);
		DFS(index , num+1 , sum+fac[index] , facsum+index);
		//��ѡ
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