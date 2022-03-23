#include <iostream>
#include <queue>
using namespace std;
//A1091

struct node{
	int x;
	int y;
	int z;
}Node;
int m, n, l, t;
int matrix[61][1290][130];
bool inq[61][1290][130]={false};

int X[]={0,0,0,0,1,-1};
int Y[]={0,0,1,-1,0,0};
int Z[]={1,-1,0,0,0,0};

bool judge(int z , int x, int y){
	if( z>=l || z<0 || x >= m || x<0 || y >= n || y<0) return false;
	if(inq[z][x][y] == true || matrix[z][x][y] == 0) return false;
	return true;
}

int BFS(int z, int x, int y){
	int tot = 0;
	queue<node> q;
	Node.z = z, Node.x = x, Node.y = y;
	q.push(Node);
	inq[z][x][y] = true;
	while(!q.empty()){
		node top = q.front();		//队列取队头元素是 q.front()
		q.pop();
		tot++;
		for(int i = 0 ; i < 6 ; i++){
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if(judge(newZ,newX,newY))
				Node.x = newX, Node.y = newY, Node.z = newZ;
				q.push(Node);
				inq[newZ][newX][newY] = true;
		}
	}
	if(tot >= t) return tot;
	else return 0;
}

//三维
int main(int argc, char *argv[]) {
	cin >> m >> n >> l >> t;
	//输入三维数组
	for(int i = 0 ; i < l ; i++){
		for(int j = 0 ; j < m ; j++){
			for(int k = 0 ; k < n ; k++){
				cin >> matrix[i][j][k];
			}
		}
	}
	int ans = 0;
	//cout<<"sdf"<<l;
	for(int i = 0 ; i < l ; i++){
			for(int j = 0 ; j < m ; j++){
				for(int k = 0 ; k < n ; k++){
					//cout <<matrix[i][j][k]<<inq[i][j][k]<<endl;
					if(matrix[i][j][k] == 1 && inq[i][j][k] == false){
						cout<<"sdf";
						ans +=BFS(i,j,k);					
					}
				}
			}
		}
		cout << ans;
	
	
}