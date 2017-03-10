#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int num){
	if(num <= 1) return false;
	int temp = (int)sqrt(num * 1.0) + 1;
	for(int i = 2; i <= temp; i++){
		if(num % i == 0){
			return false;
		}
	}
	return true;
}
int a[100];

int main(){
	int n, d;
	while(cin >> n && n >= 0){
		cin >> d;
		if(!isPrime(n)){
			cout << "No" << endl;
		}else{
			int size = 0;
			do{
				a[size++] = n % d;
				n /= d;
			}while(n != 0);
			for(int i = 0; i < size; i++){
				n = n * d + a[i];
			}
			if(isPrime(n)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}