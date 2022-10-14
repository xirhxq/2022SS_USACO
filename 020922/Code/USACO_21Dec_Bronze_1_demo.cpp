//http://www.usaco.org/index.php?page=viewproblem2&cpid=1155

#include<bits/stdc++.h>
using namespace std;

int n;

char s[505050];

bool count(int st, int ed){
	int g_cnt = 0;
	for (int i = st; i < ed; i++){
		if (s[i] == 'G') g_cnt++;
	}
	if (g_cnt == 1 || ed - st - g_cnt == 1){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	
	int res = 0;
	
	for (int l = 3; l <= n; l++){
		for (int i = 0; i <= n - l; i++){
			if (count(i, i + l)){
				res++;
			}
		}
	}
	
	printf("%d\n", res);
	
	return 0;
}
