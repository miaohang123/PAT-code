#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
double num[MAXN];

int main(){
	int n;
	while(cin >>n){
		memset(num, 0, sizeof(num));
		double res = 0;
		for(int i = 0; i < n; i++){
			cin >>num[i];
		}
		for(int i = 0; i < n; i++){
			res += num[i] * (n - i) * (i + 1);
		}
		printf("%.2f\n", res);
	}
	return 0;
}