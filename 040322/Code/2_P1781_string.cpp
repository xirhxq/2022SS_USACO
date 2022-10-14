//
// Created by xirhxq on 2022/4/3.
//

//
// Created by xirhxq on 2022/4/2.
//

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct student{
    int id;
    string s;
} s[25];

bool cmp(student a, student b){
    if (a.s.length() != b.s.length()) return a.s.length() < b.s.length();
    int l = a.s.length();
    for (int i = 0; i < l; i++){
        if (a.s[i] != b.s[i]) return a.s[i] < b.s[i];
    }
    return a.id < b.id;
}

int main(){
    int n;
    scanf("%d", &n);

    int a[1010];

    string tmp;
    for (int i = 1; i <= n; i++){
        cin >> tmp;
        s[i].id = i;
        s[i].s = tmp;
    }
    sort(s + 1, s + n + 1, cmp);
    printf("%d\n", s[n].id);
    cout << s[n].s;
    return 0;
}