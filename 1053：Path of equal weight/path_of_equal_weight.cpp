#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 105;
int n, m, s;
struct Node
{
	int weight;
	vector<int> child;
};
Node node[MAXN];
int path[MAXN];

bool cmp(int a, int b){
	return node[a].weight > node[b].weight;
}

void DFS(int index, int nodeNum, int sum){
	if(sum > s) return;
	if(sum == s){
		if(node[index].child.size() != 0) return;
		for(int i = 0; i < nodeNum; i++){
			if(i != nodeNum - 1) cout << node[path[i]].weight << " ";
			else cout << node[path[i]].weight << endl;
		}
		return;
	}
	if(sum < s){
		for(int i = 0; i < node[index].child.size(); i++){
			int child = node[index].child[i];
			path[nodeNum] = child;
			DFS(child, nodeNum + 1, sum + node[child].weight);
		}
	}
}

int main(){
	int id, k, child;
	while(cin >> n >> m >> s){
		for(int i = 0; i < n; i++){
			cin >> node[i].weight;
		}
		for(int i = 0; i < m; i++){
			cin >> id >> k;
			if(k != 0){
				for(int j = 0; j < k; j++){
					cin >> child;
					node[id].child.push_back(child);
				}
				sort(node[id].child.begin(), node[id].child.end(), cmp);
			}
		}
		DFS(0, 1, node[0].weight);
	}
	return 0;
}