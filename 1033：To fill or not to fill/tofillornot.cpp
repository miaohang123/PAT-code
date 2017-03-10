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
const int MAXN = 510;
struct Station{
	double distance;
	double price;
};
Station station[MAXN];
bool cmp(Station a, Station b){
	return a.distance < b.distance;
}

int main(){
	double cmax, d, d_avg;
	int n;
	while(scanf("%lf %lf %lf %d", &cmax, &d, &d_avg, &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%lf %lf", &station[i].price, &station[i].distance);
		}
		station[n].price = 0;
		station[n].distance = d;
		sort(station, station + n, cmp);
		if(station[0].distance != 0) printf("The maximum travel distance = 0.00\n");
		else{
			int now = 0;
			double res = 0, nowTank = 0, max_dis = cmax * d_avg;
			while(now < n){
				int index = -1;
				double min_price = 123123123;
				for(int i = now + 1; i <= n && station[i].distance - station[now].distance <= max_dis; i++){
					if(station[i].price < min_price){
						min_price = station[i].price;
						index = i;
						if(min_price < station[now].price){  //find the first station whose price is lower than now
							break;
						}
					}
				}
				if(index == -1) break;   //can not reach any station even though the tank is full
				double needTank = (station[index].distance - station[now].distance) / d_avg;
				if(min_price < station[now].price){
					if(nowTank < needTank){
						res += (needTank - nowTank) * station[now].price;
						nowTank = 0;
					}else{
						nowTank -= needTank;
					}
				}else{
					res += (cmax - nowTank) * station[now].price;
					nowTank = cmax - needTank; 
				}
				now = index;
			}
			if(now == n){
				printf("%.2f\n", res);
			}else{
				printf("The maximum travel distance = %.2f\n", station[now].distance + max_dis);
			}
		}
	}
	return 0;
}