#include <iostream>
#include <stack>
#include <cstring>	//必须使用cstring。查阅资料：ctring是C++版本的头文件，，包含比如说strcpy之类的字符串处理函数
//1086
//在已知先序中序求后序熟悉的情况下，难在于字符串的输入和鉴别
using namespace std;
int pre[31];
int in[31];
int n, num = 0;
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
	
	cout << root->data;
	num++;
	if(num<n) cout<<" ";
	

}

int main(int argc, char *argv[]) {
	
	cin >> n;
	stack<int> s;
	char str[5];		//设为5的意思是，如果是Push 2 恰好2还有前面的空格不进str里面。。
	int x ;  //临时变liang
	int preindex = 0 , inindex=0;
	for(int i = 0 ; i < 2*n ; i++){
		cin >> str;
		if( strcmp(str,"Push") == 0 )	//入栈
		{
			cin >> x;
			s.push(x);
			pre[preindex] = x;
			preindex++;
		}else{
			in[inindex] = s.top();
			//cout << in[inindex]<<" "<<inindex <<endl;
			s.pop();
			inindex++;
		}
	}
	tree* root = new tree;
	root = fun(0,n-1,0,n-1);
	postorder(root);
}