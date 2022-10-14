#include <iostream>
using namespace std;

int a[1010], b[1010], c[1010];

int main(){
	string ain, bin;
	cin >> ain >> bin;
	int maxl = max(ain.length(), bin.length());
	for (int i = 0; i < ain.length(); i++){
		a[i] = ain[ain.length() - 1 - i] - '0';
	} 
	for (int i = 0; i < bin.length(); i++){
		b[i] = bin[bin.length() - 1 - i] - '0';
	}
/*
	1. 下标反向
	2. 数字字符转化成整数 
*/
	for (int i = 0; i < maxl; i++){
		c[i] += a[i] + b[i];
		if (c[i] > 9){
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}

	bool flag = false;
	for (int i = maxl; i >= 0; i--){
		if (c[i] != 0) flag = true;
		if (flag) cout << c[i];
	}

    if (!flag){
        cout << 0;
    }
	return 0;
}

