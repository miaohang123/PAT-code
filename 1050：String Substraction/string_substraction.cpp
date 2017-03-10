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
bool hashTable[MAXN] = {false};


int main(){
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int len1 = str1.length();
	int len2 = str2.length();
	for(int i = 0; i < len1; i++){
		char c = str1[i];
		hashTable[c] = true;
	}
	for(int i = 0; i < len2; i++){
		char c = str2[i];
		hashTable[c] = false;
	}
	for(int i = 0; i < len1; i++){
		char c = str1[i];
		if(hashTable[c] == true){
			printf("%c", c);
		}
	}
	return 0;
}