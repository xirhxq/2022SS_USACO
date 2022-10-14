#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
    int n, a[1024], dp[1024] = {}, dp2[1024] = {};
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
        dp2[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] >= a[i]) {
                continue;
            }
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            if (a[j] >= a[i]) {
                continue;
            }
            dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dp[i] + dp2[i] - 1);
    }
    cout << n - mx;
    return 0;
}