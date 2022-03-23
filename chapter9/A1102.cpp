#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
//A1102
//先通过描述构造出二叉树，再考虑反转

int n;
int biTree[11][2]={0};
bool visit[11] = {false};
int num = 0;
void layerorder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		cout << top;
		num++;
		if(num < n) cout << " ";
//		cout<< "biTree[top][1]="<<biTree[top][1]<<"biTree[top][0]="<<biTree[top][0];
		if(biTree[top][1] != -1) q.push(biTree[top][1]);
		if(biTree[top][0] != -1) q.push(biTree[top][0]);
		
	}
	
}

void inorder(int root){
	if(root == -1) return;
	
	inorder(biTree[root][1]);
	cout << root;
	num++;
	if(num < n) cout << " ";
	inorder(biTree[root][0]);
	
}
////两个测试点过不了，看参考答案是，先所有的后序反转
//void postorder(int root){
//	if(root == -1) return;
//	postorder(biTree[root][0]);
//	postorder(biTree[root][1]);
//	swap(biTree[root][0],biTree[root][1]);
//}

int main(int argc, char *argv[]) {
	cin >> n;
	char c1,c2;
	
	for(int i = 0 ; i < n ;i++){
		cin >> c1 >> c2;
		//cout << c1 << c2 << endl;
		if(c1 == '-') 
		biTree[i][0] = -1;	//没有左子节点
		else {
			biTree[i][0] = (int)(c1-'0');
			visit[biTree[i][0]] =true;
			//cout<<biTree[i][0]<<"df"<<endl;
			
		}
		if(c2 == '-') 
		biTree[i][1] = -1;	//没有右子节点
		else {
			biTree[i][1] = (int)(c2-'0');
			visit[biTree[i][1]] =true;		//为什么一直两个测试点没过，不是别的原因，是因为！这里的biTree[i][1]写成biTree[i][0]
			//cout << biTree[i][1]<<endl;
		}
		
	}	

	int root = 0;
	for(int i = 0 ; i < n ; i++){
		if(visit[i] == false){
			root = i;
			break;
		}
	}
	//cout << root<<endl;
//	postorder(root);
	layerorder(root);
	cout << endl;
	num = 0;
	inorder(root);
	cout << endl;
}