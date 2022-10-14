//
// Created by xirhxq on 2022/6/18.
//

#include <iostream>
using namespace std;

double n, m;
int k;

// 1 + p% -> (1 + p/100)
// f(p) = 1/1+p + 1/(1+p)^2 + ... + 1 / (1+p)^k

bool judge(double p){
    double res = 0, tmp = 1;
    for (int i = 1; i <= k; i++){
        tmp *= 1 + p / 100;
        res += 1 / tmp;
    }
    return res >= n / m;
}

int main(){
    cin >> n >> m >> k;
    double l = 0, r = 1000, mid;
    while (r - l > 1e-4){
        mid = (l + r) / 2;
        if (judge(mid)){ // f(mid) >= n / m
            l = mid;
        }
        else {
            r = mid;
        }
    }
    printf("%.1lf", l);
}