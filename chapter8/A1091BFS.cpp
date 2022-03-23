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
int matrix[1290][130][61];
bool inq[1290][130][61]={false};

int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};

bool judge(int x , int y, int z){
	if( z>=l || z<0 || x >= n || x<0 || y >= m || y<0) return false;
	if(inq[x][y][z] == true || matrix[x][y][z] == 0) return false;
	return true;

}

int BFS(int x, int y, int z){
	//cout << z << x << y << matrix[z][x][y];
	int tot = 0;
	queue<node> q;
	Node.z = z, Node.x = x, Node.y = y;
	q.push(Node);
	inq[x][y][z] = true;
	while(!q.empty()){
		node top = q.front();		//队列取队头元素是 q.front()
		q.pop();
		tot++;
		for(int i = 0 ; i < 6 ; i++){
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if(judge(newX,newY,newZ)){
				Node.x = newX, Node.y = newY, Node.z = newZ;
				q.push(Node);
				inq[newX][newY][newZ] = true;
				}
		}
	}
	if(tot >= t) return tot;
	else return 0;

}

//三维
int main(int argc, char *argv[]) {
	cin >> n >> m >> l >> t;
	int ans=0;
	int num=0;
	//输入三维数组
	for(int i = 0 ; i < l ; i++){
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < m ; k++){
				cin >> matrix[j][k][i];
			}
		}
	}


for(int i = 0 ; i < l ; i++){
			for(int j = 0 ; j < m ; j++){
				for(int k = 0 ; k < n ; k++){
					//cout <<matrix[i][j][k]<<inq[   i][j][k]<<endl;
					if(matrix[i][j][k] == 1 && inq[i][j][k] == false){
						
						ans +=BFS(i,j,k);					
					}
				}
			}
		}

	cout << ans<<endl;
	return 0;
}