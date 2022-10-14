#include <iostream>
using namespace std;
#define maxn 101010
int n, a[maxn], dp[maxn];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        dp[i] = 1;
        for (int j = 1; j < i; j++){
            if (a[j] >= a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    // dp[i]: a[1] ... a[i] 中以a[i]为结尾的最长不升/不降/上升/下降子序列长度


    int mx_res = 0;
    for (int i = 1; i <= n; i++){
        mx_res = max(mx_res, dp[i]);
    }
    cout << mx_res << endl;
}
/*
 8
 389 207 155 300 299 170 158 65
 */