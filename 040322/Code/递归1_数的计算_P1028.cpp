#include<iostream>
using namespace std;

int f[1010];

int solve(int x){
	if (f[x] > 0) return f[x];
	int ans = 1;
	for(int i = 1; i * 2 <= x; i++){
		ans += solve(i);
	}
	f[x] = ans;
	return ans;
}

int main(){
	int n;
	cin >> n;
	memset(f,0,sizeof(f));
	f[1] = 1;
	cout << solve(n);
	return 0;
}
