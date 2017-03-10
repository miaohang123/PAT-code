#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 11111;
int dp[N];
int a[N];
int s[N] = {0};

int main(){
	int k;
	while(cin >> k){
		bool flag = false;
		for(int i = 0; i < k; i++){
			cin >> a[i];
			if(a[i] >= 0) flag = true;
		}
		if(!flag){
			cout << 0 << " " << a[0] << " " << a[k - 1] << endl;
			break;
		}
		dp[0] = a[0];
		for(int i = 1; i < k; i++){
			if(dp[i - 1] + a[i] > a[i]){
				dp[i] = dp[i - 1] + a[i];
				s[i] = s[i - 1];
			}else{
				dp[i] = a[i];
				s[i] = i;
			}
		}
		int index = 0;
		for(int i = 1; i < k; i++){
			if(dp[index] < dp[i]){
				index = i;
			}
		}
		cout << dp[index] << " " << a[s[index]] << " " << a[index] << endl;
	}
	return 0;
}