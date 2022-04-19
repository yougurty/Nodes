#include <iostream>
#include <queue>
#include <cstring>
//A1013
using namespace std;

const int maxn = 1010;
int n , m , k;
int G[maxn][maxn];
//���еĸ������ִ�ĸ���������Ҫ����ĳ�����
bool vis[maxn] = {false};
int currentPoint = 0;		//��Ҫ��¼��ǰ��Ҫɾ���Ķ�����,�������û�뵽�ġ�
//����ͨ��ĸ���
void BFS(int num){
	queue<int> q;
	q.push(num);
	vis[num] = true;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(top == currentPoint) continue;				//������Ҫɾ�����Ǹ��ڵ㣬ֱ�ӣ��ô�ѭ������
		for(int i = 1 ; i <= n ;i++){
			if(G[i][top] == 1 && vis[i] == false){
				q.push(i);
				vis[i] = true;
			}
		}
	}
	
}
int BFSTrave(){
	int geshu = 0;			//��ͨ��ĸ���
	for(int i = 1; i <= n ; i++){
		if(vis[i] == false && i != currentPoint ){				//������Ҫɾ�����Ǹ��ڵ㣬ֱ������
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