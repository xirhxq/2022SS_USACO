#include<iostream>
using namespace std;

int main(){
	int n, a[101];
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	int ans = 0;
	for (int i = 1; i <= n; i++) if (i == 1 || a[i] != a[i - 1]) ans++;
	cout << ans << endl;
	for (int i = 1; i <= n; i++) if (i == 1 || a[i] != a[i - 1]) cout << a[i] << " "; 
	return 0;
}

