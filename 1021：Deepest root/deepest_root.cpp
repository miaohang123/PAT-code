#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
vector<int> edge[MAXN];
set<int> temp, res;
int Tree[MAXN];

void init(int n){
	for(int i = 1; i <= n; i++){
		Tree[i] = -1;
		edge[i].clear();
	}
}

int findRoot(int x){
	if(Tree[x] == -1) return x;
	else{
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}

void Union(int a, int b){
	int fa = findRoot(a);
	int fb = findRoot(b);
	if(fa != fb){
		Tree[fa] = fb;
	}
}
int max_height = 0;

void DFS(int u, int height, int pre){
	if(height > max_height){
		max_height = height;
		temp.clear();
		temp.insert(u);
	}else if(height == max_height){
		temp.insert(u);
	}
	for(int i = 0; i < edge[u].size(); i++){
		if(edge[u][i] != pre){
			DFS(edge[u][i], height + 1, u);
		}
	}
}
int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		init(n);
		for(int i = 0; i < n - 1; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			edge[a].push_back(b);
			edge[b].push_back(a);
			Union(a, b);
		}
		int count = 0;            //the number of blocks
		for(int i = 1; i <= n; i++){
			if(Tree[i] == -1) count++;
		}
		if(count > 1){
			printf("Error: %d components\n", count);
		}else{
			DFS(1, 1, -1);
			res = temp;
			DFS(*res.begin(), 1, -1);
			for(set<int>::iterator it = temp.begin(); it != temp.end(); it++){
				res.insert(*it);
			}
			for(set<int>::iterator it = res.begin(); it != res.end(); it++){
				printf("%d\n", *it);
			}
		}

	}
	return 0;
}