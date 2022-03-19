#include <iostream>

using namespace std;
//示例代码，dfs
//第一步知道是递归，第二步判断岔路口在哪，死胡同怎么界定，以及边界的判断

int w[21], c[21];
int V, n, maxValue = 0;

void DFS(int index, int sumW, int sumC)
{
	//边界
	if(sumW > V && index < n)
		return ;
	if( index == n) {
		if(sumW <= V && sumC > maxValue)
			maxValue = sumC;
		return ;
	}

	//选
	DFS(index+1, sumW+w[index], sumC+c[index]);
	//不选
	DFS(index+1, sumW , sumC);
	
}

//剪枝版本
void DFS(int index, int sumW, int sumC)
{
	//边界
	if(index == n) return ;
	
	DFS(index+1, sumW , sumC);
	
	if(sumW + w[index] <= V){
		if(sumC + c[index] > maxValue)
			maxValue = sumC + c[index];
		DFS(index+1, sumW+w[index], sumC+c[index]);
	}
	
}

int main(int argc, char *argv[]) {
	cin >> n >> V;
	for(int i = 0 ; i < n ; i++){
		cin >> w[i];
	}
	for(int i = 0 ; i < n ; i++){
			cin >> c[i];
	}
	DFS(-1, 0,0);
	cout << maxValue<<endl;
}

