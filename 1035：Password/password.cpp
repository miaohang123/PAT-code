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
const int MAXN = 1010;
struct User
{
	string name;
	string psd;
	bool mark;
};
User user[MAXN];

bool check(string str){
	for(int i = 0; i < str.size(); i++){
		if(str[i] == '0' || str[i] == 'O' || str[i] == '1' || str[i] == 'l'){
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	//string name, psd, res;
	while(cin >> n){
		int ans = 0;
		for(int i = 0; i < n; i++){
			cin >> user[i].name >> user[i].psd;
			user[i].mark = false;
			bool flag = check(user[i].psd);
			if(flag){
				ans++;
				user[i].mark = true;
				string tmp ;
				for(int j = 0; j < user[i].psd.size(); j++){
					if(user[i].psd[j] == '1'){
						tmp += '@';
					}else if(user[i].psd[j] == 'l'){
						tmp += 'L';
					}else if(user[i].psd[j] == '0'){
						tmp += '%';
					}else if(user[i].psd[j] == 'O'){
						tmp += 'o';
					}else{
						tmp += user[i].psd[j];
					}
				}
				user[i].psd = tmp;
			}
		}
		if(ans == 0){
			if(n > 1){
				cout << "There are " << n << " accounts and no account is modified" << endl;
			}else{
				cout << "There is " << n << " account and no account is modified" << endl;
			}
		}else{
			printf("%d\n", ans);
			for(int i = 0; i < n; i++){
				if(user[i].mark){
					cout << user[i].name << " " << user[i].psd << endl;
				}
			}
		}
	}
	return 0;
}