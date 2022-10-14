#include <cstdio>
#include <algorithm>

using namespace std;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

void solve(int a) {
    for (int i = 2; i + i <= a; i++){
        if (is_prime(i) && is_prime(a - i)){
            printf("%d=%d+%d\n", a, i, a - i);
            break;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 4; i <= n; i += 2){
        solve(i);
    }
    return 0;
}