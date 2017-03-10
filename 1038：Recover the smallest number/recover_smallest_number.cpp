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
vector<string> seg;
bool cmp(string a, string b){
	return a + b  < b + a;
}
int main(){
	int n;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			string str;
			cin >> str;
			seg.push_back(str);
		}
		sort(seg.begin(), seg.end(), cmp);
		string res;
		for(int i = 0; i < n; i++){
			res += seg[i];
		}
		while(res.size() != 0 && res[0] == '0'){
			res.erase(res.begin());
		}
		if(res.size() == 0) cout << 0 << endl;
		else cout << res << endl;
	}
	return 0;
}

