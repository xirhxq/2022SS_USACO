#include<iostream>

using namespace std;

long long dp[30][30];
int m, n, a, b;

int main() {
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) dp[i][j] = 1;
            else dp[i][j] = 0;
            if (abs(i - a) == 1 && abs(j - b) == 2) continue;
            if (abs(i - a) == 2 && abs(j - b) == 1) continue;
            if (i == a && j == b) continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    printf("%lld\n", dp[n][m]);
    return 0;
}