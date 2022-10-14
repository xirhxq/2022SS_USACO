//
// Created by xirhxq on 2022/4/29.
//
#include<iostream>
using namespace std;

void f(int x1, int y1, int x2, int y2, int n){
    if (n == 1) return;
    if (x2 <= (n >> 1)){
        if (y2 <= (n >> 1)){
            cout << (n >> 1) + x1 << " " << (n >> 1) + y1 << " " << 1 << endl;
            f(x1, y1, x2, y2, n >> 1);
            f(x1, y1 + (n >> 1), n >> 1, 1, n >> 1);
            f(x1 + (n >> 1), y1, 1, n >> 1, n >> 1);
            f(x1 + (n >> 1), y1 + (n >> 1), 1, 1, n >> 1);
        }
        else {
            cout << (n >> 1) + x1 << " " << (n >> 1) + y1 - 1 << " " << 2 << endl;
            f(x1, y1, n >> 1, n >> 1, n >> 1);
            f(x1, y1 + (n >> 1), x2, y2 - (n >> 1), n >> 1);
            f(x1 + (n >> 1), y1, 1, n >> 1, n >> 1);
            f(x1 + (n >> 1), y1 + (n >> 1), 1, 1, n >> 1);
        }
    }
    else {
        if (y2 <= (n >> 1)){
            cout << (n >> 1) + x1 - 1 << " " << (n >> 1) + y1 << " " << 3 << endl;
            f(x1, y1, n >> 1, n >> 1, n >> 1);
            f(x1, y1 + (n >> 1), n >> 1, 1, n >> 1);
            f(x1 + (n >> 1), y1, x2 - (n >> 1), y2, n >> 1);
            f(x1 + (n >> 1), y1 + (n >> 1), 1, 1, n >> 1);
        }
        else {
            cout << (n >> 1) + x1 - 1 << " " << (n >> 1) + y1 - 1 << " " << 4 << endl;
            f(x1, y1, n >> 1, n >> 1, n >> 1);
            f(x1, y1 + (n >> 1), n >> 1, 1, n >> 1);
            f(x1 + (n >> 1), y1, 1, n >> 1, n >> 1);
            f(x1 + (n >> 1), y1 + (n >> 1), x2 - (n >> 1), y2 - (n >> 1), n >> 1);
        }
    }
}

int main(){
    int k, x, y;
    cin >> k >> x >> y;
    f(1, 1, x, y, 1 << k);
}