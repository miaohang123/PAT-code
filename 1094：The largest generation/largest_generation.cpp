#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
int n, m;
vector<int> Node[MAXN];

void DFS(int index, int depth){
	
}

int main(){
	int child;
	while(cin >> n >> m){
		for(int i = 0; i < m; i++){
			int index, k;
			cin >> index >> k;
			for(int j = 0; j < k; j++){
				cin >> child;
				Node[index].push_back(child);
			}
		}
	}
	return 0;
}