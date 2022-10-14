#include <iostream>
using namespace std;
#define maxn 2010

int t, k, n, m;
int c[maxn][maxn], ans[maxn][maxn];
// c[i][j] == iCj % k
// ans[i][j] == (n=i, m=j) -> ans

void prepare(){
    for (int i = 0; i <= 2000; i++){
        for (int j = 0; j <= i; j++){
            if (i == 0 || j == 0 || j == i) c[i][j] = 1;
            else {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k;
            }
            if (i == 0 && j == 0) ans[i][j] = (c[i][j] == 0);
            else if (i == 0) ans[i][j] = ans[i][j - 1] + (c[i][j] == 0);
            else if (j == 0) ans[i][j] = ans[i - 1][j] + (c[i][j] == 0);
            else if (i == j) ans[i][j] = ans[i][j - 1] + (c[i][j] == 0);
            else {
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + (c[i][j] == 0);
            }
//            if (i <= 5) printf("%d(%d)%c", c[i][j], ans[i][j], " \n"[i == j]);
        }
    }
}

int main(){
    scanf("%d %d", &t, &k);
    prepare();
    for (int i = 1; i <= t; i++){
        scanf("%d %d", &n, &m);
        printf("%d\n", ans[n][min(m, n)]);
    }
}