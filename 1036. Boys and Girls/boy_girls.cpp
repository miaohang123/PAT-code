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
const int MAXN = 10001;
struct Stu{
	char name[30];
	char gender;
	char id[30];
	int score;
};
Stu stu[MAXN];

int main(){
	int n;
	while(cin >>n){
		for(int i = 0; i < n; i++){
			cin >> stu[i].name >> stu[i].gender >> stu[i].id >> stu[i].score;
		}
		bool have_male = false, have_female = false;
		Stu res_male, res_female;
		int max_female = -1;
		int min_male = 123123123;
		for(int i = 0; i < n; i++){
			if(stu[i].gender == 'M'){
				have_male = true;
				if(stu[i].score < min_male){
					min_male = stu[i].score;
					res_male = stu[i];
				}
			}else{
				have_female = true;
				if(stu[i].score > max_female){
					max_female = stu[i].score;
					res_female = stu[i];
				}
			}
		}
		if(have_male && have_female){
			int dis = res_female.score - res_male.score;
			cout << res_female.name << " " << res_female.id << endl;
			cout << res_male.name << " " << res_male.id << endl;
			cout << dis <<endl;
		}else if(have_male && !(have_female)){
			cout << "Absent" << endl;
			cout << res_male.name << " " << res_male.id << endl;
			cout << "NA" <<endl; 
		}else{
			cout << res_female.name << " " << res_female.id << endl;
			cout << "Absent" << endl;
			cout << "NA" <<endl; 
		}
	}	
	return 0;
}