#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int N = 1111;
struct Stu
{
	string name;
	string id;
	int grade;
};
Stu stu[N];
bool cmp(Stu a, Stu b){
	return a.grade > b.grade;
}

int main(){
	int n;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> stu[i].name >> stu[i].id >> stu[i].grade;
		}
		sort(stu, stu + n, cmp);
		int g_low, g_up;
		cin >> g_low >> g_up;
		bool flag = false;
		for(int i = 0; i < n; i++){
			if(stu[i].grade >= g_low && stu[i].grade <= g_up){
				flag = true;
				cout << stu[i].name << " " << stu[i].id << endl;
			}
		}
		if(flag == false) cout << "NONE" << endl;
	}
	return 0;
}