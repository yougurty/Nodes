#include <iostream>

using namespace std;
const int maxn = 102;
int father[maxn];
bool isroot[maxn];	//�ǲ���һ�����ϵĸ��ڵ�
int n, m;

void init(){
	for(int i = 1 ; i <= n ; i++){
		father[i] = i;
		isroot[i] = true;
	}
	
		
	return ;
}
int findFather(int x){
	int a = x;
	if(father[x] != x){
		x = father[x];
	}
	//���������·��ѹ���Ĵ���
	//���� xΪ���ڵ�ı��,a��֮ǰ��x
	while(a != father[a]){
		int temp;
		temp = father[a];
		father[a] = x;
		a = temp;
		
	}
	return x;
	
}
void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
		isroot[faA] = false;
	}
		
}
int main(int argc, char *argv[]) {
	cin >> n>>m;
	init();
	for(int i = 0 ; i < m ;i++){
		int a, b;
		cin >> a >> b;
		Union(a,b);
	}
	int ans = 0;
	for(int i = 1 ; i <= n ;i++ ){
		if(isroot[i]){
			ans++;
			//cout << i <<" ";
		}
		
	}
	cout << ans<<endl;
}