#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
//A1076
//����ѧ�ᣬ���漰����ŵ�ʱ��ʹ��BFS������һ���ṹ�壬��id��layer��֮��BFS��������ջҲ����queue<Node>
using namespace std;
const int maxv = 1010;
int n,l;						//lΪת������
struct Node{
	int id;
	int layer;
};
vector<Node> Adj[maxv];				//ʹ���ڽӱ���Ϊ����int���ǽṹ��Node
//int G[maxv][maxv] = {0};			
bool vis[maxv] = {false};


int BFS(int index){
	int zhuanfa = 0;
	queue<Node> q;
	Node start;
	start.id = index;
	start.layer = 1;			//ע����ʼ�Ĳ�������Ϊ0��BFS������ж������� next.layer <= l����ʼ����Ϊ1��BFS������ж���������next.layer <= l+1
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
//			G[i][a] = 1;			//i ��עa
			Node node;
			node.id = i;
			node.layer = 0;
			Adj[a].push_back(node);
			
		}
	}
	//���һ�е�����
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