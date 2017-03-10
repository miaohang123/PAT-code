#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
const int MAXN = 1001;
struct Node
{
	int id;
	int layer;	
};
vector<Node> node[MAXN];
bool mark[MAXN] = {false};

int BFS(int s, int L){
	int res = 0;
	queue<Node> q;
	Node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	mark[start.id] = true;
	while(!q.empty()){
		Node now = q.front();
		q.pop();
		int u = now.id;
		for(int i = 0; i < node[u].size(); i++){
			Node next = node[u][i];
			next.layer = now.layer + 1;
			if(mark[next.id] == false && next.layer <= L){
				q.push(next);
				mark[next.id] = true;
				res++;
			}
		}
	}
	return res;
}

int main(){
	int n, L, m, u;
	Node user;
	while(scanf("%d %d", &n, &L) != EOF){
		for(int i = 1 ; i <= n; i++){
			user.id = i;
			scanf("%d", &m);
			if(m != 0){
				for(int j = 0; j < m; j++){
					scanf("%d", &u);
					node[u].push_back(user);
				}
			}
		}
		int k, start;
		scanf("%d", &k);
		for(int i = 0; i < k; i++){
			memset(mark, false, sizeof(mark));
			scanf("%d", &start);
			int res = BFS(start, L);
			printf("%d\n", res);
		}
	}
	return 0;
}