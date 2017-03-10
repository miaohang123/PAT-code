#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 1110;
int myindex = 0;
int n;
int max_layer = -1;
int Layer[MAXN]={0};

struct Node
{
	int data;
	int lchild, rchild;
	int layer;
};
Node node[MAXN];

void init(int n){
	for(int i = 0; i < n; i++){
		node[i].lchild = node[i].rchild = -1;
	}
}

int newNode(int u){
	node[myindex].data = u;
	node[myindex].lchild = node[myindex].rchild = -1;
	return myindex++;
}

void insert(int &root, int data){
	if(root == -1){
		root = newNode(data);
		return;
	}
	if(data < node[root].data) insert(node[root].lchild, data);
	else insert(node[root].rchild, data);
}

void BFS(int root){
	queue<int> q;
	q.push(root);
	node[root].layer = 1;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(node[now].layer > max_layer){
			max_layer = node[now].layer;	
		}
		Layer[node[now].layer] += 1;
		if(node[now].lchild != -1){
			node[node[now].lchild].layer = node[now].layer + 1;
			q.push(node[now].lchild); 
		}
		if(node[now].rchild != -1){
			node[node[now].rchild].layer = node[now].layer + 1;
			q.push(node[now].rchild); 
		}
	}
}

int main(){
	while(scanf("%d", &n) != EOF){
		int root = -1;
		for(int i = 0; i < n; i++){
			int data;
			scanf("%d", &data);
			insert(root, data);
		}
		BFS(root);
		int n1 = Layer[max_layer];
		int n2 = Layer[max_layer - 1];
		printf("%d + %d = %d\n", n1, n2, n1 + n2);
	}
	return 0;
}
