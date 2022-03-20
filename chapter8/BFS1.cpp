#include <iostream>
#include <queue>
//BFS广度优先搜索
using namespace std;


struct node{
	int x;
	int y;
}Node;
int a[4]={0,0,1,-1};
int b[4] = {1,-1,0,0};
bool inq[100][100];
int map[100][100];
int n , m;
bool judge(int x, int y){
	if(x >= n || x < 0 || y >= m || y < 0)return false;  //map的边界
	if(map[x][y] == 0 || inq[x][y] == true) return false; //有没有被访问过。
	return true;	
}

void BFS(int x,int y){
	queue<node> Q;
	Node.x = x;
	Node.y = y;
	Q.push(Node);
	inq[x][y] = true;
	while(!Q.empty()){
		node top = Q.front();
		Q.pop();
		for(int i = 0 ; i < 4 ; i++)
		{
			int newX = top.x + a[i];
			int newY = top.y + b[i];
			if(judge(newX , newY))
			{
				Node.x = newX, Node.y = newY;
				Q.push(Node);
				inq[newX][newY] = true;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	cin >> n >> m;
	for(int x = 0 ; x < n ; x++){
		for(int y = 0 ; y < m ; y++)
		{
			cin >> map[x][y];
		}
	}
	
	int ans = 0;
//	cout << "dfs";
//	cout << n;
	
	for(int x = 0 ; x < n ; x++){
		for(int y = 0 ; y < n ;y++){
			if(map[x][y] == 1 && inq[x][y] == false){
				ans++;
				BFS(x,y);
			}
		}
	}
	cout << ans <<endl;
	return 0;
	
}