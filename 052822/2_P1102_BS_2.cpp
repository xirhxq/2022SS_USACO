#include<algorithm>
using namespace std;
typedef long long ll;

int n, x;
int a[1010101];

int main(){
	
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) scanf("%d", a + i);

    //Sort first!!!!!!!!!!!!!!!
	sort(a, a+n);
	
	ll ans = 0;
	for (int i = 0; i < n; i++){
		ans += lower_bound(a, a + n, a[i] + x + 1) - lower_bound(a, a + n, a[i] + x);
	}
	printf("%lld\n", ans);
	return 0;
}
