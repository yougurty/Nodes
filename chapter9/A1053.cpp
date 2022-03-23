#include <iostream>
#include <vector>
#include <algorithm>
//1053

using namespace std;

const int maxn = 102;
int n, m,s;	//n:所有节点，m所有非叶子节点，s
int w[maxn];
struct tree{
	int data;
	int weight;
	vector<int> child;
}Node[maxn];
vector<int> path;
int sum=0;


bool cmp(int a, int b){
	return Node[a].weight > Node[b].weight;
}
//下面是算给定路径的权值
//感觉要DFS
void dfs(int root){
	
	sum +=Node[root].weight;
	path.push_back(Node[root].weight);
	//cout<<"sd";
	if(Node[root].child.size() == 0){
		if(sum == s){
			for(int i = 0 ; i<path.size()-1 ;i++) cout<<path[i]<<" ";
			cout<<path[path.size()-1]<<endl;
		}
		return;
	}
	//cout << sum<<" ";
	for(int i = 0 ; i < Node[root].child.size() ; i++){
		
		dfs(Node[root].child[i]);
		path.pop_back();
		int a = Node[root].child[i];
		sum -= Node[a].weight;
	}
	
}

int main(int argc, char *argv[]) {
	cin >> n >> m >> s;
	for(int i = 0 ; i <n ; i++ )
		cin >> Node[i].weight;
	for(int i = 0 ; i < m ; i++){
		int a,k;
		cin >> a >> k;
		for(int j = 0 ; j < k ; j++){
			int b;
			cin>>b;
			Node[a].child.push_back(b);
		}
		sort(Node[a].child.begin() , Node[a].child.end() , cmp);		//这个纯属考虑到输出按照
	}
	dfs(0);
	
}