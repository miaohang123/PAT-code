#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
struct Node
{
	int data;
	int lchild, rchild;
};
Node node[MAXN];
vector<int> data;
vector<int> in_seq;
int count = 0, n;

void init(int n){
	for(int i = 0; i < n; i++){
		node[i].lchild = node[i].rchild = -1;
	}
}

void inOrder(int root){
	if(root == -1){
		return
	}
	inOrder(node[root].lchild);
	node[root].data = in_seq[count++];
	inOrder(node[root].rchild);
}

void BFS(int root){
	queue<int> q;
	q.push(root);
	count = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		printf("%d", node[q].data);
		count++;
		if(count < n)
	}
}


int main(){
	int left_index, right_index;
	while(scanf("%d", &n) != EOF){
		init(n);
		for(int i = 0; i < n; i++){
			scanf("%d %d", &left_index, &right_index);
			node[i].lchild = left_index;
			node[i].rchild = right_index;
		}
		for(int i = 0; i < n; i++){
			int num;
			scanf("%d", &num);
			data.push_back(num);
		}
		sort(data.begin(), data.end());

	}
	return 0;
}

