#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
using namespace std;
const int N = 100005;

struct Stu
{
	int id;
	char name[8];
	int grade;
};
Stu stu[N];
bool cmp1(Stu a, Stu b){
	return a.id < b.id;
}
bool cmp2(Stu a, Stu b){
	int s = strcmp(a.name, b.name);
	if(s != 0) return s < 0;
	else return a.id < b.id;
}
bool cmp3(Stu a, Stu b){
	if(a.grade != b.grade) return a.grade < b.grade;
	else return a.id < b.id;
}
int main(){
	int n, c;
	while(scanf("%d %d", &n, &c) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].grade);
		}
		switch(c){
			case 1:{
				sort(stu, stu + n, cmp1);
				break;
			}
			case 2:{
				sort(stu, stu + n, cmp2);
				break;
			}
			case 3:{
				sort(stu, stu + n, cmp3);
				break;
			}
			default: break;
		}
		for(int i = 0 ; i < n; i++){
			printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
		}
	}
	return 0;
}