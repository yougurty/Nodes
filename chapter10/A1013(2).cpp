#include <iostream>
#include <queue>
#include <cstring>
//A1013，给你一个表
using namespace std;

const int maxn = 1010;
int n, m, k;
int G[maxn][maxn] = {0};
bool vis[maxn] = {false};
int currnet_num;
//判断联通块
void BFS(int index){
	queue<int> q;
	q.push(index);
	vis[index] = true;
	while(!q.empty()){
		int top = q.front();
		q.pop();
//		if(top == currnet_num) continue;
		for(int i = 1 ; i <= n; i++){
			if(vis[i] == false && G[top][i] != 0 && i!=currnet_num){
				q.push(i);
				vis[i] = true;
			}
		}
	}
}

int BFSTrave(){
	int num = 0;
	memset(vis, false, sizeof(vis));
	for(int i = 1 ; i <= n ; i++){
		if(vis[i] == false && i != currnet_num){
			BFS(i);
			num++;
		}
	}
	return num-1;
}

int main(int argc, char *argv[]) {
	cin >> n >> m >> k;
	for(int i = 0 ; i < m ; i++){
		int a1, a2;
		cin >> a1 >> a2;
		G[a1][a2] = 1;
		G[a2][a1] = 1;
	}
	for(int i = 0 ; i < k ; i++){
		int de;
		cin >> de;
		currnet_num = de;
		int an = BFSTrave();
		cout << an;
		if(i != k-1) cout << endl;
	}
	
}