#include<cstdio>
#include<queue>
#define ONLINE_JUDGE

using namespace std;
int n, a[100005], ans, in[100005];
queue<int> q;

int main() {
#ifdef ONLINE_JUDGE
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        in[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        in[a[now]]--;
        if (!in[a[now]]) {
            q.push(a[now]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in[i]) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}