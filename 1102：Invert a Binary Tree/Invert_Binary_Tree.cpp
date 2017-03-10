
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn = 20;
bool notRoot[maxn] = { false };
struct Node
{
	int lchild, rchild;
};
Node node[maxn];
int n, num = 0;
void print(int id) {
	cout << id;
	num++;
	if (num < n) cout << " ";
	else cout << endl;
}

void inOrder(int root) {
	if (root == -1) {
		return;
	}
	inOrder(node[root].lchild);
	print(root);
	inOrder(node[root].rchild);
}

void bfs(int root) {
	queue<int>q;
	q.push(root);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		print(now);
		if (node[now].lchild != -1) q.push(node[now].lchild);
		if (node[now].rchild != -1) q.push(node[now].rchild);

	}
}
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
void postOrder(int root) {
	if (root == -1) {
		return;
	}
	postOrder(node[root].lchild);
	postOrder(node[root].rchild);
	swap(node[root].lchild, node[root].rchild);
}

int strToNum(char ch) {
	if (ch == '-') return -1;
	else {
		notRoot[ch - '0'] = true;
		return ch - '0';
	}
}
int findRoot() {
	for (int i = 0; i < n; i++) {
		if (notRoot[i] == false) {
			return i;
		}
	}
}

int main() {
	while (cin >> n) {
		char lchild, rchild;
		for (int i = 0; i < n; i++) {
			//scanf_s("%c %c", &lchild, &rchild);
			cin >> lchild >> rchild;
			node[i].lchild = strToNum(lchild);
			node[i].rchild = strToNum(rchild);
		}
		int root = findRoot();
		postOrder(root);
		bfs(root);
		num = 0;
		inOrder(root);
	}
	return 0;
}

