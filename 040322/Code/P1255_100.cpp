#include<cstdio>
using namespace std;

int a[5050][300];

int main(){
    int n;
    scanf("%d", &n);
    a[1][0] = 1;
    a[2][0] = 2;
    for (int i = 3; i <= n; i++){
        for (int j = 250; j >= 0; j--){
            a[i][j] = a[i - 1][j] + a[i - 2][j];
        }
        for (int j = 0; j <= 250; j++){
            a[i][j+1] += a[i][j] / 100000;
            a[i][j] %= 100000;
        }
    }
    bool flag = false;
    for (int j = 250; j >= 0; j--){
        if (flag) printf("%05d", a[n][j]);
        else {
            if (a[n][j] > 0) {
                printf("%d", a[n][j]);
                flag = true;
            }
        }
    }
    if (!flag) printf("0");
    return 0;
}