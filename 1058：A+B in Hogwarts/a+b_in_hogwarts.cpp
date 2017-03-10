#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <string>
using namespace std;

int main(){
	int g1, s1, k1;
	int g2, s2, k2;
	int g, s, k;
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	k = k1 + k2;
	int k_r = k % 29;
	int k_c = k / 29;
	s = s1 + s2 + k_c;
	int s_r = s % 17;
	int s_c = s / 17;
	g = g1 + g2 + s_c;
	cout << g << "." << s_r << "." << k_r << endl;
	return 0;
}