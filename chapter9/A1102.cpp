#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
//A1102
//��ͨ��������������������ٿ��Ƿ�ת

int n;
int biTree[11][2]={0};
bool visit[11] = {false};
int num = 0;
void layerorder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		cout << top;
		num++;
		if(num < n) cout << " ";
//		cout<< "biTree[top][1]="<<biTree[top][1]<<"biTree[top][0]="<<biTree[top][0];
		if(biTree[top][1] != -1) q.push(biTree[top][1]);
		if(biTree[top][0] != -1) q.push(biTree[top][0]);
		
	}
	
}

void inorder(int root){
	if(root == -1) return;
	
	inorder(biTree[root][1]);
	cout << root;
	num++;
	if(num < n) cout << " ";
	inorder(biTree[root][0]);
	
}
////�������Ե�����ˣ����ο����ǣ������еĺ���ת
//void postorder(int root){
//	if(root == -1) return;
//	postorder(biTree[root][0]);
//	postorder(biTree[root][1]);
//	swap(biTree[root][0],biTree[root][1]);
//}

int main(int argc, char *argv[]) {
	cin >> n;
	char c1,c2;
	
	for(int i = 0 ; i < n ;i++){
		cin >> c1 >> c2;
		//cout << c1 << c2 << endl;
		if(c1 == '-') 
		biTree[i][0] = -1;	//û�����ӽڵ�
		else {
			biTree[i][0] = (int)(c1-'0');
			visit[biTree[i][0]] =true;
			//cout<<biTree[i][0]<<"df"<<endl;
			
		}
		if(c2 == '-') 
		biTree[i][1] = -1;	//û�����ӽڵ�
		else {
			biTree[i][1] = (int)(c2-'0');
			visit[biTree[i][1]] =true;		//Ϊʲôһֱ�������Ե�û�������Ǳ��ԭ������Ϊ�������biTree[i][1]д��biTree[i][0]
			//cout << biTree[i][1]<<endl;
		}
		
	}	

	int root = 0;
	for(int i = 0 ; i < n ; i++){
		if(visit[i] == false){
			root = i;
			break;
		}
	}
	//cout << root<<endl;
//	postorder(root);
	layerorder(root);
	cout << endl;
	num = 0;
	inorder(root);
	cout << endl;
}