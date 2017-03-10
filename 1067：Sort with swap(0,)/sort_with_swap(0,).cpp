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
const int MAXN = 100010;
int seq[MAXN];

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int left = 0, res = 0, k = 1, num;
		for(int i = 0; i < n; i++){
			scanf("%d", &num);
			seq[num] = i;
			if(num != 0 && num != i){
				left++;
			}
		}
		while(left > 0){
			if(seq[0] == 0){
				for(int i = k; i < n; i++){
					if(seq[i] != i){
						swap(seq[0], seq[k]);
						res++;
						break;
					}
					k++;
				}
			}
			while(seq[0] != 0){
				swap(seq[0], seq[seq[0]]);
				res++;
				left--;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}

//
//
//
