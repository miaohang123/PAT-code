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
const int MAXN = 100010;
vector<int> coupon;
vector<int> product;

int main(){
	int nc, np;
	int num;
	while(scanf("%d", &nc) != EOF){
		coupon.clear();
		product.clear();
		int cou_pos = 0, cou_neg = 0, pro_pos = 0, pro_neg = 0;
		for(int i = 0; i < nc; i++){
			scanf("%d", &num);
			if(num != 0){
				coupon.push_back(num);
				if(num > 0) cou_pos++;
				else cou_neg++;
			}
		}
		scanf("%d", &np);
		for(int i = 0; i < np; i++){
			scanf("%d", &num);
			if(num != 0) {
				product.push_back(num);
				if(num > 0) pro_pos++;
				else pro_neg++;
			}
		}
		sort(coupon.begin(), coupon.end());
		sort(product.begin(), product.end());
		int pos = min(cou_pos, pro_pos);
		int neg = min(cou_neg, pro_neg);
		int res = 0;
		for(int i = 0; i < neg; i++){
			res += coupon[i] * product[i];
		}
		for(int i = coupon.size() - 1, j = product.size() - 1; i >= coupon.size() - pos, j >= product.size() - pos; i--, j--){
			res += coupon[i] * product[j];
		}
		printf("%d\n", res);
	}
	return 0;
}