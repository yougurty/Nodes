#include <iostream>
#include <vector>

using namespace std;
const int maxn= 100001;
int N ;
double P , r ,maxp = 0;
int num = 0;	//叶节点个数
struct tree{
	double data;
	vector<int> child;
	
}Node[maxn];

void dfs(int root){
	
	if(Node[root].child.size() == 0){
		//num++;		题目的意思是价格是最高价格的结点有多少个。
		if(Node[root].data > maxp) {
			maxp = Node[root].data;
			num = 1;
		}
		else if(Node[root].data == maxp) num++;
		return ;
	}
	
	for(int i = 0 ; i< Node[root].child.size() ; i++){
		int a = Node[root].child[i];
		Node[a].data = Node[root].data*(1+r/100);
		//cout << Node[a].data<<endl;
		dfs(a);
	}
	
}
int main(int argc, char *argv[]) {
	int root;
	cin >> N >> P >> r;
	
	for(int i = 0 ; i < N ; i++){
		int a;
		cin >> a;
		if(a == -1) {
			root = i;
			continue;
		}
		Node[a].child.push_back(i);
	}
	//把树建好了
	Node[root].data = P;
	//cout << Node[root].child.size()<<endl;
	dfs(root);
	//cout << maxp << " "<<num;
	printf("%.2lf %d\n", maxp,num);
}