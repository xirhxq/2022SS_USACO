#include<iostream>

using namespace std;

int dp[30010];

int main() {
    int t, m, c[110], v[110];
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", c + i, v + i);
        v[i] *= c[i];
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= c[i]; j--) {
            dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
        }
    }
    int mx = 0;
    for (int j = t; j >= 0; j--) mx = max(mx, dp[j]);
    cout << mx;
    return 0;
}