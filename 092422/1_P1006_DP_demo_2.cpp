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
    // F[i][j][k][l]
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k < i; k++){
                int l = i + j - k;
                int mx = -1;
                mx = max(mx, F[i - 1][j][k - 1][l]);
                mx = max(mx, F[i - 1][j][k][l - 1]);
                mx = max(mx, F[i][j - 1][k - 1][l]);
                mx = max(mx, F[i][j - 1][k][l - 1]);
                if (mx == -1) continue;
                F[i][j][k][l] = mx + a[i][j] + a[k][l];
            }
        }
    }
    printf("%d", F[m][n - 1][m - 1][n]);
    return 0;
}