#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 502;
struct Person
{
	char id[16];
	int sign_in_hour, sign_in_min, sign_in_second;
	int sign_out_hour, sign_out_min, sign_out_second;
};
Person p[MAXN];

bool cmp_in(Person A, Person B){
	if(A.sign_in_hour != B.sign_in_hour){
		return A.sign_in_hour < B.sign_in_hour;
	}else if(A.sign_in_min != B.sign_in_min){
		return A.sign_in_min < B.sign_in_min;
	}else{
		return A.sign_in_second < B.sign_in_second;
	}
}

bool cmp_out(Person A, Person B){
	if(A.sign_out_hour != B.sign_out_hour){
		return A.sign_out_hour > B.sign_out_hour;
	}else if(A.sign_out_min != B.sign_out_min){
		return A.sign_out_min > B.sign_out_min;
	}else{
		return A.sign_out_second > B.sign_out_second;
	}
}

int main(){
	int n;
	while(cin >>n){
		for(int i = 0; i < n; i++){
			scanf("%s %d:%d:%d %d:%d:%d", p[i].id, &p[i].sign_in_hour, &p[i].sign_in_min, &p[i].sign_in_second, 
				&p[i].sign_out_hour, &p[i].sign_out_min, &p[i].sign_out_second);
		}
		sort(p, p + n, cmp_in);
		cout <<p[0].id <<" ";
		sort(p, p + n, cmp_out);
		cout <<p[0].id <<endl;
	}
	return 0;
}