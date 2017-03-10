#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
char s[3] = {'W', 'T', 'L'};
double max[3] = {-1.0};
int flag[3] = {-1};

int main(){
	double num;
	double res = 0;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			scanf("%lf", &num);
			if(num > max[i]){
				max[i] = num;
				flag[i] = j;
			}
		}
	}
	res = ((max[0] + max[1] + max[2]) * 0.65 - 1) * 2;
	printf("%c % c % c %.2f\n", flag[0], flag[1], flag[2], res);
	return 0;
}