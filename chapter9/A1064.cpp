#include <iostream>
#include <algorithm>
//BST
using namespace std;

//给出n个负整数，要用它们构建完全二叉排序树。
//完全二叉树，CBT[maxn]完全可以用数组表示，一个节点的左孩子，和右孩子都是确定的了
//1064

const int maxn = 1001;
int n,num = 0;
int CBT[maxn] = {0};
int tree[maxn];
struct node{
	int data;
	node* lchild;
	node* rchild;
};
//	对完全二叉树进行中序遍历，同时进行赋值
void inorder(int root){
	if(root >n) return ;
	inorder(root*2);
	CBT[root] = tree[num];
//	cout << root<<endl;
	num++;
	inorder(root*2+1);
	
}
int main(int argc, char *argv[]) {
	
	cin	>> n;
	for(int i = 0 ; i < n ; i ++){
		int a;
		cin >> a;
		tree[i] = a;
	}
	sort(tree,tree+n);
	inorder(1);
	for(int i = 1 ; i<n ;i++){
		cout<<CBT[i]<<" ";
	 }
	cout << CBT[n]<<endl;
}

