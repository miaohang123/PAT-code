#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
const int MOD = 1000000007;
int leftP[MAXN] = {0};
int rightT[MAXN] = {0};
int main(){
	string str;
	cin >>str;
	int len = str.size();
	for(int i = 0; i < len; i++){
		if(i > 0){
			if(str[i] == 'P'){
				leftP[i] = leftP[i - 1] + 1;
			}else{
				leftP[i] = leftP[i - 1];
			}
		}
	}
	int res = 0;
	int numT = 0;
	for(int i = len - 1; i >= 0; i--){
		if(str[i] == 'T'){
			numT++;
		}
		else if(str[i] == 'A'){
			res += leftP[i] * numT;
		}
	}
	res = res % MOD;
	cout <<res <<endl;
	return 0;
}