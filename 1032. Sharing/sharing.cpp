#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 100040;
struct  Node
{
	char data;
	int next;
	bool flag; 
};
Node node[MAXN];

int main(){
	for(int i = 0; i < MAXN; i++){
		node[i].flag = false;
	}
	int start1, start2, n;
	scanf("%d %d %d", &start1, &start2, &n);
	for(int i = 0; i < n; i++){
		int address, data, next;
		scanf("%d %c %d", &address, &data, &next);
		node[address].data = data;
		node[address].next = next;
	}
	int res ;
	for(res = start1; res != -1; res = node[res].next){
		node[res].flag = true;
	}
	for(res = start2; res != -1; res = node[res].next){
		if(node[res].flag == true) break;
	}
	if(res != -1){
		printf("%05d\n", res);
	}else{
		printf("-1\n");
	}
	return 0;
}