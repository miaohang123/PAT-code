#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 40010;
const int MAXM = 26 * 26 * 26 * 10 + 1;
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
	while(scanf("%d %d", &n, &k) != EOF){
		int course, numofstu;
		for(int i = 0; i < k; i++){
			scanf("%d %d", &course, &numofstu);
			for(int j = 0; j < numofstu; j++){
				scanf("%s", name);
				int id = getId(name);
				name_course[id].push_back(course);
			}
		}
		for(int i = 0; i < n; i++){
			scanf("%s",name);
			int id = getId(name);
			sort(name_course[id].begin(), name_course[id].end());
			printf("%s %d", name, name_course[id].size());
			for(int j = 0; j < name_course[id].size(); j++){
				printf(" %d", name_course[id][j]);
			}
			cout << endl;
		}
	}
	return 0;
}