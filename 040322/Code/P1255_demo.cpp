//
// Created by xirhxq on 2022/4/3.
//

#include<iostream>
#include<cstring>
using namespace std;

int f_val[5010];

int f(int x){
    if (x == 1 || x == 2) return x;
    if (f_val[x] != 0) return f_val[x];
    return f_val[x] = f(x - 1) + f(x - 2);
}

int main(){
    int n;
    memset(f_val, 0, sizeof(f_val));
    cin >> n;
    cout << f(n);
}