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
struct Person{
	char name[10];
	int tall;
};
Person p[MAXN];
int raw[MAXN];
bool cmp(Person a, Person b){
	if (a.tall != b.tall) return a.tall < b.tall;
	else return strcmp(a.name, b.name) > 0;
}
int main(){
	int n, k;
	while (cin >> n >> k){
		for (int i = 0; i < n; i++){
			cin >>p[i].name >>p[i].tall;
		}
		int raw_num = n / k;
		int other_num = n - k * raw_num;
		sort(p, p + n, cmp);
		for (int i = 0; i < k; i++){
			if (i != k - 1) raw[i] = raw_num;
			else raw[i] = raw_num + other_num;
		}
		for (int i = k - 1; i >= 0; i--){
			int begin = i * raw_num;
			int end = i * raw_num + raw[i] - 1;
			int central = (int)(raw[i] / 2);
			vector<Person> tmp(raw[i] + 1);
			bool shoud_right = false;
			int count_left = 0, count_right = 0;
			for (int j = end; j >= begin; j--){
				if (j == end) tmp[central] = p[j];
				else{
					if (shoud_right){
						count_right++;
						tmp[central + count_right] = p[j];
						shoud_right = false;
					}
					else{
						count_left--;
						tmp[central + count_left] = p[j];
						shoud_right = true;
					}
					
				}
			}
			for (int j = 0; j < raw[i]; j++){
				if (j != raw[i] - 1) cout << tmp[j].name << " ";
				else cout << tmp[j].name << endl;
			}
		}
	}
	return 0;
}