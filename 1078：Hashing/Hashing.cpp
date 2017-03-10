#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 11111;
bool hashTable[MAXN] = {false};

bool isPrime(int num){
	if(num <= 1) return false;
	int temp = (int)(sqrt(1.0 * num));
	for(int i = 2; i <= temp; i++){
		if(num % i == 0) return false;
	}
	return true;
}

int main(){
	int msize, n, num;
	while(scanf("%d %d", &msize, &n) != EOF){
		while(!isPrime(msize)){
			msize++;
		}
		for(int i = 0; i < n; i++){
			scanf("%d", &num);
			int index = num % msize;
			if(hashTable[index] == false){
				hashTable[index] = true;
				if(i == 0) printf("%d", index);
				else printf(" %d", index);
			}else{
				int step;
				for(step = 1; step < msize; step++){
					index = (num + step * step) % msize;
					if(hashTable[index] == false){
						hashTable[index] = true;
						if(i == 0) printf("%d", index);
						else printf(" %d", index);
						break;
					}
				}
				if(step >= msize){
					if(i > 0) printf(" ");
					printf("-");
				}
			}
		}
	}
	return 0;
}