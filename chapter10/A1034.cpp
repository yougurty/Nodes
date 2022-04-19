#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
//A1034
//map��find��������λ���ݳ���λ�ã������ص�һ���������������ݳ���ʱ����������������λ�õĵ����������map��û��Ҫ���ҵ����ݣ������صĵ���������end��������

using namespace std;

const int maxn = 2010;	// ������
const int INF = 1000000000;
map<int , string> intToString;	//���->����
map<string , int> stringToInt;	//����->���
map<string , int>Gang;			//head->����
int G[maxn][maxn] = {0} , weight[maxn] = {0};//�ڽӾ���G����Ȩweight
int n , k , numPerson = 0;		//����n������k��������numPerson
bool vis[maxn] = {false};		//����Ƿ񱻷���

void DFS(int nowVisit , int& head , int& numMember , int& totalValue){
	numMember++;
	vis[nowVisit] = true;
	if(weight[nowVisit] > weight[head]){
		head = nowVisit;
	}
	for(int i = 0 ; i < numPerson ; i++){
		if(G[nowVisit][i] > 0){
			totalValue +=G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;			//��ֹ��Ϊһ��Ȧ��ʱ���ӡ�
			if(vis[i] == false){
				DFS(i , head , numMember , totalValue);
			}
		}
	}
	
}

void DFSTrave(){
	for(int i = 0 ; i < numPerson ; i++){		//��Ŵ�0��ʼ��
		if(vis[i] == false){
			int head = i , numMember = 0 ,totalValue = 0 ;
			DFS(i , head , numMember , totalValue);
			if(numMember > 2 && totalValue > k ){		//������Щ��������һ���Ż�
				Gang[intToString[head]] = numMember;
				cout << head << " " << numMember << endl;
			}
		}
	}
}
int change(string str){
	if(stringToInt.find(str) != stringToInt.end()){		//�������˳��ֹ����ͷ����ֵ��Ӧ��intֵ��
		return stringToInt[str];
	}else{
		stringToInt[str] = numPerson;		//��������û���ֹ����Ǿͽ���ӳ���ϵ��
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
		int id1 = change(str1);		//��str1תΪid1
		int id2 = change(str2);
		weight[id1] += w;			//��¼ÿ���˵ĵ�Ȩ
		weight[id2] +=w;
		G[id1][id2] +=w;			//�����ڽ�ͼ��
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