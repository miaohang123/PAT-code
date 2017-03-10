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
	bool flag;
};
Node node[MAXN];
bool cmp(Node a, Node b){
	if(a.flag == false || b.flag == false){
		return a.flag > b.flag;
	}else{
		return a.data < b.data;
	}
}
int main(){
	int n, start;
	for(int i = 0; i < MAXN; i++){
		node[i].flag = false;
	}
	scanf("%d %d", &n, &start);
	for(int i = 0; i < n; i++){
		int address, data, next;
		scanf("%d %d %d", &address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}
	int count = 0;
	int res;
	for(res = start; res != -1; res = node[res].next){
		node[res].flag = true;
		count++;
	}
	if(count == 0){
		printf("0 -1\n");
	}else{
		sort(node, node + MAXN, cmp);
		printf("%d %05d\n", count, node[0].address);
		for(int i = 0; i < count; i++){
			if(i != count - 1){
				printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
			}else{
				printf("%05d %d -1\n", node[i].address, node[i].data);
			}
		}
	}
	return 0;
}