#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
const int N = 100002;
int prime[N];
bool mark[N];
int primesize;
void init(){
	primesize = 0;
	for(int i = 2; i <= N; i++){
		if(mark[i]) continue;
		prime[primesize++] = i;
		if(i > 1000) continue;
		for(int j = i * i; j <= N; j += i){
			mark[j] = true;
		}
	}
}

int main(){
	init();
	int n;
	while(cin >>n && n > 1){
		int ansPrime[32];
		int ansSize = 0;
		int ansNum[32];
		for(int i = 0; i < primesize; i++){
			if(n % i == 0){
				ansPrime[ansSize] = prime[i];
				ansNum[ansSize] = 0;
				while(n % prime[i] == 0){
					ansNum[ansSize]++;
					n /= prime[i];
				}
				ansSize++;
				if(n == 1) break;
			}
		}
		if(n != 1){
			ansPrime[ansSize] = n;
			ansNum[ansSize++] = 1;
		}
		int ans = 0;
		for(int i = 0; i < ansSize; i++){
			ans += ansNum[i];
		}
		cout <<ans <<endl;
		for(int i = 0; i < ansSize - 1; i++){
			cout <<ansPrime[i] <<"*";
		}
		cout <<ansPrime[ansSize - 1] <<endl;
	}
	return 0;
}