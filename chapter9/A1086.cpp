#include <iostream>
#include <stack>
#include <cstring>	//����ʹ��cstring���������ϣ�ctring��C++�汾��ͷ�ļ�������������˵strcpy֮����ַ���������
//1086
//����֪���������������Ϥ������£��������ַ���������ͼ���
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
	//�߽�
	if(preL > preR) return NULL;
	//������ĵڼ�������pre[preL]
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
	char str[5];		//��Ϊ5����˼�ǣ������Push 2 ǡ��2����ǰ��Ŀո񲻽�str���档��
	int x ;  //��ʱ��liang
	int preindex = 0 , inindex=0;
	for(int i = 0 ; i < 2*n ; i++){
		cin >> str;
		if( strcmp(str,"Push") == 0 )	//��ջ
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