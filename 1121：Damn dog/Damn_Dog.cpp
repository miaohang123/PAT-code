#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
map<string, string> couple;
set<string> dog;

int main(){
	int n, m;
	while(cin >>n && n != 0){
		string str1, str2;
		for(int i = 0; i < n; i++){
			cin >>str1 >>str2;
			couple[str1] = str2;
			couple[str2] = str1;
		}
		cin >>m;
		for(int i = 0; i < m; i++){
			string str;
			cin >>str;
			if(couple.find(str) == couple.end()){
				dog.insert(str);
			}
		}
		for(set<string>::iterator it = dog.begin(); it != dog.end; it++){
			set<string>::iterator tmp = it;
			if(++tmp != dog.end()){
				cout <<*it <<" ";
			}
			set<string>::iterator it = dog.end();
			cout <<*(--it) <<endl;
		}
	}
	return 0;
}