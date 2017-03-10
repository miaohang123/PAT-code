#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100010;
vector<int> Node[MAXN];
int n, m;
int count[MAXN];
int maxdepth;
void init(){
	for(int i = 0; i < MAXN; i++){
		count[i] = -1;
	}
}

void DFS(int index, int level){
	if(Node[index].size() == 0){
		count[level]++;
		if(level > maxdepth){
			maxdepth = level;
		}
		return;
	}
	for(int i = 0; i < Node[index].size(); i++){
		DFS(Node[index][i], level + 1);
	}
}

int main(){
	int id, k, child;
	while(cin >> n >> m){
		init();
		for(int i = 0; i < m; i++){
			cin >> id >> k;
			if(k != 0){
				for(int j = 0; j < k; j++){
					cin >> child;
					Node[id].push_back(child);
				}
			}
		}
		DFS(1, 1);
		for(int i = 1; i < maxdepth; i++){
			cout << count[i] << " ";
		}
		cout << count[maxdepth] << endl;
	}
	return 0;
}