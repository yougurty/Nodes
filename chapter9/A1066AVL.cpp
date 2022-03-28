#include <iostream>
#include <algorithm>
//A1066--平衡树
//感觉平衡树的插入比较麻烦，先建树吧
//这里面全部都是AVL的基本操作
using namespace std;
int n;
struct node{
	int data,height;
	node* lchild;
	node* rchild;
}*root;
node* newNode(int x){
	node* Node = new node;
	Node->data = x;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}
int getHeight(node* root){
	if(root == NULL) return 0;
	return root->height;
}
void updateHeight(node* &root){
	root->height = 1+ max(getHeight(root->lchild) , getHeight(root->rchild));
	
}
int getBalanceFactor(node* root){
	
	return getHeight(root->lchild) - getHeight(root->rchild);
}

//左旋
void L(node* &root){
	node* temp = root->rchild; 
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

//右旋
void R(node* &root){
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node* &root , int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	
	if(x < root->data){
		insert(root->lchild , x);
		updateHeight(root);	//更新树高
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1)	R(root);	//LL型
			else if(getBalanceFactor(root->lchild) == -1){		//LR型
				L(root->lchild);		//	对于LR型，先左旋，变成LL型，然后用右旋
				R(root);
			}
		}
	}else{
		insert(root->rchild , x);
		updateHeight(root);	//更新树高
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->rchild) == -1)	L(root);	//RR型
			else if(getBalanceFactor(root->rchild) == 1){			//RL型
				R(root->rchild);			//	对于RL型，先右旋，变成RR型，然后用左旋。
				L(root);
			}
		}

	}
}
int main(int argc, char *argv[]) {
	cin >> n;
	node* root = NULL;
	for(int i = 0 ; i < n ;i ++){
		int x;
		cin >>x;
		insert(root, x);
	}
	cout << root->data;
	return 0;
}