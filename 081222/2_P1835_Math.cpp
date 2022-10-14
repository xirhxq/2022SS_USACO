#include <iostream>

#define M 1010101
#define N 1010101
typedef long long ll;
using namespace std;

bool a[M], ans[M];
ll cnt = 0, pri[N];
ll L, R;

bool prime(int n) {
    for (int i = 2; i <= n; ++i)
        if (!a[i]) {
            pri[++cnt] = i;
            for (int j = i * 2; j <= n; j += i)
                a[j] = 1;
        }
}

int main() {
    prime(50000);
    scanf("%lld%lld", &L, &R);
    L += (L == 1);
    if (L > R) {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= cnt; i++) {
        for (ll j = max(2 * 1ll, (L - 1) / pri[i] + 1) * pri[i]; j <= R; j += pri[i])
            if (j - L >= 0) ans[j - L] = 1;
    }
    int tot = 0;
    for (int i = 0; i <= R - L; ++i) if (!ans[i]) tot++;
    printf("%d\n", tot);
    return 0;
}