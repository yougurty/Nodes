#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//A1004
int n, m;
const int maxn = 103;
struct tree{
	int depth;
	vector<int> child;
}Node[maxn];
int maxdepth = 0;
int layernodes[maxn]= {0};
//每一层有多少叶子节点

void bfs(int root){
	queue<int> q;
	q.push(root);
	while( !q.empty() ){
		int top = q.front();
		q.pop();
		if(Node[top].child.size() == 0){
			layernodes[Node[top].depth]++;
			if(maxdepth < Node[top].depth ) maxdepth = Node[top].depth;
		}
		for(int i = 0 ; i < Node[top].child.size() ; i++){
			int a = Node[top].child[i];
			Node[a].depth = Node[top].depth + 1;
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
	Node[1].depth = 0;
	bfs(1);
	for(int i = 0 ; i < maxdepth ; i++){
			cout << layernodes[i]<<" ";
	}
	cout<< layernodes[maxdepth]<<endl;
}