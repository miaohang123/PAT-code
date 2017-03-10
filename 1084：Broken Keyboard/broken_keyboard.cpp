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
const int MAXN = 128;
bool hashTable[MAXN] = {0};

int main(){
	string str1, str2;
	while(cin >> str1 >> str2){
		int len1 = str1.length();
		int len2 = str2.length();
		char c1, c2;
		for(int i = 0; i < len1; i++){
			c1 = str1[i];
			if(c1 >= 'a' && c1 <= 'z') c1 -= 32;
			int j;
			for(j = 0; j < len2; j++){
				c2 = str2[j];
				if(c2 >= 'a' && c2 <= 'z') c2 -= 32;
				if(c1 == c2) break;
			}
			if(j == len2 && hashTable[c1] == false){
				cout << c1;
				hashTable[c1] = true;
			}
		}
		cout << endl;
	}
	return 0;
}