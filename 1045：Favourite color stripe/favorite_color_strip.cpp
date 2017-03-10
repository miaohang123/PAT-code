#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 11111;
int dp[N];
int hashTable[N] = {-1};
int A[N];

int main(){
	int n, m, L, num = 0;
	while(cin >> n){
		memset(hashTable, -1, sizeof(hashTable));
		cin >> m;
		for(int i = 0; i < m; i++){
			int f;
			cin >> f;
			hashTable[f] = i;
		}
		cin >> L;
		for(int i = 0; i < L; i++){
			int x;
			cin >> x;
			if(hashTable[x] != -1){
				A[num++] = hashTable[x];
			}
		}
		//LSI
		int ans = -1;
		for(int i = 0; i < num; i++){
			dp[i] = 1;
			for(int j = 0; j < i; j++){
				 if(A[i] >= A[j] && dp[i] < dp[j] + 1){
				 	dp[i] = dp[j] + 1;
				 }
			}
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}