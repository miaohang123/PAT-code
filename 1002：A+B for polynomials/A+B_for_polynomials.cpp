#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1111;
double cof[MAXN] = {0};

int main(){
	int k1, k2;
	int count = 0;
	scanf("%d", &k1);
	int n;
	double an;
	for(int i = 0; i < k1; i++){
		scanf("%d %lf", &n, &an);
		cof[n] += an;
	}
	scanf("%d", &k2);
	for(int i = 0; i < k2; i++){
		scanf("%d %lf", &n, &an);
		cof[n] += an;
	}
	for(int i = 0; i < MAXN; i++){
		if(cof[i] != 0) count++;
	}
	printf("%d", count);
	for(int i = MAXN - 1; i >= 0; i--){
		if(cof[i] != 0){
			printf(" %d %.1f", i, cof[i]);
		}
	}
	return 0;
}