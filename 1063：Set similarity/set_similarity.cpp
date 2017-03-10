#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int MAXN = 51;
set<int> num[MAXN];

int main(){
	int n, m, k;
	while(cin >> n){
		for(int i = 0; i < MAXN; i++){
			num[i].clear();
		}
		for(int i = 1; i <= n; i++){
			cin >> m;
			for(int j = 0; j < m; j++){
				int d;
				cin >> d;
				num[i].insert(d);
			}
		}
		cin >> k;
		for(int i = 0; i < k; i++){
			int query1, query2;
			cin >> query1 >> query2;
			int totalNum = num[query2].size();
			int sameNum = 0;
			for(set<int>::iterator it1 = num[query1].begin(); it1 != num[query1].end(); it1++){
				if(num[query2].find(*it1) != num[query2].end()) sameNum++;
				else totalNum++;
			}
			double res = (sameNum * 100.0) / totalNum;
			printf("%.1f%\n", res);
		}
	}
	return 0;
}