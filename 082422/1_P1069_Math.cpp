#include <iostream>
#include <vector>
using namespace std;
#define maxn 30303
typedef long long ll;

ll n, s, m1, m2;
vector<ll> m_prime, m_alpha;

void factor(){
    for (ll i = 2; i * i <= m1; i++){
        if (m1 % i == 0){
            m_prime.push_back(i);
            m_alpha.push_back(0);
            while (m1 % i == 0){
                m1 /= i;
                m_alpha[m_alpha.size() - 1]++;
            }
        }
    }
    if (m1 > 1) {
        m_prime.push_back(m1);
        m_alpha.push_back(1);
    }
//    for (int i = 0; i < m_prime.size(); i++){
//        printf("%d^%d%c", m_prime[i], m_alpha[i], "*\n"[i == m_prime.size() - 1]);
//    }
}

ll solve(){
    ll res = 0;
    if (m_prime.size() == 0) return 0;
    for (int i = 0; i < m_prime.size(); i++){
        // m_prime[i] ^ (m_alpha[i] * m2)
        if (s % m_prime[i] != 0) return -1;
        ll tmp = 0;
        while (s % m_prime[i] == 0){
            s /= m_prime[i];
            tmp++;
        }
        // tmp: m_prime[i] time in s
        // tmp * t >= m_alpha[i] * m2
        // t >= ceil(m_alpha[i] * m2 / tmp)
        res = max(res, (m_alpha[i] * m2 + tmp - 1) / tmp);
    }
    return res;
}

int main(){
    scanf("%lld", &n);
    scanf("%lld %lld", &m1, &m2);
    factor();
    ll ans = -1;
    for (int i = 1; i <= n; i++){
        scanf("%lld", &s);
        ll tmp = solve();
        if (tmp == -1) continue;
        if (ans == -1 || ans > tmp) ans = tmp;
    }
    printf("%lld\n", ans);
}