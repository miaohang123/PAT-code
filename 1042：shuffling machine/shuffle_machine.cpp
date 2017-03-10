#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 55;
char mp[5] = {'S', 'H', 'C', 'D', 'J'};
int order[N];
int start[N];
int res[N];

int main(){
	int k;
	while(cin >> k){
		for(int i = 1; i <= N - 1; i++){
			start[i] = i;
		}
		for(int i = 1; i <= N - 1; i++){
			scanf("%d", &order[i]);
		}
		for(int i = 0; i < k; i++){
			for(int j = 1; j <= N - 1; j++){
				res[order[j]] = start[j];
			}
			for(int j = 1; j <= N - 1; j++){
				start[j] = res[j];
			}
		}
		for(int i = 1; i <= N - 1; i++){
			if(i != N - 1){
				printf("%c%d ", mp[(res[i] - 1) / 13], (res[i] - 1) % 13 + 1);
			}else{
				printf("%c%d\n", mp[(res[i] - 1) / 13], (res[i] - 1) % 13 + 1);
			}
		}
	}
	return 0;
}