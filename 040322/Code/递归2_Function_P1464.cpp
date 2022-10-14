#include<iostream>
using namespace std;

long long res[25][25][25];

int w(int a, int b, int c){
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	if (res[a][b][c] != -1) return res[a][b][c];
	if (a < b && b < c) return res[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	return res[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c)
            + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main(){
	int a, b, c;
	memset(res, -1, sizeof(res));
	while (cin >> a >> b >> c){
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c) << endl;
	}
	return 0;
}