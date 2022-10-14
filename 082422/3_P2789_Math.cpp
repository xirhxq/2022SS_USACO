#include <iostream>
using namespace std;

int n, cnt;
bool ans[330];

void solve(int p, int inter){
    if (p == 0){
        if (!ans[inter]){
            cnt++;
            ans[inter] = true;
        }
    }
    else {
        for (int i = 1; i <= p; i++){
            solve(p - i, i * (p - i) + inter);
        }
    }
}

int main(){
    cnt = 0;
    scanf("%d", &n);
    solve(n, 0);
    printf("%d\n", cnt);
}