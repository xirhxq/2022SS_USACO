#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define maxn 101010
using namespace std;

int m, n;
vector<int> v[maxn];
bool vis[maxn];
int ans[maxn];

void dfs(int x, int start){
    vis[x] = true;
    int sz = v[x].size();
    for (int i = 0; i < sz; i++){
        if (ans[v[x][i]] > start) continue;
        if (vis[v[x][i]]) continue;
        ans[v[x][i]] = start;
        dfs(v[x][i], start);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        v[y].push_back(x);
    }
    for (int i = n; i >= 1; i--){
        ans[i] = i;
    }
    for (int i = n; i >= 1; i--){
        memset(vis, 0, sizeof(vis));
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++){
        printf("%d%c", ans[i], " \n"[i == n]);
    }
}