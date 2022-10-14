#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    for (ll i = a; i >= 1; i--){
        if (a % i == 0 && b % i == 0){
            return i;
        }
    }
}

int main(){
    int x0, y0;
    cin >> x0 >> y0;

    // n <= 10^10 long long
    // int 2*10^9
    ll n = x0 * y0;

    int cnt = 0;
    for (ll a = 1; a * a <= n; a++){
        if (n % a != 0) continue;
        ll b = n / a;
        if (gcd(a, b) == x0){
            cnt++;
            if (a != b) cnt++;
        }
    }
    cout << cnt;
}