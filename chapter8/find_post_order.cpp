#include <iostream>

using namespace std;

//int post[]={4,5,2,3,1};//{4,5,2,3,1
//int pre[] = {1,2,4,5,3};//1,2,4,5,3
//int in[] = {4,2,5,1,3};//4,2,5,1,3
int pre[20] ={4,1,6,3,5,7,2};
int post[20]={2,3,1,5,7,6,4};
int in[20]= {1,2,3,4,5,6,7};
struct tree{
	int data;
	tree* lchild;
	tree* rchild;
};

tree* fun(int inL, int inR, int preL, int preR){
	if(preL > preR) return NULL;
	tree* node = new tree;
	node->data = pre[preL];
	int k;
	for(int i = inL; i<=inR ; i++){
		if(in[i] == pre[preL]){
			k = i;
			break;
		}
	}
	int num = k-inL;
	node->lchild = fun(inL, k-1 ,preL+1 , preL+num );
	node->rchild = fun(k+1 , inR , preL+num+1 , preR);
	return node;
}
void postorder(tree* root){
	if(root == NULL) return;
	postorder(root->lchild);
	postorder(root->rchild);
	cout << root->data<<" ";

}
int main(int argc, char *argv[]) {
	tree* root = new tree;
//	root = fun(0,4,0,4);
	root = fun(0,6,0,6);
	postorder(root);
}