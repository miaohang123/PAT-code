#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <string>
using namespace std;
string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int strtoNum(string str){
	int res;
	if(str.find(" ") == string::npos){
		if(str == "tret") res = 0;
		else{
			for(int i = 1; i < 13; i++){
				if(str == unitDigit[i]){
					res = i;
					break;
				}else if(str == tenDigit[i]){
					res = i * 13;
					break;
				}
			}
		}
	}else{
		int ten = 0, unit = 0;
		string tenStr = str.substr(0, str.find(" "));
		string unitStr = str.substr(str.find(" ") + 1);
		for(int i = 0; i < 13; i++){
			if(tenStr == tenDigit[i]){
				ten = i;
				break;
			}
		}
		for(int i = 0; i < 13; i++){
			if(unitStr == unitDigit[i]){
				unit = i;
				break;
			}
		}
		res = ten * 13 + unit;
	}
	return res;
}

string numtoStr(int num){
	string res;
	int ten = num / 13;
	int unit = num % 13;
	if(ten == 0){
		res = unitDigit[unit];
	}else if(ten != 0 && unit == 0){
		res = tenDigit[ten];
	}else{
		res = tenDigit[ten] + " " + unitDigit[unit];
	}
	return res;
}

int main(){
	int n;
	string str;
	while(cin >> n){
		getchar(); 
		for(int i = 0; i < n; i++){
			getline(cin, str);
			if(str[0] >= '0' && str[0] <= '9'){
				int num = 0;
				for(int i = 0; i < str.length(); i++){
					num = num * 10 + (str[i] - '0');
				}
				string res = numtoStr(num);
				cout << res << endl;
			}else{
				int res = strtoNum(str);
				cout << res << endl;
			}
		}
	}
	return 0;
}