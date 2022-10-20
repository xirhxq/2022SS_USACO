#include <iostream>
#include <cstring>
#include <vector>
#define maxn 1510
typedef long long ll;

using namespace std;

int m, n, s, u, v;
ll w;

ll d[maxn][maxn];

int main(){
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            d[i][j] = (1 << 31) - 1;
        }
    }
    while (m--){
        scanf("%d%d%lld", &u, &v, &w);
        d[u][v] = min(d[u][v], w);
    }
    for (int i = 1; i <= n; i++){
        d[i][i] = 0;
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        printf("%lld%c", d[s][i], " \n"[i == n]);
    }
    return 0;
}