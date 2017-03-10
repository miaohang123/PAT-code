#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 502;
const int INF = 123123123;
struct E
{
	int next;
	int c;
};
vector<E> edge[N];
bool mark[N];
int dis[N];
int weight[N];
int num[N];
int w[N];

void init(){
	memset(mark, 0, sizeof(mark));
	for(int i = 0; i < N; i++){
		dis[i] = -1;
	}
	memset(w, 0, sizeof(w));
}
void Dijistr(int s, int n){
	int newP = s;
	dis[newP] = 0;
	w[newP] = weight[s];
	num[newP] = 1;
	mark[newP] = true;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < edge[newP].size(); j++){
			int t = edge[newP][j].next;
			int c = edge[newP][j].c;
			if(mark[t] == true) continue;
			if(dis[t] == -1 || dis[t] > dis[newP] + c){
				dis[t] = dis[newP] + c;
				w[t] = weight[t] + w[newP];
				num[t] = num[newP];
			}
			else if(dis[t] == dis[newP] + c){
				if(w[t] < w[newP] + weight[newP]){
					w[t] = w[newP] + weight[t];
				}
				num[t] += num[newP];
			}
		}
		int min = INF;
		for(int j = 0; j < n; j++){
			if(mark[j]) continue;
			if(dis[j] == -1) continue;
			if(dis[j] < min){
				min = dis[j];
				newP = j;
			}
		}
		mark[newP] = true;
	}
}
int main(){
	int n, m, st, ed;
	while(cin >>n >>m){
		cin >>st >>ed;
		for(int i = 0; i < n; i++){
			cin >>weight[i];
		}
		for(int i = 0; i < m; i++){
			int a, b, cost;
			cin >>a >>b >>cost;
			E tmp;
			tmp.next = b;
			tmp.c = cost;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
		}
		init();
		Dijistr(st, n);
		cout <<num[ed] <<" " <<w[ed] <<endl;
	}
	return 0;
}
