#include <iostream>
#include <vector>
#define maxn 101010
using namespace std;

int n, s[maxn];
int pre[maxn], min_s[maxn];

int main(){
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    scanf("%d", &n);
    pre[0] = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", s + i);
        pre[i] = pre[i - 1] + s[i];
    }
    min_s[n] = s[n];
    for (int i = n - 1; i >= 1; i--){
        min_s[i] = min(min_s[i + 1], s[i]);
    }
    double mx = 0.0;
    for (int k = 1; k <= n - 2; k++){
        mx = max(mx, 1.0 * (pre[n] - pre[k] - min_s[k + 1]) / (n - k - 1));
    }
    for (int k = 1; k <= n - 2; k++){
        if (1.0 * (pre[n] - pre[k] - min_s[k + 1]) / (n - k - 1) == mx){
            printf("%d\n", k);
        }
    }
}