#include <iostream>

using namespace std;

void solve(int x1, int y1, int x2, int y2, int n) {
    if (n == 1) return;
    if (x1 - x2 < (n >> 1)) {
        if (y1 - y2 < (n >> 1)) {
            cout << (x2 + (n >> 1)) << ' ' << (y2 + (n >> 1)) << ' ' << 1 << endl;
            solve(x1, y1, x2, y2, (n >> 1));
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1), x2, y2 + (n >> 1), (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1) - 1, x2 + (n >> 1), y2, (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1), x2 + (n >> 1), y2 + (n >> 1), (n >> 1));
        } else {
            cout << (x2 + (n >> 1)) << ' ' << (y2 + (n >> 1) - 1) << ' ' << 2 << endl;
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1) - 1, x2, y2, (n >> 1));
            solve(x1, y1, x2, y2 + (n >> 1), (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1) - 1, x2 + (n >> 1), y2, (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1), x2 + (n >> 1), y2 + (n >> 1), (n >> 1));
        }
    } else {
        if (y1 - y2 < (n >> 1)) {
            cout << (x2 + (n >> 1) - 1) << ' ' << (y2 + (n >> 1)) << ' ' << 3 << endl;
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1) - 1, x2, y2, (n >> 1));
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1), x2, y2 + (n >> 1), (n >> 1));
            solve(x1, y1, x2 + (n >> 1), y2, (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1), x2 + (n >> 1), y2 + (n >> 1), (n >> 1));
        } else {
            cout << (x2 + (n >> 1) - 1) << ' ' << (y2 + (n >> 1) - 1) << ' ' << 4 << endl;
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1) - 1, x2, y2, (n >> 1));
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1), x2, y2 + (n >> 1), (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1) - 1, x2 + (n >> 1), y2, (n >> 1));
            solve(x1, y1, x2 + (n >> 1), y2 + (n >> 1), (n >> 1));
        }
    }
}

int main() {
    int k, x, y;
    cin >> k >> x >> y;
    solve(x, y, 1, 1, 1 << k);
    return 0;
}