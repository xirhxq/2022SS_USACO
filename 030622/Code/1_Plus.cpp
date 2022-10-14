#include <iostream>
using namespace std;

int a[1010], b[1010], c[1010];

int main(){
	string ain, bin;
	cin >> ain >> bin;
	for (int i = 0; i < ain.length(); i++)	a[i] = ain[ain.length() - 1 - i] - '0';
	for (int i = 0; i < bin.length(); i++)	b[i] = bin[bin.length() - 1 - i] - '0';
    int max_l = max(ain.length(), bin.length());
	for (int i = 0; i < max_l; i++){
		c[i] = a[i] + b[i];
	}
	for (int i = 0; i < max_l; i++){
		if (c[i] > 9){
			c[i + 1] ++;
			c[i] -= 10;
		}
	}
	if (c[max_l] != 0) max_l++;
	for (int i = max_l - 1; i >= 0; i--){
		cout << c[i];
	}
	return 0;
}

