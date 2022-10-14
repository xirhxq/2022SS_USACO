#include <iostream>
using namespace std;
int l,n,m;
int d[50505];
bool check(int x){
    int res=0,now=0;
    for (int i=1;i<=n+1;i++){
        if (d[i]-now<x){
            res++;
            continue;
        }
        now=d[i];
    }
    return res <= m;
}
int main(){
    cin>>l>>n>>m;
    d[0]=0;d[n+1]=l;
    for (int i=1;i<=n;i++) cin>>d[i];
    int l=0,r=l+1,mid;
    while(l<r){
        mid=(l+r)/2;
        if (check(mid)){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    cout<<l-1;
    return 0;
}