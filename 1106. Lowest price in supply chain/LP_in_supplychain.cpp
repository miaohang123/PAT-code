#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
vector<int> Node[MAXN];
int num = 0;
double ans = 123123123;
double r, p;

void DFS(int index, int depth){
	if(Node[index].size() == 0){
		double price = p * pow(1 + r, depth);
		if(price < ans){
			ans = price;
			num = 1;
		}else if(price == ans){
			num++;
		}
		return;
	}
	for(int i = 0; i < Node[index].size(); i++){
		DFS(Node[index][i], depth + 1);
	}
}

int main(){
	int child;
	int n;
	while(cin >> n >> p >> r){
		r /= 100;
		for(int i = 0; i < n; i++){
			int k;
			cin >> k;
			if(k != 0){
				for(int j = 0; j < k; j++){
					cin >> child;
					Node[i].push_back(child);
				}
			}
		}
		DFS(0, 0);
		printf("%.4f %d\n", ans, num);
	}
	return 0;
}