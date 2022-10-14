#include <iostream>
#include <cstring>

using namespace std;

int dp[1010][1010];

int main() {
    int t, m, c[110], v[110];
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", c + i, v + i);
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= 0; j--) {
            if (j >= c[i])  dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + v[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[m][t];
    return 0;
}