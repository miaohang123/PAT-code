#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 1001;
int Tree[MAXN];
int hobby[MAXN] = {0};
int isRoot[MAXN];

int findRoot(int x){
	if(Tree[x] == -1) return x;
	else{
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}
void Union(int a, int b){
	a = findRoot(a);
	b = findRoot(b);
	if(a != b){
		Tree[a] = b;
	}
}
bool cmp(int x, int y){
	return x > y;
}
int main(){
	int n, k;
	while(cin >>n){
		for(int i = 1; i <= n; i++){
			Tree[i] = -1;
			isRoot[i] = 0;
		}
		for(int i = 1; i <= n; i++){
			scanf("%d:", &k);
			for(int j = 0; j < k; j++){
				int h;
				cin >>h;
				if(!hobby[h]) hobby[h] = i;
				Union(i, findRoot(hobby[h]));
			}
		}
		for(int i = 1; i <= n; i++){
			isRoot[findRoot(i)]++;
		}
		int res = 0;
		for(int i = 1; i <= n; i++){
			if(isRoot[i] != 0) res++;
		}
		sort(isRoot + 1, isRoot + n, cmp);
		cout <<res <<endl;
		for(int i = 1; i < res; i++){
			cout <<isRoot[i] <<" ";
		}	
		cout <<isRoot[res] <<endl;
	}
	return 0;
}