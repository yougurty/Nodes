#include <iostream>
#include <cstring>
#include <map>

using namespace std;
const int maxn = 1010;
int n , k; 	
int G[maxn][maxn];			//建立邻接矩阵的图
map<string , int> string_to_int;
map<int , string> int_to_string;
map<string , int> Gang;
int numPerson = 0;
int weight[maxn] = {0};
bool vis[maxn] = {false};

int change(string str){
	//先在map里面找，之前有没有出现过这个str，有出现过的话，那就有映射关系，就有对应的int值了
	if(string_to_int.find(str) != string_to_int.end()){
		return string_to_int[str];					//出现过，那就直接返回
	}else{
		//这里要有个值，记录已经出现过的人的个数
		string_to_int[str] = numPerson;
		int_to_string[numPerson] = str;
		return numPerson++;
	}
}

void DFS(int index , int& sumW ,int& head , int& number){
	number ++ ;
	vis[index] = true;
	if(weight[index] > weight[head]){
		head = index;
	}
	
	//选
	for(int i = 0 ; i < numPerson ; i++){
//		if(vis[i] == false && G[index][i] != 0){
//			sumW = sumW + G[index][i];
//			G[index][i] = 0;
//			G[i][index] = 0;
//			DFS( i , sumW , head , number );		
		if(G[index][i] != 0){				//上面那个if语句不对，下面这个是对的，下面这个比上面的多考虑了一种情况。，那就是F-G-H是一个三角形，互相相连。
			sumW = sumW + G[index][i];
			G[index][i] = 0;
			G[i][index] = 0;
			if(vis[i] == false)
				DFS( i , sumW , head , number );
		}
		
	}
	//不选
}
void DFSTrave(){
	
	for(int i = 0 ; i < numPerson ; i++){
		int sumW = 0 , head = i , number = 0;
		if(vis[i] == false){
			DFS(i , sumW , head , number);
			if(number >2 && sumW > k){
				Gang[int_to_string[head]] = number;
			}
		}
	}
}
int main(int argc, char *argv[]) {
	cin >> n >> k;
	string str1 , str2;
	int w ;
	for(int i = 0 ; i < n ; i++){
		int name;
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2);
		G[id1][id2] += w;
		G[id2][id1] += w;
		weight[id1] += w;
		weight[id2] += w;
	}
	//输入完毕，下面判断团伙，也就是弱联通？？
	//输出只需要输出团伙点权最大的那个人，还有团伙的总人数
	DFSTrave();
	cout << Gang.size() << endl;
	map<string , int>::iterator it;
	for(it = Gang.begin() ; it != Gang.end() ; it++){
		cout<< it->first << " " << it->second<< endl;
	}
	return 0;
}