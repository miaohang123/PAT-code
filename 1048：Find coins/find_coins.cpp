#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
const int MAXN = 1010;
int hashTable[MAXN] = {0};
int n, m;

int main(){
	while(scanf("%d %d", &n, &m) != EOF){
		memset(hashTable, 0, sizeof(hashTable));
		for(int i = 0; i < n; i++){
			int num;
			scanf("%d", &num);
			hashTable[num]++;
		}
		bool flag = false;
		int i;
		for(i = 0; i < MAXN ; i++){
			if(hashTable[i] && hashTable[m - i]){
				if(i == m - i && hashTable[i] <= 1) continue;
				printf("%d %d\n", i, m - i);
				flag = true;
				break;
			}
		}
		if(!flag) printf("No Solution\n");
	}
	return 0;
}