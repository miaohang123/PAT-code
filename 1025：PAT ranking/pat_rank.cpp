#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
const int MAXN = 30030;
struct Testee{
	char id[30];
	int location;
	int local_rank;
	int total_rank;
	int scores;
};
Testee stu[MAXN];
bool cmp(Testee a, Testee b){
	if(a.scores != b.scores) return a.scores > b.scores;
	else return strcmp(a.id, b.id) < 0;
}
int main(){
	int n, k;
	int num = 0;
	while(cin >>n){
		for(int q = 0; q < n; q++){
			cin >>k;
			for(int i = 0; i < k; i++){
				stu[num].location = q + 1;
				scanf("%s %d", stu[num].id, &stu[num].scores);
				num++;
			}
			sort(stu + num - k, stu + num, cmp);
			stu[num - k].local_rank = 1;
			for(int i = num - k + 1; i < num; i++){
				if(stu[i].scores == stu[i - 1].scores){
					stu[i].local_rank = stu[i - 1].local_rank;
				}else{
					stu[i].local_rank = i - num + k + 1;
				}
			}
		}
		sort(stu, stu + num, cmp);
		stu[0].total_rank = 1;
		for(int i = 1; i < num; i++){
			if(stu[i].scores == stu[i - 1].scores){
				stu[i].total_rank = stu[i - 1].total_rank;
			}else{
				stu[i].total_rank = i + 1;
			}
		}
		printf("%d\n", num);
		for(int i = 0; i < num; i++){
			printf("%s %d %d %d\n", stu[i].id, stu[i].total_rank, stu[i].location, stu[i].local_rank);
		}
	}
	return 0;
}