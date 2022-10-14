#include <iostream>
using namespace std;
#define maxn 101010
int n, a[maxn], dp[maxn], h[maxn], cnt;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
//    n = 0;
//    int x;
//    while (cin >> x){
//        n++;
//        a[n] = x;
//    }
    for (int i = 1; i <= n; i++){
        // dp[i] 以i结尾的最长不升子序列长度
        dp[i] = 1;
        for (int j = 1; j < i; j++){
            if (a[j] >= a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int mx_res = 0;
    for (int i = 1; i <= n; i++){
        mx_res = max(mx_res, dp[i]);
    }
    cout << mx_res << endl;
//    cnt = 0;
//    for (int i = 1; i <= n; i++){
//        for (int j = 1; j <= cnt; j++){
//            if (h[j] >= a[i]){
//                h[j] = a[i];
//                break;
//            }
//        }
//        if (cnt == 0 || a[i] > h[cnt]){
//            cnt++;
//            h[cnt] = a[i];
//        }
//    }
//    cout << cnt;
}
/*
 8
 389 207 155 300 299 170 158 65
 */