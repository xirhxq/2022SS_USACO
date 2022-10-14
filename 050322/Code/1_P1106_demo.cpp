//
// Created by xirhxq on 2022/5/3.
//

#include<iostream>
using namespace std;

string num;
int n, k, a[505];

int main(){
    cin >> num >> k;
    n = num.length();
    for (int i = 0; i < n; i++){
        a[i] = num[n - i - 1] - '0';
    }
    bool flag = false;
    int rest = n - k, cnt = 0; // 共需要输出rest位 现在已经输出cnt位
    while (cnt < rest){
        int t = n - 1;
        for (int i = n - 2; i >= n - k - 1; i--){
            if (a[i] < a[t]){
                t = i;
            }
        }

        int p = n - t; // t是最小值在a数组里面的位置 p代表从n-1位开始左数的位数
        // 删除左数第1到第p-1位 输出第p位
        cnt++;
//        printf("t = %d p = %d\n", t, p);
        if (a[t] > 0) flag = true;
        if (flag) cout << a[t];

        n -= p;
        k -= p - 1;
    }
    if (!flag) cout << 0;
}