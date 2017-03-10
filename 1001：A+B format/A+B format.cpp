#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main(){
	int a, b;
	int sum = 0;
	string res = "";
	while(scanf("%d %d", &a, &b) != EOF){
		res = "";
		sum = a + b;
		if(sum < 0){
			cout << "-";
			sum = -sum;
		}
		do{
			res = res + (char)(sum % 10 + '0');
			sum /= 10;
		}while(sum != 0);
		int len = res.length();
		if(len <= 3){
			for(int i = len - 1; i >= 0; i--){
				if(i != 0) cout << res[i];
				else cout << res[i] << endl;
			}
		}else if(len > 3 && len <= 6){
			for(int i = len - 1; i >= 0; i--){
				if(i == 0) cout << res[i] << endl;
				else{
					if(i == 3) cout << res[i] << ",";
					else cout << res[i];
				}
			}
		}else{
			for(int i = len - 1; i >= 0; i--){
				if(i == 0) cout << res[i] << endl;
				else{
					if(i == 6 || i == 3) cout << res[i] << ",";
					else cout << res[i];
				}
			}
		}
	}
	return 0;
}