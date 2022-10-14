#include<iostream>
using namespace std;

int L, n, m;
int d[50505];

int judge(int x){
	int res = 0;
	int now = 0;
	for (int i = 1; i <= n + 1; i++){
		if (d[i] - now < x) {
			res++;
			continue;
		}
		now = d[i];
	}
	return res;
}

int main(){
	scanf("%d %d %d", &L, &n, &m);
	d[0] = 0; d[n + 1] = L;
	for (int i = 1; i <= n; i++) scanf("%d", d + i);
	int l = 0, r = L + 1, mid;
	while (l < r){
		mid = (l + r) / 2;
		if (judge(mid) <= m){
			l = mid + 1;
		}
		else r = mid;
	}
	printf("%d\n", l - 1);
	return 0;
}

