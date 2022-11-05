#include <iostream>
#include <cstring>
#include <vector>
#define maxn 101010
typedef long long ll;

using namespace std;

int m, n, s, u, v;
ll w;

vector<pair<ll, int> > e[maxn];
bool vis[maxn];

ll dis[maxn];

int main(){
    scanf("%d%d%d", &n, &m, &s);
    while (m--) {
        scanf("%d%d%lld", &u, &v, &w);
//        e[u].push_back(make_pair(w, v));
        e[u].push_back({w, v});
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++){
        dis[i] = (1 << 31) - 1;
    }
    dis[s] = 0;
    while (true){
        int t = -1;
        for (int i = 1; i <= n; i++){
            if (vis[i]) continue;
            if (t == -1 || dis[i] < dis[t]){
                t = i;
            }
        }
//        printf("t = %d\n", t);
        if (t == -1) {
            break;
        }
        vis[t] = true;
        for (auto i: e[t]){
            ll d = i.first;
            int y = i.second;
            if (vis[y]) continue;
            dis[y] = min(dis[y], dis[t] + d);
        }


//        int sz = e[t].size();
//        for (int i = 0; i < sz; i++){
//            ll d = e[t][i].first;
//            int y = e[t][i].second;
//            if (vis[y]) continue;
//            printf("dis[%d] = %lld or %lld + %lld\n", y, dis[y], dis[t], d);
//            dis[y] = min(dis[y], dis[t] + d);
//        }
    }
    for (int i = 1; i <= n; i++){
        printf("%lld ", dis[i]);
    }
    return 0;
}