#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
const int MAXN = 10010;
struct E
{
	int next;
	int length;
	int time;
};
vector<E> edge[MAXN];
bool mark[MAXN] = { false };
int dis[MAXN];
int tim[MAXN];
int dis2[MAXN];
int tim2[MAXN];
int t_path[MAXN];
int d_path[MAXN];
int n, m;
int st, ed;
vector<int> tpath;
vector<int> dpath;

void Dijistra_shortest(int u){
	for (int i = 0; i < n; i++) d_path[i] = i;
	dis[u] = 0;
	tim[u] = 0;
	mark[u] = true;
	int newP = u;
	for (int i = 1; i < n; i++){
		for (int j = 0; j < edge[newP].size(); j++){
			int nextnode = edge[newP][j].next;
			int time = edge[newP][j].time;
			int distance = edge[newP][j].length;
			if (mark[nextnode]) continue;
			if (dis[nextnode] == -1 || dis[nextnode] > dis[newP] + distance){
				dis[nextnode] = dis[newP] + distance;
				tim[nextnode] = tim[newP] + time;
				d_path[nextnode] = newP;
			}
			else if (dis[nextnode] == dis[newP] + distance){
				if (tim[nextnode] > tim[newP] + time){
					tim[nextnode] = tim[newP] + time;
					d_path[nextnode] = newP;
				}
			}
		}
		int min = 123123123;
		for (int j = 0; j < n; j++){
			if (mark[j]) continue;
			if (dis[j] == -1) continue;
			if (dis[j] < min){
				min = dis[j];
				newP = j;
			}
		}
		mark[newP] = true;
	}
}
void Dijistra_fastest(int u){
	for (int i = 0; i < n; i++) t_path[i] = i;
	dis2[u] = 0;
	tim2[u] = 0;
	mark[u] = true;
	int newP = u;
	for (int i = 1; i < n; i++){
		for (int j = 0; j < edge[newP].size(); j++){
			int nextnode = edge[newP][j].next;
			int time = edge[newP][j].time;
			int distance = edge[newP][j].length;
			if (mark[nextnode]) continue;
			if (tim2[nextnode] == -1 || tim2[nextnode] > tim2[newP] + time){
				tim2[nextnode] = tim2[newP] + time;
				dis2[nextnode] = dis2[newP] + distance;
				t_path[nextnode] = newP;
			}
			else if (tim2[nextnode] == tim2[newP] + time){
				if (dis2[nextnode] > dis2[newP] + distance){
					dis2[nextnode] = dis2[newP] + distance;
					t_path[nextnode] = newP;
				}
			}
		}
		int min = 123123123;
		for (int j = 0; j < n; j++){
			if (mark[j]) continue;
			if (tim2[j] == -1) continue;
			if (tim2[j] < min){
				min = tim2[j];
				newP = j;
			}
		}
		mark[newP] = true;
	}
}
void DFS_Shortest(int v){
	if (v == st){
		//cout <<v <<" -> ";
		dpath.push_back(v);
		return;
	}
	DFS_Shortest(d_path[v]);
	//cout <<v <<" -> ";
	dpath.push_back(v);
}
void DFS_Fastest(int v){
	if (v == st){
		//cout <<v <<" -> ";
		tpath.push_back(v);
		return;
	}
	DFS_Fastest(t_path[v]);
	//cout <<v <<" -> ";
	tpath.push_back(v);
}
bool judge_identical(vector<int> &path1, vector<int> &path2){
	int len1 = path1.size();
	int len2 = path2.size();
	if (len1 != len2) return false;
	else{
		for (int i = 0; i < len1; i++){
			if (path1[i] != path2[i]){
				return false;
			}
		}
		return true;
	}
}
void init(){
	for (int i = 0; i < n; i++){
		mark[i] = false;
	}
}
int main(){
	while (cin >> n >> m && n != 0){
		for (int i = 0; i < n; i++){
			edge[i].clear();
			dis[i] = -1;
			tim[i] = -1;
			dis2[i] = -1;
			tim2[i] = -1;
		}
		tpath.clear();
		dpath.clear();
		for (int i = 0; i < m; i++){
			int v1, v2, my_length, my_time;
			bool flag;
			cin >> v1 >> v2 >> flag >> my_length >> my_time;
			E tmp;
			tmp.length = my_length;
			tmp.time = my_time;
			tmp.next = v2;
			edge[v1].push_back(tmp);
			if (!flag){
				tmp.next = v1;
				edge[v2].push_back(tmp);
			}
		}
		cin >> st >> ed;
		init();
		Dijistra_shortest(st);
		DFS_Shortest(ed);
		init();
		Dijistra_fastest(st);
		DFS_Fastest(ed);
		bool flag;
		flag = judge_identical(dpath, tpath);
		if (flag){
			cout << "Distance = " << dis[ed] << "; " << "Time = " << tim2[ed] << ": ";
			for (int i = 0; i < dpath.size(); i++){
				if (i < dpath.size() - 1){
					cout << dpath[i] << " -> ";
				}
				else{
					cout << dpath[i] << endl;
				}
			}
		}
		else{
			cout << "Distance = " << dis[ed] << ": ";
			for (int i = 0; i < dpath.size(); i++){
				if (i < dpath.size() - 1){
					cout << dpath[i] << " -> ";
				}
				else{
					cout << dpath[i] << endl;
				}
			}
			cout << "Time = " << tim2[ed] << ": ";
			for (int i = 0; i < tpath.size(); i++){
				if (i < tpath.size() - 1){
					cout << tpath[i] << " -> ";
				}
				else{
					cout << tpath[i] << endl;
				}
			}
		}
	}
	return 0;
}