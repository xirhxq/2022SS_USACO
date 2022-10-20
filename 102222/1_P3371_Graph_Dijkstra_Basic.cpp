#include <iostream>
#include <cstring>
#include <vector>
#define maxn 10101

using namespace std;

int m, n, s, u, v, w;

int d[maxn][maxn];
int dis[maxn];
bool vis[maxn];

int main(){
    scanf("%d%d%d", &n, &m, &s);
    memset(d, 0x3f, sizeof(d));
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    while (m--){
        scanf("%d%d%d", &u, &v, &w);
        d[u][v] = min(d[u][v], w);
    }
    dis[s] = 0;

    while (true){
        int t = -1;
        for (int i = 1; i <= n; i++){
            if (vis[i]) continue;
            if (dis[i] < dis[t] || t == -1) {
                t = i;
            }
        }
//        printf("t = %d\n", t);
        vis[t] = true;
        if (t == -1){
            break;
        }
        for (int i = 1; i <= n; i++){
//            printf("dis[%d] = %d compare with %d + %d\n", i, dis[i], dis[t], d[t][i]);
            dis[i] = min(dis[i], dis[t] + d[t][i]);
        }
    }


    for (int i = 1; i <= n; i++){
        printf("%d%c", dis[i], " \n"[i == n]);
    }
    return 0;
}