#include <iostream>
#include <vector>
using namespace std;
//图的遍历代码
const int MAXV = 2000;
const int INF = 10000000;
int n , G[MAXV][MAXV];	//matrix
vector<int> Adj[MAXV];
bool vis[MAXV] = {false};

void DFS_matrix(int index){
	//设置该节点已经访问
	vis[index] = true;
	cout << index;		//	输出该节点编号
	for(int i = 0 ; i < n ; i++){
		if(G[index][i] != INF && vis[i] ==false ){	//注意这里是INF，代表所有从i出发能到达的分支顶点进行枚举。
			DFS_matrix(i);
		}
	}
}

void Trave_matrix(){
	for(int u = 0 ; u < n ; u++){
		if(vis[u] == false){
			DFS_matrix(u);
		}
	}
}
//邻接表版本
void DFS_table(int index){
	//设置该节点已经访问
	vis[index] = true;
	cout << index;		//	输出该节点编号
	for(int i = 0 ; i < Adj[index].size() ; i++){
		if(vis[Adj[index][i]] == false ){
			DFS_table(Adj[index][i]);
		}
	}
}

void Trave_table(){
	for(int u = 0 ; u < n ; u++){
		if(vis[u] == false){
			DFS_table(u);
		}
	}
}

int main(int argc, char *argv[]) {
	
}