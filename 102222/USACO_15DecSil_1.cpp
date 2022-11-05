#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#define maxn 110

using namespace std;

int n, m, x, y, a, b;
queue<pair<int, int> > q;
map<pair<int, int>, vector<pair<int, int> > > mp;
int res;

map<pair<int, int>, bool> vis, lit;
//bool vis[maxn][maxn], lit[maxn][maxn];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

bool valid(pair<int, int> p){
    if (p.first < 1 || p.second > n) return false;
    if (p.second < 1 || p.second > n) return false;
    return true;
}

int main(){
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--){
        scanf("%d%d%d%d", &x, &y, &a, &b);
        mp[{x, y}].push_back({a, b});
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            vis[{i, j}] = lit[{i, j}] = false;
        }
    }
    q.push({1, 1});
    lit[{1, 1}] = vis[{1, 1}] = true;
    res = 1;


    while (!q.empty()){
        auto now = q.front();
//        printf("vis %d %d\n", now.first, now.second);
        q.pop();

        for (auto a: mp[now]){
            if (vis[a] && !lit[a]){
                q.push(a);
//                printf("push %d %d\n", a.first, a.second);
            }
            if (!lit[a]){
                lit[a] = true;
                res++;
//                printf("lit %d %d\n", a.first, a.second);
            }
        }

        auto go = now;
        for (int i = 0; i < 4; i++){
            go.first = now.first + dx[i];
            go.second = now.second + dy[i];
            if (!valid(go)) continue;
            if (!vis[go] && lit[go]){
                q.push(go);
//                printf("push %d %d\n", go.first, go.second);
            }
            vis[go] = true;
//            printf("can go to %d %d\n", go.first, go.second);
        }
    }

    printf("%d\n", res);

    return 0;
}