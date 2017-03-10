#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int N = 300;
const int MAXN = 10001;
struct E{
	int next;
};
vector<E> edge[N];

bool judge_connected(int a[], int n){
	int pre = a[0];
	for(int i = 1; i < n; i++){
		int flag = 0;
		for(int j = 0; j < edge[pre].size(); j++){
			if(a[i] == edge[pre][j].next){
				flag = 1;
			}
		}
		if(!flag) return false;
		pre = a[i];
	}
	return true;
}
bool judge_hamilton(int a[], int len, int n){
	if(a[0] != a[len - 1] || len != n + 1) return false;
	else if(!judge_connected(a, len)) return false;
	else{
		vector<int>times(len);
		for(int i = 0; i < len; i++){
			times[i] = 0;
		}
		for(int i = 0; i < len; i++){
			times[a[i]]++;
		}
		for(int i = 1; i < len; i++){
			if(i == a[0]){
				if(times[i] != 2) return false;
			}else{
				if(times[i] != 1) return false;
			}
		}
	}
	return true;
}

int main(){
	int n, m, k;
	while(cin >>n >>m && n != 0){
		while(m--){
			int s, t;
			cin >>s >>t;
			E tmp;
			tmp.next = t;
			edge[s].push_back(tmp);
			tmp.next = s;
			edge[t].push_back(tmp);
		}
		cin >>k;
		int query[MAXN];
		while(k--){
			memset(query, 0, sizeof(query));
			int len;
			cin >>len;
			for(int i = 0; i < len; i++){
				cin >>query[i];
			}
			bool flag = judge_hamilton(query, len, n);
			if(flag){
				cout <<"YES" <<endl;
			}else{
				cout <<"NO" <<endl;
			}
		}
	}
	return 0;
}