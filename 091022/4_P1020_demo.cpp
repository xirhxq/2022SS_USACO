#include <iostream>
using namespace std;
#define maxn 101010
int n, a[maxn], dp[maxn], h[maxn], cnt;

int main(){
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
    n = 0;
    int x;
    while (cin >> x){
        n++;
        a[n] = x;
    }
    for (int i = 1; i <= n; i++){
        // calculate dp[i]
        int max_id = 0;
        for (int j = 1; j < i; j++){
            if (a[j] >= a[i]) {
                if (dp[j] > dp[max_id] || max_id == 0) {
                    max_id = j;
                }
            }
        }
        if (max_id == 0) dp[i] = 1;
        else dp[i] = dp[max_id] + 1;
    }
    int mx_res = 0;
    for (int i = 1; i <= n; i++){
        mx_res = max(mx_res, dp[i]);
    }
    cout << mx_res << endl;
    cnt = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= cnt; j++){
            if (h[j] >= a[i]){
                h[j] = a[i];
                break;
            }
        }
        if (cnt == 0 || a[i] > h[cnt]){
            cnt++;
            h[cnt] = a[i];
        }
    }
    cout << cnt;
}