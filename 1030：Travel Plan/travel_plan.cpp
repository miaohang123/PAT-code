#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 502;
struct E
{
	int next;
	int c;
	int cost;
};
vector<E> edge[MAXN];
bool mark[MAXN] = {false};
int dis[MAXN];
int cost[MAXN];
int path[MAXN];
int n, m, st, ed;

void Dijistra(int st){
	mark[st] = true;
	dis[st] = 0;
	cost[st] = 0;
	for(int i = 0; i < n; i++){
		path[i] = i;
	}
	int newP = st;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < edge[newP].size(); j++){
			int nextnode = edge[newP][j].next;
			int mycost = edge[newP][j].cost;
			int distance = edge[newP][j].c;
			if(mark[nextnode]) continue;
			if(dis[nextnode] == -1 || dis[nextnode] > dis[newP] + distance){
				dis[nextnode] = dis[newP] + distance;
				cost[nextnode] = cost[newP] + mycost;
				path[nextnode] = newP;
			}else if(dis[nextnode] == dis[newP] + distance){
				if(cost[nextnode] > cost[newP] +mycost){
					cost[nextnode] = cost[newP] + mycost;
					path[nextnode] = newP;
				}
			}
		}
		int min = 123123123;
		for(int i = 0; i < n; i++){
			if(mark[i]) continue;
			if(dis[i] == -1) continue;
			if(dis[i] < min){
				min = dis[i];
				newP = i;
			}
		}
		mark[newP] = true;
	}
}
void DFS(int v){
	if(v == st){
		cout <<v <<" ";
		return;
	}
	DFS(path[v]);
	cout <<v <<" ";
}
int main(){
	while(cin >>n >>m >>st >>ed){
		for(int i = 0; i < n; i++){
			edge[i].clear();
		}
		memset(mark, 0, sizeof(mark));
		memset(dis, -1, sizeof(dis));
		memset(cost, -1, sizeof(cost));
		for(int i = 0; i < m; i++){
			E tmp;
			int from, to, distance, mycost;
			cin >>from >>to >>distance >>mycost;
			tmp.next = to;
			tmp.c = distance;
			tmp.cost = mycost;
			edge[from].push_back(tmp);
			tmp.next = from;
			edge[to].push_back(tmp);
		}
		Dijistra(st);
		DFS(ed);
		cout <<dis[ed] <<" " <<cost[ed] <<endl;
	}	
	return 0;
}