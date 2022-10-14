#include <iostream>
#include <vector>
#include <cstring>

#define maxn 10101
using namespace std;

int n;
vector<int> v[maxn];
int t[maxn];
int res[maxn];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int x;
        scanf("%d%d", &x, t + i);
        while (x > 0){
            scanf("%d", &x);
            v[i].push_back(x);
        }
    }
    memset(res, 0, sizeof(res));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int sz = v[i].size();
        for (int j = 0; j < sz; j++) {
            res[i] = max(res[i], res[v[i][j]] + t[i]);
        }
        ans = max(ans, res[i]);
    }
    printf("%d\n", ans);
}