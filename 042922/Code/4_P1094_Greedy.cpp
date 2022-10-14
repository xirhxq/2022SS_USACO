#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int w, n, a[32768], ans = 0;
	cin >> w >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort (a,a+n);
	
	int l = 0, r = n - 1;
	while (l <= r){
		if (a[l] + a[r] <= w){
			ans++;
			l++, r--;
		}
		else{
			ans++;
			r--;
		}
	}
	cout << ans;
	return 0;
} 

