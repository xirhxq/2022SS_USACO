#include <iostream>
#include <vector>
#include <cstring>
#define mod 80112002
#define maxn 5010
using namespace std;

int n, m, a, b;
vector<int> v[maxn];
int indeg[maxn]; //入度
int res[maxn]; // 每个点到任意一个终点的路径数量

void dfs(int x){
//    printf("DFS %d\n", x);
    // x -> 1 2 3 4
    // res[x] = res[1] + res[2] + res[3] + res[4]
    if (res[x] > 0){
        return;
    }
    int sz = v[x].size();
    if (sz == 0){
        res[x] = 1;
    }
    for (int i = 0; i < sz; i++){
        int y = v[x][i];
//        printf("%d -> %d\n", x, y);
        dfs(y);
        res[x] += res[y];
        res[x] %= mod;
    }
//    printf("res[%d] = %d\n", x, res[x]);
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        indeg[b]++;
    }
    memset(res, 0, sizeof(res));
    for (int i = 1; i <= n; i++){
        if (indeg[i] == 0){
            dfs(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (indeg[i] == 0){
            ans += res[i];
            ans %= mod;
        }
    }
    printf("%d\n", ans);
}