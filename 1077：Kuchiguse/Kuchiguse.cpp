#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 110;
vector<string> str;

int main(){
	int n;
	while(cin >> n){
		str.clear();
		int minlen = 123123123;
		getchar();
		string temp;
		for(int i = 0; i < n; i++){
			getline(cin, temp);
			reverse(temp.begin(), temp.end());
			int len = temp.length();
			if(len < minlen){
				minlen = len;
			}
			str.push_back(temp);
		}
		int res = 0;
		for(int i = 0; i < minlen; i++){
			char c = str[0][i];
			bool flag = false;
			for(int j = 1; j < n; j++){
				if(c != str[j][i]){
					flag = true;
					break;
				}
			}
			if(!flag) res++;
			else break;
		}
		if(res == 0){
			cout << "nai" << endl;
		}else{
			for(int i = res - 1; i >= 0; i--){
				cout << str[0][i];
			}
			cout << endl;
		}
	}
	return 0;
}