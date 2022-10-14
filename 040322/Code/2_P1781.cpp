//
// Created by xirhxq on 2022/4/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct student{
    int id;
    char s[110];
    int len;
} s[25];

bool cmp(student a, student b){
    if (a.len != b.len) return a.len < b.len;
    for (int i = 0; i < a.len; i++){
        if (a.s[i] != b.s[i]) return a.s[i] < b.s[i];
    }
    return a.id < b.id;
}

int main(){
    int n;
    scanf("%d", &n);

    char tmp[101];
    for (int i = 1; i <= n; i++){
        scanf("%s", tmp);
        s[i].id = i;
        s[i].len = strlen(tmp);
        for (int j = 0; j < strlen(tmp); j++) s[i].s[j] = tmp[j];
    }
    sort(s + 1, s + n + 1, cmp);
    printf("%d\n", s[n].id);
    for (int i = 0; i < s[n].len; i++) printf("%c", s[n].s[i]);
    return 0;
}