# 算法笔记
git add -A 所有的文件提交到缓存区
![](media/16476868509493/16477832484692.jpg)
## 第八章
### DFS
常见的DFS问题的解决办法，给定一个序列，枚举所有序列的所有子序列。也等价于枚举从N个整数中选K个数，使得满足一定特征。
考虑：递归，岔路口是什么，死胡同是什么条件，选/不选。
### BFS
以广度为第一优先级，当碰到岔路口，总是依次访问从该岔道口能直接到的所有节点，再按这些节点被访问的顺序去依次访问它们能直接到达的所有节点。

用队列，模板。
>
```
void BFS（int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        取出队首元素top；
        访问队首元素top；
        将队首元素出队；
        将top的下一层结点中未曾入队的结点全部入队，并设置为已入队。
    }
}
```

##第九章
### 树的基本知识点
### 树的遍历，不仅限于二叉树
注意树的建立
>
```
struct tree{
	int data;
	int weight;
	vector<int> child;
}Node[maxn];
```
记得对树的结点的遍历，
普通的树的遍历:
>先序遍历——DFS
>层次遍历——BFS
> 
```
for(int i = 0 ; i < Node[root].child.size() ; i++){
		dfs(Node[root].child[i]);	
	}
```
### 二叉查找树 BST
核心:给你序列，如何构造一个二叉排序树。典型A1043
二叉排序树最重要的性质：**中序遍历的值是递增的。**
>
```
//记得这里要引用，&root，因为涉及到了修改
struct node{
    int data;
    node* lchild;
    node* rchild;
};
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
int main(){
    node root = NULL;   //记得这里要是空节点，一开始写的是node* root = new Node；就不对
}
```
还有A1064，告诉我，完全二叉树可以直接用一个数组构造出来，利用下标可以找到左右孩子（2n和2n+1），数组的值代表树节点的值。

### 平衡树
A1066已经列举了所有基本的函数操作。核心在insert函数里面。
写的时候注意，`root==NULL？？`
类型判断如下：左旋和右旋的代码+下表

| root的平衡因子 | root->lchild/root->rchild | 类型 |
|----------------|---------------------------|------|
| 2              | 1                         | LL   |
| 2              | -1                        | LR   |
| -2             | 1                         | RL   |
| -2             | -1                        | RR   |


### 并查集
基本函数
>`令father[i] = 1 //初始化`
`int findFather(int x)  //寻找跟节点`
`void Union(int a, int b) //把两个集合合并`


### 堆
堆比较重要吧，面试也问到了。
>堆是一颗完全二叉树。一般用于优先队列的实现
>跟节点 >= 左右孩子 大顶堆
>跟节点 <= 左右孩子 小顶堆
1. 建堆的过程
    每次调整都是把结点从上往下调整。每次调整都是从[n/2]开始倒着枚举结点。倒着枚举的目的是**保证每个结点都是以其为根结点的子树中权值最大的结点**
   ` void downAdjust()`
1. 堆里删除最大的元素——用最后一个元素覆盖堆顶元素，然后对根结点进行调整。
2. 往堆里添加一个元素，把想要添加的元素放在数组最后，然后向上调整函数。
    主要就是该节点和根结点进行比较
    ` void upAdjust()和 void insert()`
    
    **堆排序**
    取出堆顶元素，然后将堆的最后一个元素替换至堆顶，再进行一次针对堆顶元素的向下调整。





