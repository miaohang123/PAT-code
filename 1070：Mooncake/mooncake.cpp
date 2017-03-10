#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
const int MAXN = 1005;
int n;
double d;
struct Mooncake
{
	double store;
	double totalvalue;
	double price;
};
Mooncake cake[MAXN];

bool cmp(Mooncake a, Mooncake b){
	return a.price > b.price;
}

int main(){
	while(scanf("%d %lf", &n, &d) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%lf", &cake[i].store);
		}
		for(int i = 0; i < n; i++){
			scanf("%lf", &cake[i].totalvalue);
			cake[i].price = cake[i].totalvalue / cake[i].store;
		}
		sort(cake, cake + n, cmp);
		double res = 0.00;
		for(int i = 0; i < n; i++){
			if(cake[i].store <= d){
				d -= cake[i].store;
				res += cake[i].totalvalue;
			}else{
				res += cake[i].price * d;
				break;
			}
		}
		printf("%.2f\n", res);
	}
	return 0;
}