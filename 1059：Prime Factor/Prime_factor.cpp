#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	long long n;
	while(cin >>n && n > 0){
		long long bound = (long long)(sqrt(1.0 * n))+ 1;
		long long maxLen = 0, maxIndex = 0;
		for(long long i = 2; i <= bound; i++){
			long long current = 1;
			long long j = i;
			while(1){
				current *= j;
				if(n % current != 0) break;
				if(j - i + 1 > maxLen){
					maxLen = j - i + 1;
					maxIndex = i;
				}
				j++;
			}
		}
		if(maxLen == 0){
			cout <<"1" <<endl <<n <<endl;
		}
		else{
			cout <<maxLen <<endl;
			for(int i = 0; i < maxLen - 1; i++){
				cout <<maxIndex + i <<"*";
			}
			cout <<maxIndex + maxLen - 1 <<endl;
		}
	}
	return 0;
}