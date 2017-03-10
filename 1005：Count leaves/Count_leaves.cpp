#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 105;
int digit[20];
char num[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
	string s;
	while(cin >>s){
		int sum = 0;
		int numSize = 0;
		for(int i = 0; i < s.size(); i++){
			sum += s[i] - '0';
		}
		if(sum == 0){
			cout <<num[0] <<endl;
		}
		else{
			while(sum != 0){
				digit[numSize++] = sum % 10;
				sum /= 10;
			}
			for(int i = numSize - 1; i >= 0; i--){
				cout <<num[digit[i]];
				if(i != 0) cout <<" ";
			}
			cout <<endl;
		}
	}
	return 0;
}