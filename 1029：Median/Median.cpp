#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1000002;
long list[N + N];

void merge(long list1[], long list2[], int len1, int len2){
	long len = len1 + len2;
	long i, j, k;
	for (i = 0, j = 0, k = i; i < len1 && j < len2; k++){
		if (list1[i] < list2[j]){
			list[k] = list1[i++];
		}
		else{
			list[k] = list2[j++];
		}
	}
	while (i < len1) list[k++] = list1[i++];
	while (j < len2) list[k++] = list2[j++];
}

int main(){
	int n1, n2;
	memset(list, 0, sizeof(list));
	long list1[N], list2[N];
	cin >> n1;
	for (int i = 0; i < n1; i++){
		cin >> list1[i];
	}
	cin >> n2;
	for (int i = 0; i < n2; i++){
		cin >> list2[i];
	}
	int len = n1 + n2;
	merge(list1, list2, n1, n2);
	if (!(len % 2)){
		cout << list[(len / 2) - 1]<< endl;
	}
	else{
		cout << list[(len - 1) / 2] << endl;
	}
	return 0;
}
