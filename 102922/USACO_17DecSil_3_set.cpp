#include <iostream>
#include <set>
#define maxn 101010
#define ONLINE_JUDGE
using namespace std;

int n, a[maxn];
bool vis[maxn];

set<int> s, ring, no_ring;

int main(){
#ifdef ONLINE_JUDGE
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++){
        if (ring.find(i) != ring.end() || vis[i]) {
            continue;
        }
        int now = i;
        s.clear();
        bool flag = false;
        while (s.find(now) == s.end()){
            if (no_ring.find(now) != no_ring.end() || ring.find(now) != ring.end()){
                flag = true;
                break;
            }
            s.insert(now);
            vis[now] = true;
            now = a[now];
        }
        if (flag) {
            continue;
        }
        while (ring.find(now) == ring.end()){
            ring.insert(now);
            now = a[now];
        }
        now = i;
        while (ring.find(now) == ring.end()){
            no_ring.insert(now);
            now = a[now];
        }
    }
    printf("%ld\n", ring.size());
}