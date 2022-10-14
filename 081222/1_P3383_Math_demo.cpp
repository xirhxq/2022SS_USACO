#include <iostream>

using namespace std;

#define N 101010101

bool deleted[N];
int prime[N / 10], cnt;

int main(){
    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 2; i <= n; i++){
        if (deleted[i] == false){
            for (int j = 2; i * j <= n; j++){
                deleted[i * j] = true;
            }
        }
    }
    cnt = 0;
    for (int i = 2; i <= n; i++){
        if (deleted[i] == false){
//            ++cnt;
//            prime[cnt] = i;
            prime[++cnt] = i;
        }
    }

    for (int i = 1; i <= q; i++){
        int k;
        scanf("%d", &k);
        printf("%d\n", prime[k]);
    }


}