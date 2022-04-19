#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
//A1076
//这题学会，在涉及到层号的时候，使用BFS，设置一个结构体，有id和layer，之后BFS里面设置栈也是用queue<Node>
using namespace std;
const int maxv = 1010;
int n,l;						//l为转发上限
struct Node{
	int id;
	int layer;
};
vector<Node> Adj[maxv];				//使用邻接表，因为不是int，是结构体Node
//int G[maxv][maxv] = {0};			
bool vis[maxv] = {false};


int BFS(int index){
	int zhuanfa = 0;
	queue<Node> q;
	Node start;
	start.id = index;
	start.layer = 1;			//注意起始的层数设置为0，BFS里面的判断条件是 next.layer <= l。起始设置为1，BFS里面的判断条件就是next.layer <= l+1
	q.push(start);
	vis[index] = true;
	while(!q.empty()){
		Node top = q.front();
		q.pop();
		for(int i = 0 ; i < Adj[top.id].size() ; i++){
			Node next = Adj[top.id][i];
			next.layer = top.layer + 1;
			if(vis[next.id] == false && next.layer <= l+1 ){
				q.push(next);
				vis[next.id] = true;
				zhuanfa++;
		     }
	     }
	}
	return zhuanfa;
}

int main(int argc, char *argv[]) {
	cin >> n >> l;
	for( int i = 1 ; i <= n ; i++){
		int num;
		cin >> num ;
		for( int j = 0; j < num ; j++){
			int a;
			cin >> a;
//			G[i][a] = 1;			//i 关注a
			Node node;
			node.id = i;
			node.layer = 0;
			Adj[a].push_back(node);
			
		}
	}
	//最后一行的输入
	int num = 0;
	cin >> num;
	for(int i = 0 ; i < num ; i++){
		memset(vis, false, sizeof(vis));
		int a;
		cin >> a;
		int zhuanfa = BFS(a);
		cout << zhuanfa;
		if(i != num - 1){
			cout << endl;
		} 
		
	}
}