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
bool have_ans[maxn];
int ans[maxn];

void dfs(int x, int start){
    vis[x] = true;
    if (have_ans[x]){
        ans[start] = max(ans[start], ans[x]);
        return;
    }
    int sz = v[x].size();
    for (int i = 0; i < sz; i++){
        if (vis[v[x][i]]) continue;
        ans[start] = max(ans[start], v[x][i]);
        dfs(v[x][i], start);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
    }
    for (int i = n; i >= 1; i--){
        ans[i] = i;
    }
    memset(have_ans, 0, sizeof(have_ans));
    for (int i = n; i >= 1; i--){
        memset(vis, 0, sizeof(vis));
        dfs(i, i);
        have_ans[i] = true;
    }
    for (int i = 1; i <= n; i++){
        printf("%d%c", ans[i], " \n"[i == n]);
    }
}