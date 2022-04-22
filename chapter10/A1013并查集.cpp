#include <iostream>
#include <vector>
//1013 用并查集
using namespace std;
const int maxn = 1010;
int n , m , k;
vector<int> G[maxn];
int father[maxn] ;			//
bool vis[maxn];

int findFather(int x){
	int a = x;
	while( x != father[x]){
		x = father[x];
	}
	//路径压缩
	while( a !=father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}
void init(){
	for(int i = 1 ; i < maxn ; i++){
		father[i] = i;
		vis[i] = false;
	} 
}


int main(int argc, char *argv[]) {
	cin >> n >> m >> k;
	for(int i = 0 ; i < m ; i++){
		int a1, a2;
		cin >> a1 >> a2;
		G[a1].push_back(a2);
		G[a2].push_back(a1);
	}
	int currentPoint;
	for(int query = 0 ; query < k ; query++){
		cin >> currentPoint;
//		cout <<"currentPoint = "<< currentPoint <<endl;
		init();
		for(int i = 1 ; i <= n ; i++){
			for(int j = 0 ; j < G[i].size() ; j++){
				int u = i ;
				int v = G[i][j];
				if( u == currentPoint || v == currentPoint) continue; 
				Union(i, G[i][j]);	 		//合并u和v所在的集合
//				cout << u << v << endl;
			}
		}	
		int block = 0;
		for(int i = 1 ; i <= n ; i++){
			if( i == currentPoint ){
				continue;
			}
			int fa_i = findFather(i);
			if(vis[fa_i] == false){
				block++;
				vis[fa_i] = true;
			}
		}
		cout << block-1<< endl;
	}
	return 0;

}