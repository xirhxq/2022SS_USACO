#include <iostream>
#include <cstring>
#include <vector>
#define maxn 5010
#define mod 80112002
typedef long long ll;
using namespace std;

int n, m;
vector<int> v[maxn];
ll cnt[maxn];
int indeg[maxn];

ll dfs(int x){
    if (v[x].size() == 0){
        return 1ll;
    }
    if (cnt[x] > 0){
        return cnt[x];
    }
    int sz = v[x].size();
    ll res = 0;
    for (int i = 0; i < sz; i++){
        res = (res + dfs(v[x][i])) % mod;
    }
    cnt[x] = res;
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    memset(indeg, 0, sizeof(indeg));
    for (int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        indeg[y]++;
    }
    memset(cnt, 0, sizeof(cnt));
    ll res = 0;
    for (int i = 1; i <= n; i++){
        if (indeg[i] > 0) continue;
        res += dfs(i);
        res %= mod;
    }
    printf("%lld\n", res);
}