//
// Created by xirhxq on 2022/5/3.
//

#include<iostream>
using namespace std;

long long n,a[301],ans;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int q = 0, p = n;
    while (q < p){
        ans += (a[p] - a[q]) * (a[p] - a[q]);
        q++;
        ans += (a[q] - a[p]) * (a[q] - a[p]);
        p--;
    }
    cout << ans;
    return 0;
}