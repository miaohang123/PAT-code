#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 100040;

int main(){
	string str;
	cin >> str;
	int len = str.size();
	int n1, n2, n3;
	n1 = (len + 2) / 3;
	n3 = n1;
	n2 = len + 2 - n1 - n3;
	for(int i = 0; i < n1 - 1; i++){
		cout << str[i];
		for(int j = 0; j < n2 - 2; j++){
			cout << " ";
		}
		cout << str[len - 1 - i] << endl;
	}
	for(int j = 0; j < n2; j++){
		cout << str[n1 + j - 1];
	}
	cout << endl;
	return 0;
}