//
// Created by xirhxq on 2022/3/19.
//

#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long a[22];

long long digit(long long x){
    int cnt = 1;
    while(x){
        x = x / 10;
        cnt *= 10;
    }
    return cnt;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j <= n - i; j++){
            long long ajajp1 = a[j] * digit(a[j + 1]) + a[j + 1];
            long long ajp1aj = a[j + 1] * digit(a[j]) + a[j];
            if (ajajp1 < ajp1aj){
                swap(a[j], a[j + 1]);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        cout << a[i];
    }
    return 0;
}