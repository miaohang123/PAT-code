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

void insert(node* &root, int d){
	if(root == NULL){
		root = new node;
		root->data = d;
		root->lchild = root->rchild = NULL;
		return;
	}
	if(data < root->data) insert(root->lchild, d);
	else insert(root->rchild, d);
}


int main(){
	while(cin >> n){
		node *root = NULL;
		for(int i = 0; i < n; i++){
			int d;
			cin >> d;
			insert(root, d);
		}
		
	}
	return 0;
}

