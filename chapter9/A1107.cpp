#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//A1107-并查集
//说实话，这题自己只独立写了一半，后面自己写的太过于繁琐，就看了答案。
//答案把isRoot从bool换成了int，因为要记录每个社交网络，有多少人。


const int maxn = 1010;
int n ;
int father[maxn];
//vector<int> list[maxn];		//	每个爱好是拥有人数是变长数组
struct List{
	vector<int> lb;
}list[maxn];

int isRoot[maxn];
bool hoppyexist[maxn] = {false};
void init(){
	for(int i = 0 ; i < n ;i++){
		father[i] = i;
		isRoot[i] = 1;
	}
}

int findFather(int x){
	while(x != father[x]){
		x = father[x];
	}
	return x;
}

void Union(int a , int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
		isRoot[faA] = 0;
	}
}
bool cmp(int a, int b){
	return a > b;
}
int main(int argc, char *argv[]) {
	char un2;
	cin >> n;
	init();
	for(int i = 0 ; i < n ; i++){
		int k; cin >> k >> un2;
		for(int j = 0 ; j< k ;j++){
			int a;
			cin >> a;
			list[a].lb.push_back(i);
			hoppyexist[a] = true;
		}
	}
	for(int i = 0 ; i < maxn ; i++)
	{
		if(hoppyexist[i] == true){
			for(int j = 0 ; j< list[i].lb.size() - 1 ; j++){
			Union(list[i].lb[j] , list[i].lb[j+1]);
			}
		}
	}
	int ans = 0;
	
	for(int i = 0 ; i< n ; i++){
		if(isRoot[i] != 0) {
			ans++;
		}
	}
	for(int i = 0 ; i < n ; i++){
		isRoot[findFather(i)]++;			//精妙绝伦，我是想不到。遍历一遍节点，节点i的跟节点是findFather(i)，所以isRoot[]++;巧妙的记录了，一个社交网络有多少人。
	}
	cout << ans << endl;
	sort(isRoot , isRoot+n , cmp);
	for(int i = 0 ; i< ans-1 ; i++){
		cout << isRoot[i]-1 << " ";
	}
	cout << isRoot[ans-1]-1;
}