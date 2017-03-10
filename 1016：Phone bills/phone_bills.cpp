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
const int MAXN = 1001;
struct Record{
	char name[21];
	int month, day, hour, minute;
	bool states;
};
Record rec[MAXN];
Record tmp;
int toll[25];
bool cmp(Record a, Record b){
	int s = strcmp(a.name, b.name);
	if(s != 0) return s < 0;
	else if(a.month != b.month) return a.month < b.month;
	else if(a.day != b.day) return a.day < b.day;
	else if(a.hour != b.hour) return a.hour < b.hour;
	else return a.minute < b.minute;
}
void get_ans(int on, int off, int &total, int &res){
	tmp = rec[on];
	while(tmp.day < rec[off].day || tmp.hour < rec[off].hour || tmp.minute < rec[off].minute){
		res += toll[tmp.hour];
		total++;
		tmp.minute++;
		if(tmp.minute >= 60){
			tmp.minute = 0;
			tmp.hour++;
		}
		if(tmp.hour >= 24){
			tmp.hour = 0;
			tmp.day++;
		}
	}
}
int main(){
	for(int i = 0; i < 24; i++){
		scanf("%d", &toll[i]);
	}
	/*
	int tmp[25] = {10,10,10,10,10,10,20,20,20,15,15,15,15,15,15,15,20,30,20,15,15,10,10,10};
	for(int i = 0; i < 24; i++){
		toll[i] = tmp[i];
	}
	*/
	int n;
	cin >>n;
	char line[20];
	for(int i = 0; i < n; i++){
		scanf("%s", rec[i].name);
		scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].day, &rec[i].hour, &rec[i].minute);
		scanf("%s", line);
		if(!strcmp(line, "on-line")){
			rec[i].states = true;
		}else{
			rec[i].states = false;
		}
	}
	sort(rec, rec + n, cmp);
	int on = 0, off, next;
	while(on < n){
		next = on;
		int nextprint = 0;
		while(strcmp(rec[on].name, rec[next].name) == 0 && next < n){
			if(nextprint == 0 && rec[next].states == true){
				nextprint = 1;
			}else if(nextprint == 1 && rec[next].states == false){
				nextprint = 2;
			}
			next++;
		}
		if(nextprint < 2){
			on = next;
			continue;
		}
		int total_amount = 0;
		printf("%s %02d\n", rec[on].name, rec[on].month);
		while(on < next){
			while(on < next - 1 && !(rec[on].states == true && rec[on + 1].states == false)){
				on++;
			}
			off = on + 1;
			if(off == next){
				on = next;
				break;
			}
			printf("%02d:%02d:%02d ", rec[on].day, rec[on].hour, rec[on].minute);
			printf("%02d:%02d:%02d ", rec[off].day, rec[off].hour, rec[off].minute);
			int total_time = 0, ans = 0;
			get_ans(on, off, total_time, ans);
			cout <<total_time <<" ";
			printf("$%.2f\n", ans / 100.0);
			total_amount += ans;
			on = off + 1;
		}
		printf("Total amount: $%.2f\n", total_amount / 100.0);
	}	
	return 0;
}