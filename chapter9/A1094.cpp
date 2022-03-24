#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//A1094
const int maxn = 102;
int n , m;
struct tree{
	int depth;
	vector<int> child;
}Node[maxn];
int hashnode[maxn]={0};
//这题树的编号从1开始计算。

void bfs(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		for(int i = 0 ; i < Node[top].child.size() ; i++){
			int a = Node[top].child[i];
			Node[a].depth = Node[top].depth + 1;
			hashnode[Node[a].depth]++;
			q.push(a);
		}
	}
}
int main(int argc, char *argv[]) {
	cin >> n>> m;
	
	for(int i = 1 ; i <= m ; i++){
		int a, k;
		cin>> a >> k;
		for(int j = 1 ; j <= k ;j++){
			int b;
			cin >> b;
			Node[a].child.push_back(b);
		}
	}
	Node[1].depth = 1;
	hashnode[1]++;
	bfs(1);
	//输出
	int maxnodes = 0 ,maxdepth = 0;
	for(int i = 1 ; i <= n ; i++){
		if(hashnode[i] > maxnodes){
			maxdepth = i ;
			maxnodes = hashnode[i];
		}
	}
	cout << maxnodes <<" "<< maxdepth <<endl;
}