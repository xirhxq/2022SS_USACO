#include <iostream>

using namespace std;
int n, q, k, prime[101010101], cnt;
bool deleted[101010101];

int main() {
    scanf("%d %d", &n, &q);
//    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        if (deleted[i] == false) {
            for (int j = 2; i * j <= n; j++) {
                deleted[i * j] = true;
            }
        }
    }
    cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (deleted[i] == false) {
            prime[cnt] = i;
            cnt++;
        }
    }

    while(q--) {
        int val;
//        cin >> val;
        scanf("%d", &val);
//        cout << prime[val] << endl;
        printf("%d\n", prime[val]);
    }
}