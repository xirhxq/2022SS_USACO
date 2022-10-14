#include<iostream>

#define maxn 100010
using namespace std;

int main() {
    int n = 0, x, a[maxn], b[maxn];
    while (cin >> x) {
        a[n] = -x;
        b[n] = x;
        n++;
    }

    // LIS: Longest Increasing Subsequence

//    cin >> n;
//    for (int i = 0; i < n; i++){
//        cin >> b[i];
//        a[i] = -b[i];
//    }
    // b[i] > 0
    // a[i] = -b[i]


    int l[maxn], cnt = 0;
    for (int i = 0; i < n; i++) {
//        printf("--- a[%d] = %d\n", i, a[i]);
//        if (cnt > 0 ) {printf("l: ");for (int j = 1; j <= cnt; j++) printf("%d%c", l[j], " \n"[j == cnt]);}
        if (cnt == 0) l[++cnt] = a[i];
        else {
            // l[1] l[2] ... l[cnt]
            int tmp = lower_bound(l + 1, l + cnt + 1, a[i] + 1) - l;
//            printf("into %d\n", tmp);
            l[tmp] = a[i];
            if (tmp == cnt + 1) cnt++;
        }
//        if (cnt > 0 ) {printf("now l: ");for (int j = 1; j <= cnt; j++) printf("%d%c", l[j], " \n"[j == cnt]);}
    }
    cout << cnt << endl;

    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt == 0) l[++cnt] = b[i];
        else {
            // l[1] <= l[2] <= .. <= l[cnt]
            int tmp = lower_bound(l + 1, l + cnt + 1, b[i]) - l;
            l[tmp] = b[i];
            if (tmp == cnt + 1) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

/*
 7
 389 355 420 401 340 390 401
 */