#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

const int maxn = 100001;
int n;
double P,r;
struct tree{
	int depth;
	int data;	//只有叶子节点才会用到
	vector<int> child;
}Node[maxn];

void bfs(int root){
	queue<int> q;
	q.push(root);
	Node[root].depth = 0;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		for(int i = 0 ; i < Node[top].child.size() ; i++){
			int a = Node[top].child[i];
			q.push(a);
			Node[a].depth = Node[top].depth+1;
		}
	}
	
}
int main(int argc, char *argv[]) {
	double sum;
	cin >> n >> P >> r;
	for(int i = 0 ; i < n ; i++){
		int k;
		cin>> k;
		if(k == 0){		//代表是叶子节点
			int a;
			cin>> a;
			Node[i].data = a;
		}else{
			Node[i].data = 0;
			for(int j = 0 ; j < k ; j++){
				int b;
				cin >> b;
				Node[i].child.push_back(b);
			}
		}	
	}
//	现在遍历BFs
	bfs(0);
	double m = 1+r/100;
	for(int i = 0 ; i< n ;i++) {
		if(Node[i].child.size() == 0){
			sum +=P*(Node[i].data * pow( m, Node[i].depth ));
		}
	}
	printf("%.1lf",sum);
}