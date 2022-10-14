#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;

int n, x;
int a[1010101];
map <int,int> mp;

int main(){
	
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++){
		scanf("%d", a + i);
		mp[a[i]]++;
	}
	
	ll ans = 0;
	
	for (int i = 0; i < n; i++){
		ans += mp[a[i] + x];
	}
	printf("%lld\n", ans);
	return 0;
}

