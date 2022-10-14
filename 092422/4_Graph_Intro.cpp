#include <iostream>
#include <vector>
#include <cstring>
#define maxn 101010

using namespace std;

int n, m;
vector<int> v[maxn];

bool vis[maxn];

void dfs(int x){
    if (vis[x]) return;
    vis[x] = true;

}

int main(){
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
    }

    memset(vis, 0, sizeof(vis));


}