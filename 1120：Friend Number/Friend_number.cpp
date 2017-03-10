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
vector<string> client;
int main(){
	int n, m;
	while(cin >>n && n != 0){
		string str1, str2;
		couple.clear();
		dog.clear();
		client.clear();
		for(int i = 0; i < n; i++){
			cin >>str1 >>str2;
			couple[str1] = str2;
			couple[str2] = str1;
		}
		cin >>m;
		for(int i = 0; i < m; i++){
			string str;
			cin >>str;
			client.push_back(str);
		}
		for(int i = 0; i < client.size(); i++){
			if(couple.find(client[i]) == couple.end()){
				dog.insert(client[i]);
			}else if(find(client.begin(), client.end(), couple[client[i]]) == client.end()){
				dog.insert(client[i]);
			}
		}
		cout <<dog.size() <<endl;
		for(set<string>::iterator it = dog.begin(); it != dog.end(); it++){
			set<string>::iterator tmp = it;
			if(++tmp != dog.end()){
				cout <<*it <<" ";
			}
		}
		set<string>::iterator it = dog.end();
		cout <<*(--it) <<endl;
	}
	return 0;
}