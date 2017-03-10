#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
const int MAXN = 1001;
int n, m, k;
int Tree[MAXN];
vector<int> G[MAXN];
int findRoot(int x){
	if(Tree[x] == -1) return x;
	else{
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}
void Union(int a, int b){
	a = findRoot(a);
	b = findRoot(b);
	if(a != b){
		Tree[a] = b;
	}
}
void init(){
	for(int i = 1; i <= n; i++){
		Tree[i] = -1;
	}
}
int main(){
	while(cin >>n >>m >>k){
		for(int i =1 ; i <= m; i++){
			int a, b;
			cin >>a >>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		for(int query = 0; query < k; query++){
			init();
			int current;
			cin >>current;
			for(int i = 1; i <= n; i++){
				for(int j = 0; j < G[i].size(); j++){
					int u = i, v = G[i][j];
					if(u == current || v == current) continue;
					Union(u, v);
				}
			}
			int res = 0;
			for(int i = 1; i <= n; i++){
				if(i == current) continue;
				if(Tree[i] == -1) res++;
			}
			cout <<res - 1 <<endl;
		}
	}
	return 0;
}