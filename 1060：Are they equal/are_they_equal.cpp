#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <string>
using namespace std;

int main(){
	int n;
	string str1, str2;
	while(cin >> n){
		bool flag = false;
		cin >> str1 >> str2;
		string signStr1, signStr2;
		signStr1 = str1.substr(0, n);
		signStr2 = str2.substr(0, n);
		if(signStr1 == signStr2){
			flag = true;
		}else{
			flag = false;
		}
		if(flag){
			cout << "YES" << " " << "0." << signStr1 << "*10^" << n << endl;
		}else{
			cout << "NO" << " " << "0." << signStr1 << "*10^" << n << " " << "0." << signStr2 << "*10^" << n << endl;
		}
	}
	return 0;
}