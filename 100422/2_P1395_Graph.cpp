#include <iostream>
#include <cstring>
#include <vector>
#define maxn 50505

using namespace std;

int n, a, b;
vector<int> v[maxn];

int size[maxn], dis[maxn], dep[maxn];
bool vis[maxn];

void dfs_size(int x){
    int res = 1;
    vis[x] = true;
    dis[1] += dep[x];
    int sz = v[x].size();
    for (int i = 0; i < sz; i++){
        if (vis[v[x][i]]) continue;
        dep[v[x][i]] = dep[x] + 1;
        dfs_size(v[x][i]);
        res += size[v[x][i]];
    }
    size[x] = res;
//    printf("size[%d(%d)] = %d\n", x, dep[x], res);
}

void dfs_dis(int x){
//    printf("@ %d\n", x);
    vis[x] = true;
    int sz = v[x].size();
    for (int i = 0; i < sz; i++){
        int y = v[x][i];
        if (vis[y]) continue;
        dis[y] = dis[x] + (n - size[y]) - size[y];
//        printf("dis[%d] = %d\n", y, dis[y]);
        dfs_dis(y);
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i < n; i++){
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis));
    dep[1] = 0;
    dis[1] = 0;
    dfs_size(1);
//    printf("dis 1 = %d\n", dis[1]);
    memset(vis, 0, sizeof(vis));
    dfs_dis(1);
    int min_dis = -1, min_index;
    for (int i = 1; i <= n; i++){
        if (min_dis == -1 || min_dis > dis[i]){
            min_dis = dis[i];
            min_index = i;
        }
    }
    printf("%d %d\n", min_index, min_dis);
}