#include <iostream>
#include <cstring>
#include <map>

using namespace std;
const int maxn = 1010;
int n , k; 	
int G[maxn][maxn];			//�����ڽӾ����ͼ
map<string , int> string_to_int;
map<int , string> int_to_string;
map<string , int> Gang;
int numPerson = 0;
int weight[maxn] = {0};
bool vis[maxn] = {false};

int change(string str){
	//����map�����ң�֮ǰ��û�г��ֹ����str���г��ֹ��Ļ����Ǿ���ӳ���ϵ�����ж�Ӧ��intֵ��
	if(string_to_int.find(str) != string_to_int.end()){
		return string_to_int[str];					//���ֹ����Ǿ�ֱ�ӷ���
	}else{
		//����Ҫ�и�ֵ����¼�Ѿ����ֹ����˵ĸ���
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
	
	//ѡ
	for(int i = 0 ; i < numPerson ; i++){
//		if(vis[i] == false && G[index][i] != 0){
//			sumW = sumW + G[index][i];
//			G[index][i] = 0;
//			G[i][index] = 0;
//			DFS( i , sumW , head , number );		
		if(G[index][i] != 0){				//�����Ǹ�if��䲻�ԣ���������ǶԵģ��������������Ķ࿼����һ����������Ǿ���F-G-H��һ�������Σ�����������
			sumW = sumW + G[index][i];
			G[index][i] = 0;
			G[i][index] = 0;
			if(vis[i] == false)
				DFS( i , sumW , head , number );
		}
		
	}
	//��ѡ
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
	//������ϣ������ж��ŻҲ��������ͨ����
	//���ֻ��Ҫ����Ż��Ȩ�����Ǹ��ˣ������Ż��������
	DFSTrave();
	cout << Gang.size() << endl;
	map<string , int>::iterator it;
	for(it = Gang.begin() ; it != Gang.end() ; it++){
		cout<< it->first << " " << it->second<< endl;
	}
	return 0;
}