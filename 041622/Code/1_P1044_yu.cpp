#include <iostream>
#include <algorithm>
using namespace std;
long long li[20][20];
int n;
int main(){
    cin>>n;
    for (int i=0;i<=n;i++){
        li[0][i]=1;
    }
    for (int e=1;e<=n;e++){
        for (int i=0;i<=n;i++){
            if (i==0) li[e][i]=li[e-1][i+1];
            else li[e][i]=li[e-1][i+1]+li[e][i-1];
        }
    }
    cout<<li[n][0];
    return 0;
}