#include <iostream>
#include <vector>
#include <queue>
//A1021
using namespace std;
const int maxn = 10010;
int n;
int G[maxn][maxn];
struct Node{
int id;
int layer;
};
vector<Node> Adj[maxn];
int maxdepth = 0;
vector<int> nodes;
bool vis[maxn] = {false};
bool ishuan = false;
int now_depth = 0;		
//int BFS(int num){
//	queue<Node> q;
//	node now ;
//	now.id = num;
//	q.push(num);
//	while( !q.empty() ){
//		int top = q.front();
//		q.pop();
//		for(int i = 1 ; i <= n ; i++){
//			
//		}
//	}
//}
int DFS(int num){
//	if()s
	if(num)
	for(int i = 0 ; i < n ; i++){
		if(vis[i] == true){
			ishuan = true;
			return -1;
		}else if(G[num][i] == 1 && vis[i] == false){
			DFS(i);
			now_depth++;
		}
	}
}
int main(int argc, char *argv[]) {
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		int a1,a2;
		cin >> a1 >> a2;
		G[a1][a2] = 1;
		G[a2][a1] = 1;
		Node new1,new2;
		new1.id = a1;
		new2.id = a2;
		Adj[a2].push_back(new1);
		Adj[a1].push_back(new2);
	}
	for(int i = 1 ; i <= n ; i++){
		//从小到大遍历
		int depth = DFS(i);
		if(now_depth > maxdepth){
			maxdepth = now_depth;
			nodes.clear();
			nodes.push_back(i);
		}else if(now_depth == maxdepth){
			nodes.push_back(i);
		} 
	}
}