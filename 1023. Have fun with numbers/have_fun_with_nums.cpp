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
const int MAXN = 22;
struct bign{
	int d[MAXN];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};
bign toBigN(string str){
	bign tmp;
	int len = str.size();
	tmp.len = len;
	for(int i = 0; i < len; i++){
		tmp.d[i] = str[len - i - 1] - '0';
	}
	return tmp;
}
bign muti(bign a, int b){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len; i++){
		int tmp = a.d[i] * b + carry;
		c.d[c.len++] = tmp % 10;
		carry = tmp / 10;
	}
	while(carry != 0){
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}
bool judge(bign a, bign b){
	if(a.len != b.len) return false;
	int count[10] = {0};
	for(int i = 0; i < a.len; i++){
		count[a.d[i]]++;
		count[b.d[i]]--;
	}
	for(int i = 0; i < 10; i++){
		if(count[i] != 0){
			return false;
		}
	}
	return true;
}

int main(){
	string s;
	while(cin >>s){
		bign a = toBigN(s);
		bign res = muti(a, 2);
		bool flag = judge(a, res);
		if(flag) cout <<"Yes" <<endl;
		else cout <<"No" <<endl;
		for(int i = res.len - 1; i >= 0; i--){
			cout <<res.d[i];
		}
		cout <<endl;
	}
	return 0;
}