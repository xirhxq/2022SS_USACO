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

void dfs(int x){
    printf("%d ", x);
    vis[x] = true;
    int sz = v[x].size();
    for (int i = 0; i < sz; i++){
        if (vis[v[x][i]]) continue;
        dfs(v[x][i]);
    }
}

void bfs(){
    vis[1] = true;
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int x = q.front();
        printf("%d ", x);
        q.pop();
        int sz = v[x].size();
        for (int i = 0; i < sz; i++){
            if (vis[v[x][i]]) continue;
            vis[v[x][i]] = true;
            q.push(v[x][i]);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
    }
    for (int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }
    memset(vis, 0, sizeof(vis));
    dfs(1);printf("\n");
    memset(vis, 0, sizeof(vis));
    bfs();printf("\n");
}