#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
const int MAXN = 10010;
int hash_count[MAXN];

int main(){
	int n;
	while(cin >>n){
		vector<int> num;
		for(int i = 0; i < n; i++){
			int t;
			cin >>t;
			hash_count[t]++;
			num.push_back(t);
		}
		int res = -1;
		bool flag = 0;
		for(int i = 0; i < n; i++){
			if(hash_count[num[i]] == 1){
				res = num[i];
				flag = 1;
				break;
			}
		}
		if(flag){
			cout <<res <<endl;
		}else{
			cout <<"None" <<endl;
		}
	}
	return 0;
}