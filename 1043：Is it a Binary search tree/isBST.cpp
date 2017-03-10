#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
int n;
struct node
{
	int data;
	node *lchild, *rchild;
};

vector<int> origin, pre, preM, post, postM;

void insert(node* &root, int data){
	if(root == NULL){
		root = new node;
		root->data = data;
		root->lchild = root->rchild = NULL;
		return;
	}
	if(data < root->data) insert(root->lchild, data);
	else insert(root->rchild, data);
}

void preOrder(node *root, vector<int>& vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->lchild, vi);
	preOrder(root->rchild, vi);
}

void preOrderMirror(node *root, vector<int>& vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->rchild, vi);
	preOrderMirror(root->lchild, vi);
}

void postOrder(node *root, vector<int>& vi){
	if(root == NULL) return;
	postOrder(root->lchild, vi);
	postOrder(root->rchild, vi);
	vi.push_back(root->data);
}

void postOrderMirror(node *root, vector<int>& vi){
	if(root == NULL) return;
	postOrderMirror(root->rchild, vi);
	postOrderMirror(root->lchild, vi);
	vi.push_back(root->data);
}

int main(){
	while(cin >> n){
		node* root = NULL;
		origin.clear();
		pre.clear();
		preM.clear();
		post.clear();
		postM.clear();
		for(int i = 0; i < n; i++){
			int d;
			cin >> d;
			origin.push_back(d);
			insert(root, d);
		}
		preOrder(root, pre);
		preOrderMirror(root, preM);
		postOrder(root, post);
		postOrderMirror(root, postM);
		if(origin == pre){
			cout << "YES" << endl;
			for(int i = 0; i < post.size(); i++){
				if(i == post.size() - 1) cout << post[i] << endl;
				else cout << post[i] << " ";
			}
		}else if(origin == preM){
			cout << "YES" << endl;
			for(int i = 0; i < postM.size(); i++){
				if(i == postM.size() - 1) cout << postM[i] << endl;
				else cout << postM[i] << " ";
			}
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}

