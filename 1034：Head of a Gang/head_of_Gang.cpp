#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
const int MAXN = 2002;
map<string, int> Gang;
map<string, int> stringToInt; //姓名到编号
map<int, string> intToString; //编号到姓名

int G[MAXN][MAXN] = {0};      //邻接矩阵
int weight[MAXN] = {0};       //点权
bool mark[MAXN] = {false};

int n, k, totalNum = 0;

void DFS(int now, int& head, int& memNum, int& totalValue){
	memNum++;
	mark[now] = true;
	if(weight[now] > weight[head]){
		head = now;
	}
	for(int i = 0; i < totalNum; i++){
		if(G[now][i] > 0){
			totalValue += G[now][i];
			G[now][i] = G[i][now] = 0;
			if(mark[i] == false){
				DFS(i, head, memNum, totalValue);
			}
		}
	}
}

void DFSTrave(){
	for(int i = 0; i < totalNum; i++){
		if(mark[i] == false){
			int head = i, memNum = 0, totalValue = 0;
			DFS(i, head, memNum, totalValue);
			if(memNum > 2 && totalValue > k){
				Gang[intToString[head]] = memNum;
			}
		}
	}
}

int toId(string str){
	if(stringToInt.find(str) != stringToInt.end()){
		return stringToInt[str];
	}else{
		stringToInt[str] = totalNum;
		intToString[totalNum] = str;
		return totalNum++;
	}
}

int main(){
	int w;
	string name1, name2;
	while(cin >> n >> k){
		stringToInt.clear();
		intToString.clear();
		Gang.clear();
		for(int i = 0; i < n; i++){
			cin >> name1 >> name2 >> w;
			int id1 = toId(name1);
			int id2 = toId(name2);
			weight[id1] += w;
			weight[id2] += w;
			G[id1][id2] += w;
			G[id2][id1] += w;
		}
		DFSTrave();
		cout << Gang.size() << endl;
		for(map<string, int>::iterator it = Gang.begin(); it != Gang.end(); it++){
			cout << it->first << " " << it->second << endl;
		}
	}
	return 0; 
}