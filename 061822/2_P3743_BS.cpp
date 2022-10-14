//
// Created by xirhxq on 2022/6/18.
//

#include <iostream>
using namespace std;

#define maxn 101010

double a[maxn], b[maxn], p;
int n;

bool judge(double t){
    double res = 0;
    for (int i = 0; i < n; i++){
        if (b[i] - a[i] * t > 0) continue;
        else res += a[i] * t - b[i];
//        res += max(a[i] * t - b[i], 0.0);
    }
    return res <= p * t;
}

int main(){
    cin >> n >> p;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", a + i, b + i);
        sum += a[i];
    }
    if (sum <= p){
        cout << -1 << endl;
        return 0;
    }
    double l = 0, r = 1e10, mid;
    while (r - l > 1e-6){
        mid = (l + r) / 2;
        if (judge(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}