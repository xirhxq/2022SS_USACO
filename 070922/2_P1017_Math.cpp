#include <iostream>

using namespace std;
int n, m;
char a[100001];
int l = 0;

int main() {
    int i;
    cin >> n >> m;
    cout << n << "=";
    while (n != 0) {
        int j = n % m;
        n /= m;
        if (j < 0){
            j -= m, n++;
        }
        if (j < 10) {
            a[++l] = (char) (j + 48);
        }
        else {
            a[++l] = (char) ((j - 10) + 'A');
        }
    }
    for (i = l; i >= 1; i--)cout << a[i];
    cout << "(base" << m << ")" << endl;
}