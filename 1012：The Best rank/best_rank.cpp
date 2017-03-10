#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int N = 2000;
struct Stu
{
	int id;
	int grade[4];
};
Stu stu[N];
int now;
char course[4] = {'A', 'C', 'M', 'E'};
int Rank[1000000][4] = {0};

bool cmp(Stu a, Stu b){
	return a.grade[now] > b.grade[now];
}

int main(){
	int n, m;
	while(cin >> n >> m && n != 0){
		for(int i = 0; i < n; i++){
			cin >> stu[i].id >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
			stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]);
		}
		for(now = 0; now < 4; now++){
			sort(stu, stu + n, cmp);
			Rank[stu[0].id][now] = 1;
			for(int i = 1; i < n; i++){
				if(stu[i].grade[now] == stu[i - 1].grade[now]){
					Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];
				}else{
					Rank[stu[i].id][now] = i + 1;
				}
			}
		}
		for(int i = 0; i < m; i++){
			int query;
			cin >> query; 
			if(Rank[query][0] == 0){
				cout << "N/A" << endl;
			}else{
				int index = 0;;
				for(int j = 0; j < 4; j++){
					if(Rank[query][j] < Rank[query][index]){
						index = j;
					}
				}
				cout << Rank[query][index] << " " << course[index] << endl;
			}
		}
	}
	return 0;
}