#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
map<string, set<int> >mpTitle, mpAuthor, mpKey, mpPub, mpYear;
void query(map<string, set<int> >& mp, string& str){
	if(mp.find(str) == mp.end()){
		cout <<"Not Found" <<endl;
	}
	else{
		for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++){
			cout <<*it <<endl;
		}
	}
}
int main(){
	int n, m, id, type;
	string title, author, key, pub, year;
	while(cin >>n && n != 0){
		cin >>id;
		getchar();
		getline(cin, title);
		mpTitle[title].insert(id);
		getline(cin, author);
		mpAuthor[author].insert(id);
		while(cin >>key){
			mpKey[key].insert(id);
			char c = getchar();
			if(c == '\n') break;
		}
		getline(cin, pub);
		mpPub[pub].insert(id);
		getline(cin, year);
		mpYear[year].insert(id);
		cin >>m;
		char s;
		string tmp;
		for(int i = 0; i < m; i++){
			cin >>type >>s;
			getline(cin, tmp);
			switch(type){
				case 1: query(mpTitle, tmp);
				case 2: query(mpAuthor, tmp);
				case 3: query(mpKey, tmp);
				case 4: query(mpPub, tmp);
				case 5: query(mpYear, tmp);
				default: break;
			}
		}
	}
	return 0;
}