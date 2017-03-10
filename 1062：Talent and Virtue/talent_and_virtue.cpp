#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int N = 100005;
struct Person
{
	char id[10];
	int virtue, talent, total;
	int flag;
};
Person person[N];

bool cmp(Person a, Person b){
	if(a.flag != b.flag) return a.flag < b.flag;
	else if(a.total != b.total) return a.total > b.total;
	else if(a.virtue != b.virtue) return a.virtue > b.virtue;
	else return strcmp(a.id, b.id) < 0;
}

int main(){
	int n, L, H;
	int m = 0;
	while(scanf("%d %d %d", &n, &L, &H) != EOF){
		for(int i = 0; i < n; i++){
			char id_num[10];
			int v_grade, t_grade;
			scanf("%s %d %d", id_num, &v_grade, &t_grade);
			if(v_grade >= L && t_grade >= L){
				strcpy(person[m].id, id_num);
				person[m].virtue = v_grade;
				person[m].talent = t_grade;
				person[m].total = v_grade + t_grade;
				if(v_grade >= H && t_grade >= H){
					person[m].flag = 1;
				}else if(v_grade >= H && t_grade < H){
					person[m].flag = 2;
				}else if(v_grade < H && t_grade < H && v_grade >= t_grade){
					person[m].flag = 3;
				}else{
					person[m].flag = 4;
				}
				m++;
			}
		}
		printf("%d\n", m);
		sort(person, person + m, cmp);
		for(int i = 0; i < m; i++){
			printf("%s %d %d\n", person[i].id, person[i].virtue, person[i].talent);
		}
	}
	return 0;
}