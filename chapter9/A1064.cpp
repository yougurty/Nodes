#include <iostream>
#include <algorithm>
//BST
using namespace std;

//����n����������Ҫ�����ǹ�����ȫ������������
//��ȫ��������CBT[maxn]��ȫ�����������ʾ��һ���ڵ�����ӣ����Һ��Ӷ���ȷ������
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
//	����ȫ�������������������ͬʱ���и�ֵ
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

