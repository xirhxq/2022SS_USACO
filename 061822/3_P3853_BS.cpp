#include<iostream>
using namespace std;

int L, n, k;
int d[101010];

bool judge(int x){
	int res = 0;
	for (int i = 2; i <= n; i++){
		if (d[i] - d[i - 1] > x){
			res += (d[i] - d[i-1] -1) / x;
		}
	}
	return res <= k;
}

int main(){
	scanf("%d%d%d", &L, &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", d + i);
	
	int l = 0, r = L, mid;
	while (l < r){
		mid = (l + r) / 2;
		if (judge(mid)){
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	printf("%d", r);
	return 0;
}