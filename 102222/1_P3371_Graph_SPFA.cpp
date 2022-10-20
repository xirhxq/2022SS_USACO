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

queue<int> q;
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
    q.push(s);
    vis[s] = true;

    while(!q.empty()){
        int t = q.front();
        q.pop();
        vis[t] = false;
        int sz = e[t].size();
        for (int i = 0; i < sz; i++){
            ll d = e[t][i].first;
            int y = e[t][i].second;
            if (dis[y] > dis[t] + d){
                dis[y] = dis[t] + d;
                if (!vis[y]){
                    vis[y] = true;
                    q.push(y);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        printf("%lld ", dis[i]);
    }
    return 0;
}