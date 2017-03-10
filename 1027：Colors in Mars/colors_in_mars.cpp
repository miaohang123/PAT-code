#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <string>
using namespace std;

char toThirChar(int thirValue){
	if(thirValue >= 0 && thirValue <= 9){
		return (char)(thirValue + '0');
	}else{
		return (char)(thirValue - 10 + 'A');
	}
}

string decTOThir(int decimal){
	string res = "";
	do{
		int thirValue = decimal % 13;
		res = toThirChar(thirValue) + res;
		decimal /= 13;
	}while(decimal != 0);
	if(res.length() == 1) res = "0" + res;
	return res;
}



int main(){
	int r, g, b;
	cin >> r >> g >> b;
	cout << "#" << decTOThir(r) << decTOThir(g) << decTOThir(b) << endl;
	return 0;
}