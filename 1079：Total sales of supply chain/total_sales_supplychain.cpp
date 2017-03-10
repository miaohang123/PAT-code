#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100050;
int n;
double p, r, res = 0.0;

struct Node{
	double data;
	vector<int> child;
};
Node node[MAXN];

void DFS(int index, int depth){
	if(node[index].child.size() == 0){
		res += p * node[index].data * pow(1+r, depth);
		return;
	}
	for(int i = 0; i < node[index].child.size(); i++){
		DFS(node[index].child[i], depth + 1);
	}
}

int main(){
	int k;
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		if(k == 0){
			scanf("%lf", &node[i].data);
		}else{
			int child; 
			for(int j = 0; j < k; j++){
				scanf("%d", &child);
				node[i].child.push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.1f\n", res);	
	return 0;
}