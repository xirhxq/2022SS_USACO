#include<iostream>
#include<algorithm>
using namespace std;

struct Student{
	string name;
	int birth, id;
}s[101];

bool cmp(Student a, Student b){
	if (a.birth == b.birth) return a.id > b.id;
	else return a.birth < b.birth;
}

int main(){
	int n, y, m, d;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> s[i].name >> y >> m >> d;
		s[i].birth = y * 10000 + m * 100 + d;
		s[i].id = i;
	}
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i <= n; i++) cout << s[i].name << endl;
	return 0;
}

