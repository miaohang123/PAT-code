#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 502;

int main(){
	int n;
	while(cin >>n){
		int currentFloor = 0, total = 0;
		for(int i = 0; i < n; i++){
			int floor;
			cin >>floor;
			if(floor > currentFloor){
				total += 6 * (floor - currentFloor);
			}else{
				total += 4 * (currentFloor - floor);
			}
			total += 5;
			currentFloor = floor;
		}
		cout <<total <<endl; 
	}
	return 0;
}