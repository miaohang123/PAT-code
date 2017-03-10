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
struct Person
{
	char name[10];
	int age;
	int worth;
};
Person person[N];
Person valid[N];
int Age[201] = {0};

bool cmp(Person a, Person b){
	if(a.worth != b.worth) return a.worth > b.worth;
	else if(a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}

int main(){
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%s %d %d", person[i].name, &person[i].age, &person[i].worth);
		}
		sort(person, person + n, cmp);
		int val_num = 0;
		for(int i = 0; i < n; i++){
			if(Age[person[i].age] < 100){
				Age[person[i].age]++;
				valid[val_num++] = person[i];
			}
		}
		int m, Amin, Amax;
		for(int i = 0; i < k; i++){
			scanf("%d %d %d", &m, &Amin, &Amax);
			printf("Case #%d:\n", i + 1);
			int temp = m;
			for(int j = 0; j < val_num; j++){
				if(valid[j].age >= Amin && valid[j].age <= Amax){
					temp--;
					if(temp >= 0){
						printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worth);	
					}else{
						break;
					}
				}
			}
			if(temp == m){
				printf("None\n");
			}
		}
	}
	return 0;
}