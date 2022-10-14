//
// Created by xirhxq on 2022/4/3.
//

#include<iostream>
using namespace std;

int main(){
    // 0 -1 0x3f
    int a[10];
    cin >> a[0] >> a[1];
    cout << "before memset: " << a[0] << " " << a[1] << endl;
    memset(a, 0x3f, sizeof(a));
    cout << "after memset: " << a[0] << " " << a[1];
    return 0;
}