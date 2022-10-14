#include<iostream>
using namespace std;

const int maxn = 1000002;
const int mod = 10000;

int f[maxn], g[maxn];

int main() {
    int n;

    cin >> n;
    f[1] = g[1] = 1;
    f[2] = g[2] = 2;
    f[3] = 5, g[3] = 4;

    for (int i = 4; i <= n; i++) {
        f[i] = ((f[i - 1] + f[i - 2]) % mod + 2 * g[i - 3] % mod + 2 * f[i - 3]) % mod;
        g[i] = (g[i - 1] + f[i - 1]) % mod;
    }

    cout << f[n];

    return 0;
}