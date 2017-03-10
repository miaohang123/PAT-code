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
bool judge(string s, double &x){
	int len = s.length();
	int dot = 0;
	int n1 = 0, n2 = 0;
	int i = 0;
	if(s[i] == '-') i++;
	for(; i < len; i++){
		if(s[i] == '.'){
			dot++;
			if(dot > 1) return false;
		}else if(s[i] >= '0' && s[i] <= '9'){
			if(dot) n2++;
			else n1++;
		}else{
			return false;
		}
	}
	if(n2 > 2) return false;
	sscanf(s.c_str(), "%lf", &x);
	if(x >= -1000 && x <= 1000) return true;
	else return false;
}
int main(){
	int n, count = 0;
	double res = 0;
	string str;
	while(cin >>n){
		for(int i = 0; i < n; i++){
			cin >>str;
			double x;
			if(judge(str, x)){
				count++;
				res += x;
			}else{
				cout <<"ERROR: " <<str <<" is not a legal number" <<endl; 
			}
		}
		if(count == 0){
			cout <<"The average of 0 numbers is Undefined" <<endl;
		}else if(count == 1){
			printf("The average of 1 number is %.2f\n", res);
		}else{
			res = (double)(res / count);
			printf("The average of %d numbers is ", count);
			printf("%.2f\n", res);
		}
	}
	return 0;
}