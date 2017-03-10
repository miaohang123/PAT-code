#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
const int MAXN = 40001;
int n, m, k;
struct Stu{
	int GE, GI, final;
	int rank, id;
	int choice[6];
};
struct School
{
	int quota;
	int current_num;
	vector<int>admit_num;
	int lastadmit;
};
Stu stu[MAXN];
School sch[101];

bool cmp(Stu a, Stu b){
	if(a.final != b.final) return a.final > b.final;
	else return a.GE > b.GE;
}
int main(){
	while(cin >>n >>m >>k){
		for(int i = 0; i < m; i++){
			cin >>sch[i].quota;
		}
		for(int i = 0; i < n; i++){
			cin >>stu[i].GE >> stu[i].GI;
			stu[i].id = i;
			stu[i].final = stu[i].GE + stu[i].GI;
			for(int j = 0; j < k; j++){
				cin >>stu[i].choice[j];
			}
		}
		sort(stu, stu + n, cmp);
		//计算考生的排名;
		for(int i = 0; i < n; i++){
			if(i == 0) stu[i].rank = 0;
			else{
				if(stu[i].final == stu[i - 1].final && stu[i].GE == stu[i - 1].GE){
					stu[i].rank = stu[i - 1].rank;
				}else{
					stu[i].rank = i;
				}
			}
		}
		//模拟学校admit过程
		for(int i = 0; i < n; i++){
			int current_id = stu[i].id;
			for(int j = 0; j < k; j++){
				int choice = stu[i].choice[j];
				if(sch[choice].current_num < sch[choice].quota){
					sch[choice].current_num++;
					sch[choice].admit_num.push_back(current_id);
					sch[choice].lastadmit = current_id;
					break;
				}else if(sch[choice].current_num >= sch[choice].quota){
					if(i != 0 && stu[i].rank == stu[sch[choice].lastadmit].rank){
						sch[choice].current_num++;
						sch[choice].admit_num.push_back(current_id);
						sch[choice].lastadmit = current_id;
						break;
					}
				}
			}
		}
		for(int i = 0; i < m; i++){
			sort(sch[i].admit_num.begin(), sch[i].admit_num.end());
			if(sch[i].admit_num.size() != 0){
				for(int j = 0; j < sch[i].admit_num.size(); j++){
					if(j != sch[i].admit_num.size() - 1){
						cout << sch[i].admit_num[j] << " ";
					}else{
						cout << sch[i].admit_num[j] << endl;
					}
				}
			}else{
				cout << endl;
			}
		}
	}
	return 0;
}