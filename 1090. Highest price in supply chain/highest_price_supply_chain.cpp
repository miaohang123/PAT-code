#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100050;
vector<int> child[MAXN];
int maxDepth = 0, num = 0;
int n;
double p, r;

void DFS(int index, int depth){
	if(child[index].size() == 0){
		if(depth > maxDepth){
			maxDepth = depth;
			num = 1;
		}else if(depth == maxDepth){
			num++;
		}
		return;
	}
	for(int i = 0; i < child[index].size(); i++){
		DFS(child[index][i], depth + 1);
	}
}
int main(){
	int father, root;
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++){
		scanf("%d", &father);
		if(father != -1){
			child[father].push_back(i);
		}else{
			root = i;
		}
	}
	DFS(root, 0);
	double res = p * pow(1 + r, maxDepth);
	printf("%.2f %d\n", res, num);
	return 0;
}