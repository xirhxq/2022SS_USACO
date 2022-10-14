#include<bits/stdc++.h>
using namespace std;

int main(){
	char s[1010] = "asdasdf";
//	scanf("%s", s);
	printf("%d\n", strlen(s));
	s[7] = 'a';
	printf("%d\n", strlen(s));
	printf("%s", s);
	return 0;
}

