#include <iostream>
using namespace std;

int a[2010], b[2010], c[4020];

int main(){
	string ain, bin;
	cin >> ain >> bin;
	int maxl = ain.length() + bin.length();
	for (int i = 0; i < ain.length(); i++){
		a[i] = ain[ain.length() - 1 - i] - '0';
	} 
	for (int i = 0; i < bin.length(); i++){
		b[i] = bin[bin.length() - 1 - i] - '0';
	}
    for (int i = 0; i < ain.length(); i++){
        for (int j = 0; j < bin.length(); j++){
            c[i + j] += a[i] * b[j];
        }
    }
	for (int i = 0; i < maxl; i++){
		if (c[i] > 9) {
			c[i+1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	bool flag = false;//表示现在这一位是否输出 
	for (int i = maxl; i >= 0; i--){
		if (c[i] != 0) flag = true;
		if (i == 0) flag = true;
		if (flag) cout << c[i];
	}
	return 0;
}

// a 是三位数  100 <= a <= 999  10^3 <= a <= 10^4 - 1
// a是l位数  10^l <= a <= 10^(l+1) - 1
// b是m位数  10^(l+m)  <= a * b <= (10^(l+1) - 1) * (10 ^ (m+1) - 1) <= 10^(l+m+2) - 1
// (10^(l+1) - 1) * (10 ^ (m+1) - 1) = 10^(l+m+2) - 100 - 100 + 1 <= 10^(l+m+2) - 1
// a*b 是 l+m 或者 l+m+1 位数
// 结果为 maxl 位数 或者 maxl+1 位数
// 最高位 maxl-1   或者  maxl

/*
	1. 下标反向
	2. 数字字符转化成整数
*/
//    for (int i = 0; i <= maxl; i++){
//        // compute c[i]
//        for (int j = 0; j <= i; j++){
//            c[i] += a[j] * b[i - j];
//        }
//    }