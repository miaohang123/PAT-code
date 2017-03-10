#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100005;
int start[N];
int dis[N];

int main(){
	int n;
	int sum = 0, query;
	int left, right;
	while(scanf("%d", &n) != EOF){
		sum = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &start[i]);
			sum += start[i];
			dis[i] = sum;
		}
		scanf("%d", &query);
		for(int i = 0; i < query; i++){
			scanf("%d %d", &left, &right); 
			if(left > right) swap(left, right);
			int res = min(dis[right - 1] - dis[left - 1], sum - dis[right - 1] + dis[left - 1]);
			printf("%d\n", res);
		}
	}
	return 0;
}