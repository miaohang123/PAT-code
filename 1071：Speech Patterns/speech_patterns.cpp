#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 1001;
bool judge(char c){
	if(c >= '0' && c <= '9') return true;
	else if(c >= 'a' && c <= 'z') return true;
	else if(c >= 'A' && c <= 'Z') return true;
	else return flase;
}
int main(){
	string str; 
	getline(cin, str);
	int i = 0;
	map<string, int> mp;
	while(i < str.length()){
		string word;
		while(judge[str[i]] && i < str.length()){
			if(str[i] >= 'A' && str[i] <= 'Z'){
				str[i] += 32;
			}
			word += str[i];
			i++;
		}
		if(word != ""){
			if(mp.find(word) == mp.end()) mp[word] = 1;
			else{
				mp[word]++;
			}
		}
		while((!judge[str[i]]) && i < str.length()) i++;
	}
	int res = -1;
	string word;
	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
		if(it->second > max){
			res = it->second;
			word = it->first;
		}
	}
	cout <<word <<" " <<res <<endl;
	return 0;
}