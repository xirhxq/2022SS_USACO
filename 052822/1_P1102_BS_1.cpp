#include<algorithm>
using namespace std;
typedef long long ll;

int binary_search(int p[], int num, int target){
	int left = 0, right = num;
	while (left < right){
		int mid = (left + right) / 2;
		if (target <= p[mid]) right = mid;
		else left = mid + 1;
	}
	return right;
}

int n, x;
int a[1010101];

int main(){
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a+n);  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	ll ans = 0;
	for (int i = 0; i < n; i++){
		// B = a[i]
		// A = B + C = a[i] + x
		// num(==A) = num(>=A) - num(>=A+1)
		// num(==A) = pos(first >=A+1) - pos(first >=A)
		ans += binary_search(a, n, a[i] + x + 1) - binary_search(a, n, a[i] + x);
	}
	printf("%lld\n", ans);
	return 0;
}
