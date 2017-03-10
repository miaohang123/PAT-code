#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100040;
struct Node{
	int address;
	int data;
	int next;
	int index;
};
Node node[MAXN];
bool cmp(Node a, Node b){
	return a.index < b.index;
}
int main(){
	for(int i = 0; i < MAXN; i++){
		node[i].index = MAXN;
	}
	int start, n, k;
	scanf("%d %d %d", &start, &n, &k);
	for(int i = 0; i < n; i++){
		int address, data, next;
		scanf("%d %d %d", &address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}
	int count = 0;
	int p;
	for(p = start; p != -1; p = node[p].next){
		node[p].index = count++;
	}
	sort(node, node + MAXN, cmp);
	n = count;
	for(int i = 0; i < n / k; i++){
		for(int j = (i + 1) * k - 1; j > i * k; j--){
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
		}
		printf("%05d %d ", node[i * k].address, node[i * k].data);
		if(i < n / k - 1){           //不是最后一块
			printf("%05d\n", node[(i + 2) * k - 1].address);
		}else{                       //最后一块
			if(n % k == 0){
				printf("-1\n");
			}else{
				printf("%05d\n", node[(i + 1) * k].address);
				for(int i = n / k * k; i < n; i++){
					printf("%05d %d ", node[i].address, node[i].data);
					if(i != n - 1){
						printf("%5d\n", node[i + 1].address);
					}else{
						printf("-1\n");
					}
				}
			}
		}
	}
	return 0;
}