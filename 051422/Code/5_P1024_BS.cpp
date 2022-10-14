#include<bits/stdc++.h>
using namespace std;

double a, b, c, d;

double f(double x){
	return a * x * x * x + b * x * x + c * x + d;
}

int main(){
	cin >> a >> b >> c >> d;
	for (int i = -100; i < 100; i++){
		double l = i, r = i + 1;
		if (f(l) == 0.0){
			printf("%.2lf ", l);
			continue;
		}
		if (f(r) == 0.0) continue;
		if (f(l) * f(r) > 0.0) continue;
		double mid = (l + r) / 2.0;
		while(l + 1e-6 < r){
			mid = (l + r) / 2.0;
			if (f(mid) == 0.0){
				break;
			}
			if (f(mid) * f(l) > 0.0) l = mid;
			else r = mid;
		}
		printf("%.2lf ", mid);
	}
	return 0;
}

