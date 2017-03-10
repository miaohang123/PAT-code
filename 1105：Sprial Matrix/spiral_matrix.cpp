#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
int num[MAXN];
int mat[MAXN][MAXN];

bool cmp(int a, int b){
	return a > b;
}
int main(){
	int len;
	while(cin >>len){
		for(int i = 0; i < len; i++){
			cin >>num[i];
		}
		if(len == 1){
			cout <<num[0] <<endl;
			return 0;
		}
		sort(num, num + len, cmp);
		int m = (int)ceil(sqrt(1.0 * len));
		while(len % m != 0){
			m++;
		}
		int n = len / m;
		//cout <<"m:" <<m <<"n: " <<n <<endl;
		int U = 1, L = 1, D = m, R = n;
		int i = 1, j = 1;
		int now = 0;
		while(now < len){
			while(now < len && j < R){
				mat[i][j] = num[now++]; 
				j++;
			}
			while(now < len && i < D){
				mat[i][j] = num[now++];
				i++;
			}
			while(now < len && j > L){
				mat[i][j] = num[now++];
				j--;
			}
			while(now < len && i > U){
				mat[i][j] = num[now++];
				i--;
			}
			U++, D--, L++, R--;
			i++, j++;
			if(now == len - 1){
				mat[i][j] = num[now++];
			}
		}
		for(int i = 1; i <= m; i++){
			for(int j = 1; j < n; j++){
				cout <<mat[i][j] <<" ";
			}
			cout <<mat[i][n] <<endl;
		}
	}
	return 0;
}