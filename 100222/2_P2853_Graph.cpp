#include <iostream>
#include <vector>
#include <cstring>
#define maxn 1010
using namespace std;

int k, m, n;
int cow[maxn];
vector<int> v[maxn];
bool vis[maxn];
int cnt[maxn];

void dfs(int x){
    vis[x] = true;
    cnt[x]++;
    int sz = v[x].size();
    for (int i = 0; i < sz; i++){
        if (vis[v[x][i]]) continue;
        dfs(v[x][i]);
    }
}

int main(){
    scanf("%d%d%d", &k, &n, &m);
    for (int i = 1; i <= k; i++) {
        scanf("%d", cow + i);
    }
    for (int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= k; i++){
        memset(vis, 0, sizeof(vis));
        dfs(cow[i]);
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        if (cnt[i] == k) {
            res++;
        }
    }
    printf("%d\n", res);
}