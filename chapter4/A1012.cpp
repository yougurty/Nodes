#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2010;
int n , m ;
struct Student{
	int grade[4];
	int ID;
}sts[maxn];
int Rank[1000000][4] = {0}; 			//每个人四项的排名
int now;
char course[4] = {'A','C','M','E'};
bool cmp(Student s1 , Student s2){
	return s1.grade[now] > s2.grade[now];
}
int main(int argc, char *argv[]) {
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> sts[i].ID >> sts[i].grade[1] >> sts[i].grade[2] >> sts[i].grade[3];
		sts[i].grade[0] = (int)((sts[i].grade[1] + sts[i].grade[2] +sts[i].grade[3])/3 +0.5);
	}
	//计算最好的排名,下面的写法是我没想到的，牛牛牛
	for(now = 0 ; now < 4 ; now++){
		sort(sts , sts+ n , cmp);
		Rank[sts[0].ID][now] = 1;
		for(int i = 1 ; i < n ; i++){
			if(sts[i].grade[now] == sts[i-1].grade[now]) Rank[sts[i].ID][now] = Rank[sts[i-1].ID][now];
			else {
				Rank[sts[i].ID][now] = i+1;
			}
		}
	}
	int query;
	for(int i = 0 ; i < m ; i++){
		if(i != 0) cout << endl;
		cin >> query;
		//四个rank里面选最大的。
		int tmp = 0;
		if(Rank[query][tmp] == 0) {
			cout << "N/A";
			continue;
		}
		for(int j = 1 ; j < 4 ; j++){
			if(Rank[query][tmp] > Rank[query][j]){
				tmp = j;
			}
		}
		cout << Rank[query][tmp] << " " << course[tmp];
//		if(i != m-1) cout << endl;
	}
}