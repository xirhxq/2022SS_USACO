#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	char s[505050];
	scanf("%s", s);
	int res = 0, tmp_g = 0, tmp_h = 0;
	for (int i = 0; i < n; i++){
		tmp_g = tmp_h = 0;
		tmp_g += s[i] == 'G';
		tmp_h += s[i] == 'H';
		tmp_g += s[i + 1] == 'G';
		tmp_h += s[i + 1] == 'H';
		for (int j = i + 2; j < n; j++){
			tmp_g += s[j] == 'G';
			tmp_h += s[j] == 'H';
			if (tmp_g == 1 || tmp_h == 1){
				res++;
			} 
		}
	}
	printf("%d\n", res);
	return 0;
}
