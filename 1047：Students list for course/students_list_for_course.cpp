#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 40010;
const int MAXM = 26 * 26 * 26 * 10;
vector<int> name_course[MAXM];

int getId(char name[]){
	int id = 0;
	for(int i = 0; i < 3; i++){
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}

int main(){
	int n, k;
	char name[5];
	while(cin >> n >> k){
		int course, numofstu;
		for(int i = 0; i < k; i++){
			cin >> course >> numofstu;
			for(int j = 0; j < numofstu; j++){
				cin >> name;
				int id = getId(name);
				name_course[id].push_back(course);
			}
		}
		for(int i = 0; i < n; i++){
			cin >> name;
			int id = getId(name);
			sort(name_course[id].begin(), name_course[id].end());
			cout << name << " " << name_course[id].size();
			for(int j = 0; j < name_course[id].size(); j++){
				cout << " " << name_course[id][j];
			}
			cout << endl;
		}
	}
	return 0;
}