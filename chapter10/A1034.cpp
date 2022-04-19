#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
//A1034
//map用find函数来定位数据出现位置，它返回的一个迭代器，当数据出现时，它返回数据所在位置的迭代器，如果map中没有要查找的数据，它返回的迭代器等于end函数返回

using namespace std;

const int maxn = 2010;	// 总人数
const int INF = 1000000000;
map<int , string> intToString;	//编号->姓名
map<string , int> stringToInt;	//姓名->编号
map<string , int>Gang;			//head->人数
int G[maxn][maxn] = {0} , weight[maxn] = {0};//邻接矩阵G，点权weight
int n , k , numPerson = 0;		//边数n，下限k，总人数numPerson
bool vis[maxn] = {false};		//标记是否被访问

void DFS(int nowVisit , int& head , int& numMember , int& totalValue){
	numMember++;
	vis[nowVisit] = true;
	if(weight[nowVisit] > weight[head]){
		head = nowVisit;
	}
	for(int i = 0 ; i < numPerson ; i++){
		if(G[nowVisit][i] > 0){
			totalValue +=G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;			//防止成为一个圈的时候多加。
			if(vis[i] == false){
				DFS(i , head , numMember , totalValue);
			}
		}
	}
	
}

void DFSTrave(){
	for(int i = 0 ; i < numPerson ; i++){		//编号从0开始编
		if(vis[i] == false){
			int head = i , numMember = 0 ,totalValue = 0 ;
			DFS(i , head , numMember , totalValue);
			if(numMember > 2 && totalValue > k ){		//满足这些条件就算一个团伙
				Gang[intToString[head]] = numMember;
				cout << head << " " << numMember << endl;
			}
		}
	}
}
int change(string str){
	if(stringToInt.find(str) != stringToInt.end()){		//如果这个人出现过。就返回字典对应的int值。
		return stringToInt[str];
	}else{
		stringToInt[str] = numPerson;		//如果这个人没出现过，那就建立映射关系。
		intToString[numPerson] = str;
		return numPerson++;
	}
}


int main(int argc , char *argv[]){
	int w;
	string str1 , str2;
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++){
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);		//把str1转为id1
		int id2 = change(str2);
		weight[id1] += w;			//记录每个人的点权
		weight[id2] +=w;
		G[id1][id2] +=w;			//构建邻接图表
		G[id2][id1] +=w;
	}
	DFSTrave();
	cout << Gang.size() << endl;
	map<string , int>::iterator it;
	for(it = Gang.begin() ; it != Gang.end() ; it++){
		cout<< it->first << " " << it->second<< endl;
	}
	return 0;
}