#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 1110;
int myindex = 0;
int cnt = 0;
int n;

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
	node[root].layer = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		//printf("%d", node[now].data);
		cnt++;
		//if(cnt < n) printf(" ");
		if(node[now].lchild != -1) q.push(node[now].lchild); node[node[now].lchild].layer = node[now].layer + 1;
		if(node[now].rchild != -1) q.push(node[now].rchild); node[node[now].rchild].layer = node[now].layer + 1;
	}
}

int main(){
	while(scanf("%d", &n) != EOF){
		int root = -1;
		init(n);
		for(int i = 0; i < n; i++){
			int data;
			scanf("%d", &data);
			insert(root, data);
		}
		BFS(root);
		int n1 = 0, n2 = 0;
		int max_layer = -1;
		for(int i = 0; i < n; i++){
			if(node[i].layer > max_layer){
				max_layer = node[i].layer;
			}
		}
		for(int i = 0; i < n; ++i)
		{
			if(node[i].layer == max_layer) n1++;
			else if(node[i].layer == max_layer - 1) n2++;
		}
		printf("%d + %d = %d\n", n1, n2, n1 + n2);
	}
	return 0;
}

