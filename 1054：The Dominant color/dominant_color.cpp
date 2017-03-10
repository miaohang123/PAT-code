#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <string>
using namespace std;
map<int, int> count;

int main(){
	int n, m;
	while(cin >> m >> n){
		count.clear();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int d;
				scanf("%d", &d);
				if(count.find(d) == count.end()){
					count[d] = 1;
				}else{
					count[d]++;
				}
			}
		}
		int maxcount = -1, res;
		for(map<int, int>::iterator it = count.begin(); it != count.end(); it++){
			if(it->second > maxcount){
				maxcount = it->second;
				res = it->first;
			}
		}
		cout << res << endl;
	}
	return 0;
}