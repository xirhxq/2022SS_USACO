#include<iostream>
#include<algorithm>
using namespace std;

struct Person{
	int t,id;
}p[1010];

bool cmp(Person a, Person b){
	return a.t < b.t;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i].t;
		p[i].id = i;
	}
	sort(p + 1, p + n + 1, cmp);
	double ans = 0.0;
	for (int i = 1; i <= n; i++){
		cout << p[i].id;
		ans += p[i].t * (n - i);
		if (i < n) cout << " ";
		else cout << endl;
	}
	printf("%.2lf\n", ans / n);
	return 0;
}

