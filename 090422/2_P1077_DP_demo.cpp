#include <iostream>

using namespace std;

int n, m;
int a[101];
int dp[101][101];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int j = 0; j <= a[1]; j++) dp[1][j] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k <= a[i]; k++) {
                if (k > j) break;
                dp[i][j] += dp[i - 1][j - k];
            }
            dp[i][j] %= 1000007;
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}