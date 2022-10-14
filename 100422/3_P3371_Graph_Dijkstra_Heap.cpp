#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define maxn 101010
typedef long long ll;

using namespace std;

int m, n, s, u, v;
ll w;

vector<pair<ll, int>> e[maxn];
bool vis[maxn];

priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
ll dis[maxn];

int main(){
    scanf("%d%d%d", &n, &m, &s);
    while (m--) {
        scanf("%d%d%lld", &u, &v, &w);
        e[u].push_back(make_pair(w, v));
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++){
        dis[i] = (1 << 31) - 1;
    }
    dis[s] = 0;
    q.push(make_pair(0ll, s));
    while (!q.empty()){
        int t = q.top().second;
        q.pop();
        if (vis[t]) continue;
        vis[t] = true;
        int sz = e[t].size();
        for (int i = 0; i < sz; i++){
            ll d = e[t][i].first;
            int y = e[t][i].second;
            if (vis[y]) continue;
//            printf("dis[%d] = %lld or %lld + %lld\n", y, dis[y], dis[t], d);
            dis[y] = min(dis[y], dis[t] + d);
            q.push(make_pair(dis[y], y));
        }
    }
    for (int i = 1; i <= n; i++){
        printf("%lld ", dis[i]);
    }
    return 0;
}