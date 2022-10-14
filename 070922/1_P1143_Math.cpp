#include<iostream>
#include<cmath>

using namespace std;
string a;
int b[100];
int c[100], n, m, cnt, sum;

int main() {
    scanf("%d", &n);
    cin >> a;
    scanf("%d", &m);
    for (int i = a.length() - 1; i >= 0; i--){
        if (a[i] >= '0' && a[i] <= '9'){
            b[a.length() - i - 1] = a[i] - '0';
        }
        else{
            b[a.length() - i - 1] = a[i] - 'A' + 10;
        }
    }
    sum = 0;
    for (int i = 0; i < a.length(); i++){
        sum += pow(n, i) * b[i];
    }
    cnt = 0;
    while (sum > 0) {
        c[cnt] = sum % m;
        cnt++;
        sum /= m;
    }
    for (int x = cnt - 1; x >= 0; x--) {
        if (c[x] >= 10) printf("%c", c[x] + 'A' - 10);
        else printf("%d", c[x]);
    }
    return 0;
}