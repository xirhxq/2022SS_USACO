//
// Created by xirhxq on 2022/4/16.
//

#include <iostream>
using namespace std;
int f[1010101],g[1010101];
int n;
int main(){
    f[1]=1;
    f[2]=2;
    f[3]=5;
    g[1]=1;
    g[2]=2;
    g[3]=2+2;
    cin>>n;
    for (int i=4;i<=n;i++){
        g[i]=(g[i-1]+f[i-1])%10000;
        f[i]=(f[i-1]+f[i-2]+2*f[i-3]+2*g[i-3])%10000;
    }
    cout<<f[n];
    return 0;
}