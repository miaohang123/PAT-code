#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 50;
struct Node{
	int data;
	Node* lchild;
	Node* rchild;
};
int pre[maxn], in[maxn], post[maxn];
int n;
Node* create(int prel, int prer, int inl, int inr){
	if(prel > prer){
		return NULL;
	}
	Node* root = new Node;
	root->data = pre[prel];
	int k;
	for(k = inl; k <= inr; k++){
		if(in[k] == pre[prel]){
			break;
		}
	}
	int numleft = k - inl;
	root->lchild = create(prel + 1, prel + numleft, inl, k - 1);
	root->rchild = create(prel + numleft + 1, prer, k + 1, inr);
	return root;
}
int num = 0;
void postOrder(Node* root){
	if(root == NULL){
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	cout << root->data;
	num++;
	if(num < n) cout <<" ";
}
int main(){
	scanf("%d", &n);
	stack<int> st;
	char str[10];
	int x, preIndex = 0, inIndex = 0;
	for(int i = 0; i < 2 * n; i++){
		scanf("%s", str);
		if(strcmp(str, "Push") == 0){
			scanf("%d", &x);
			pre[preIndex++] = x;
			st.push(x);
		}else{
			in[inIndex++] = st.top();
			st.pop();
		}
	}
	Node* root = create(0, n - 1, 0, n - 1);
	postOrder(root);
	cout << endl;
	return 0;
}