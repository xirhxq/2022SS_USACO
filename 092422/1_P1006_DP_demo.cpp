#include<iostream>
#include <cstring>

using namespace std;
const int maxn = 60;
int a[maxn][maxn];
int F[maxn][maxn][maxn][maxn];

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    memset(F, -1, sizeof(F));
    F[1][1][1][1] = 0;
    for (int k = 3; k < m + n; k++) {
        for (int i = max(1, k - m); i < k && i <= n; i++) {
            for (int j = i + 1; j <= n && j < k; j++) {
//                printf("i = %d, j = %d, k = %d\n", i, j, k);
                int s = F[k - i][i][k - j][j];
                if (F[k - 1 - i][i][k - 1 - j][j] > s) s = F[k - 1 - i][i][k - 1 - j][j];
                if (F[k - i][i - 1][k - 1 - j][j] > s) s = F[k - i][i - 1][k - 1 - j][j];
                if (F[k - i - 1][i][k - j][j - 1] > s) s = F[k - i - 1][i][k - j][j - 1];
                if (F[k - i][i - 1][k - j][j - 1] > s) s = F[k - i][i - 1][k - j][j - 1];
                if (s == -1) continue;
                F[k - i][i][k - j][j] = s + a[k - i][i] + a[k - j][j];
            }
        }
    }
    printf("%d", F[m][n - 1][m - 1][n]);
    return 0;
}