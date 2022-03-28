#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//A1107-���鼯
//˵ʵ���������Լ�ֻ����д��һ�룬�����Լ�д��̫���ڷ������Ϳ��˴𰸡�
//�𰸰�isRoot��bool������int����ΪҪ��¼ÿ���罻���磬�ж����ˡ�


const int maxn = 1010;
int n ;
int father[maxn];
//vector<int> list[maxn];		//	ÿ��������ӵ�������Ǳ䳤����
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
		isRoot[findFather(i)]++;			//������ף������벻��������һ��ڵ㣬�ڵ�i�ĸ��ڵ���findFather(i)������isRoot[]++;����ļ�¼�ˣ�һ���罻�����ж����ˡ�
	}
	cout << ans << endl;
	sort(isRoot , isRoot+n , cmp);
	for(int i = 0 ; i< ans-1 ; i++){
		cout << isRoot[i]-1 << " ";
	}
	cout << isRoot[ans-1]-1;
}