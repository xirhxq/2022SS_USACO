#include <iostream>
#include <cstring>
using namespace std;
int n,cnt_num=0,numli[501],len,last;
int res[1010];
int leng(int m){
    if (m==0) return 1;
    int res=0;
    while(m){
        m/=10;
        res++;
    }
    return res;
}
void cnt(int l){
    if (res[l] != -1) {
        return;
    }
    int la;
    if (l%2==1) la=l-1;
    else la=l;
    res[l] = 0;
    for (int i=1;i<=la/2;i++){
        cnt(i);
        res[l] += res[i];
    }
    res[l] += 1;
}
int main(){
    len=0;
    cin>>n;
    memset(res, -1, sizeof(res));
    for (int i=1;i<=n/2;i++){
        numli[i]=i;
        len+=1;
    }
    cnt(n);
    cout<< res[n];
    return 0;
}