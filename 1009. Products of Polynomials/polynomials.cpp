#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 2222;
struct Poly{
	int exp;
	double c;
};
Poly poly[MAXN];
double cof[MAXN] = {0};

int main(){
	int k1, k2;
	int count = 0;
	int exp;
	double c;
	scanf("%d", &k1);
	for(int i = 0; i < k1; i++){
		scanf("%d %lf", &poly[i].exp, &poly[i].c);
	}
	scanf("%d", &k2);
	for(int i = 0; i < k2; i++){
		scanf("%d %lf", &exp, &c);
		for(int j = 0; j < k1; j++){
			cof[exp + poly[j].exp] += c * poly[j].c;
		}
	}
	for(int i = 0; i < MAXN; i++){
		if(cof[i] != 0.0) count++;
	}
	printf("%d", count);
	for(int i = MAXN - 1; i >= 0; i--){
		if(cof[i] != 0) printf(" %d %.1f", i, cof[i]);
	}
	return 0;
}