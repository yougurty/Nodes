#include <iostream>
#include <vector>
using namespace std;
//ͼ�ı�������
const int MAXV = 2000;
const int INF = 10000000;
int n , G[MAXV][MAXV];	//matrix
vector<int> Adj[MAXV];
bool vis[MAXV] = {false};

void DFS_matrix(int index){
	//���øýڵ��Ѿ�����
	vis[index] = true;
	cout << index;		//	����ýڵ���
	for(int i = 0 ; i < n ; i++){
		if(G[index][i] != INF && vis[i] ==false ){	//ע��������INF���������д�i�����ܵ���ķ�֧�������ö�١�
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
//�ڽӱ�汾
void DFS_table(int index){
	//���øýڵ��Ѿ�����
	vis[index] = true;
	cout << index;		//	����ýڵ���
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