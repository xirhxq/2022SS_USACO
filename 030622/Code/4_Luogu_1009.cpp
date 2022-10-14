#include<iostream>
using namespace std;

int a[110],ans[110];
int n;

int main(){
	cin >> n;
	for (int k = 0; k < 110; k++){
		a[k] = 0;
		ans[k] = 0; 
	}
	a[0] = 1; // a = 00000001 = 1!
	ans[0] = 1; // ans = 0000001 = 1!	
	for (int i = 2; i <= n; i++){
		//计算i的阶乘
		// i! = i * (i-1)! = i * a数组
		/*
			  1 20
			    4
		 --------
		       20
		*/
		for (int k = 0; k < 100; k++){
			a[k] *= i;
		}
		for (int k = 0; k < 100; k++){
			if (a[k] > 9){
				a[k+1] += a[k] / 10;
				a[k] %= 10;
			}
		}
		
		// a数组 = i!
		
		// ans += a数组
		for (int k = 0; k < 100; k++){
			ans[k] += a[k];
			if (ans[k] > 9){
				ans[k+1] ++;
				ans[k] -= 10;
			}
//			cout << "ans " << k << " " << ans[k]  << " " << a[k] << endl; 
		} 
	}
	bool flag = false;
	for (int k = 100; k >= 0; k--){
		if (ans[k] != 0) flag = true;
//		cout << "k = " << k << endl;
		if (flag) cout << ans[k];
	}
	return 0;
}

