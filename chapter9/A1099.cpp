#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 101;
int n ,num = 0;
int list[maxn];
struct node{
	int data;
	int lchild;
	int rchild;
}Node[maxn];

void inorder(int root){
	if(root == -1) return ;
	inorder(Node[root].lchild);
	
	Node[root].data = list[num];
	num++;
	//cout << Node[root].data << " ";
	inorder(Node[root].rchild);
	
}

void bfs(int root){
	queue<int> q;
	q.push(root);
	num = 0;
	while( !q.empty() ){
		int top = q.front();
		q.pop();
		cout << Node[top].data;
		num++;
		if(num < n) cout <<" ";
		if(Node[top].lchild != -1) q.push(Node[top].lchild);
		if(Node[top].rchild != -1) q.push(Node[top].rchild);
	}
	
}
int main(int argc, char *argv[]) {
	
	cin >> n;
	for(int i = 0 ; i < n ;i++){
		int a,b;
		cin >> a >>b;
		Node[i].lchild = a;
		Node[i].rchild = b;
	}
	for(int i = 0 ; i < n ; i++) cin >> list[i];
	sort(list,list+n);
	inorder(0);
	//cout << endl;
	bfs(0);
	return 0;
}