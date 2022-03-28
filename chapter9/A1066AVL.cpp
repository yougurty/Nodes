#include <iostream>
#include <algorithm>
//A1066--ƽ����
//�о�ƽ�����Ĳ���Ƚ��鷳���Ƚ�����
//������ȫ������AVL�Ļ�������
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

//����
void L(node* &root){
	node* temp = root->rchild; 
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

//����
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
		updateHeight(root);	//��������
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1)	R(root);	//LL��
			else if(getBalanceFactor(root->lchild) == -1){		//LR��
				L(root->lchild);		//	����LR�ͣ������������LL�ͣ�Ȼ��������
				R(root);
			}
		}
	}else{
		insert(root->rchild , x);
		updateHeight(root);	//��������
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->rchild) == -1)	L(root);	//RR��
			else if(getBalanceFactor(root->rchild) == 1){			//RL��
				R(root->rchild);			//	����RL�ͣ������������RR�ͣ�Ȼ����������
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