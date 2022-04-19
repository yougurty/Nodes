#include <iostream>
#include <queue>
#include <cstring>
//A1013
using namespace std;

const int maxn = 1010;
int n , m , k;
int G[maxn][maxn];
//城市的个数，现存的高铁数，需要核验的城市数
bool vis[maxn] = {false};
int currentPoint = 0;		//需要记录当前需要删除的顶点编号,这个是我没想到的。
//求联通块的个数
void BFS(int num){
	queue<int> q;
	q.push(num);
	vis[num] = true;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(top == currentPoint) continue;				//遍历到要删除的那个节点，直接，该次循环结束
		for(int i = 1 ; i <= n ;i++){
			if(G[i][top] == 1 && vis[i] == false){
				q.push(i);
				vis[i] = true;
			}
		}
	}
	
}
int BFSTrave(){
	int geshu = 0;			//连通块的个数
	for(int i = 1; i <= n ; i++){
		if(vis[i] == false && i != currentPoint ){				//遍历到要删除的那个节点，直接跳过
			BFS(i);
			geshu++;
		}
	}
	return geshu-1;
} 



int main(int argc, char *argv[]) {
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++){
		int a1,a2;
		cin >> a1 >> a2;
		G[a1][a2] = 1;
		G[a2][a1] = 1;
	}
	int de, ans;
	for(int i = 0 ; i < k ; i++){
//		int delete,ans;
		cin >> de;
		currentPoint = de;
		memset(vis, false, sizeof(vis));
		ans = BFSTrave();
		cout << ans;
		if(i != k-1) cout << endl;
	}
}