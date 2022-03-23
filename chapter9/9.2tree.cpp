#include <iostream>
#include <cstdio>
//已知树的先序、中序求xx
using namespace std;

int pre[]={1,2,4,5,3};
int in[]={4,2,5,1,3};
//int pre[] ={1,2,4,5,3,6,7};
//int in[]= {4,2,5,1,6,3,7};
struct tree{
	int data;
	tree* lchild;
	tree* rchild;
};
tree* fun(int inL, int inR, int preL, int preR)
{
	//边界
	if(preL > preR) return NULL;
	//求先序的第几个等于pre[preL]
	tree* node = new tree;
	node->data = pre[preL]; 
	int k;
	for(int i = inL ;i<=inR; i++){
		if(in[i] == pre[preL]) {
			k=i;
			break;
		}
	}
	int num = k - inL;
	
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
	int n = 7;
	tree* root = new tree;
	root = fun(0,n-1,0,n-1);
 	postorder(root);
}