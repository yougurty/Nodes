#include <iostream>
#include <vector>
//���������

using namespace std;

int n, num = 0;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
vector<int> origin, pre ,preM , post, postM;

//����Ҫ������root����δ���һ��BST��������֮��
void insert( node* &root , int x){
	if(root == NULL){
		root = new node;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return ;
	}
	if(x >= root->data) {
		insert(root->rchild , x);
	}else {
		insert(root->lchild ,  x);
	}
	
}
void preorder(node* root){
	if(root == NULL) return;
	pre.push_back(root->data);
	//cout << num<<endl;num++;
	preorder(root->lchild);
	preorder(root->rchild);
}
void preorderM(node* root ){
	if(root == NULL) return;
	preM.push_back(root->data);
//	cout << num<<endl;num++;
	preorderM(root->rchild);
	preorderM(root->lchild);
}
void postorder(node* root){
	if(root == NULL) return;
	//cout << num<<endl;num++;
	postorder(root->lchild);
	postorder(root->rchild);
	post.push_back(root->data);
}
void postorderM(node* root ){
	if(root == NULL) return;
//	cout << num<<endl;num++;
	postorderM(root->rchild);
	postorderM(root->lchild);
	postM.push_back(root->data);
}

int main(int argc, char *argv[]) {
	int a;
	cin >> n;
	node* root = NULL;			//��仰�ܹؼ���һ��ʼд����node* root = new Node��pre��preM����origin��һ������
	for(int i = 0 ; i < n ; i++){
		cin >> a;
		origin.push_back(a);	//���ʼ��
		insert(root , a);
	}	
//	//������Ӧ���ǽ�����BST
	preorder(root);
	preorderM(root);
	postorder(root);
	postorderM(root);
//	for(int i = 0 ; i < pre.size(); i++)
//		cout << pre[i] <<" ";
//	cout << endl;
	//cout <<pre.size()<<" "<< preM.size()<<" "<< origin.size();
	if(pre == origin){
		cout << "YES"<<endl;
		for(int i = 0 ; i < post.size()-1; i++)
				cout << post[i] <<" ";
			cout << post[post.size()-1]<<endl;
	}
	else if(origin == preM){
		cout << "YES"<<endl;
		for(int i = 0 ; i < postM.size()-1; i++)
				cout << postM[i] <<" ";
			cout << postM[postM.size()-1]<<endl;
	}else {
		cout << "NO" <<endl;
	}
	
}