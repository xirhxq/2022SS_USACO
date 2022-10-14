#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
char s[505050];
int a[505050];
int cnt;
ll res;
	
int main(){
	scanf("%d", &n);
	scanf("%s", s);
	
	cnt = 0;
	for (int i = 0; i < n; i++){
		if (i == 0 || s[i] != s[i - 1]) cnt++;
		a[cnt]++;
	}
	
	res = 0;
	for (int i = 1; i < cnt; i++){
		res += max(0, a[i] - 1);
	}
	for (int i = 2; i <= cnt; i++){
		res += max(0, a[i] - 1);
	}
	for (int i = 2; i < cnt; i++){
		if (a[i] == 1) res += 1ll * a[i - 1] * a[i + 1];
	}
	printf("%lld\n", res);
	return 0;
}
