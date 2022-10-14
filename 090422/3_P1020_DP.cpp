#include<bits/stdc++.h>

#define maxn 100010
using namespace std;

int main() {
    int n = 0, x, a[maxn], b[maxn];
    while (cin >> x) {
        a[n] = -x;
        b[n] = x;
        n++;
    }

    int l[maxn], cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt == 0) l[++cnt] = a[i];
        else {
            int tmp = lower_bound(l + 1, l + cnt + 1, a[i] + 1) - l;
            l[tmp] = a[i];
            if (tmp == cnt + 1) cnt++;
        }
    }
    cout << cnt << endl;

    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt == 0) l[++cnt] = b[i];
        else {
            int tmp = lower_bound(l + 1, l + cnt + 1, b[i]) - l;
            l[tmp] = b[i];
            if (tmp == cnt + 1) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}