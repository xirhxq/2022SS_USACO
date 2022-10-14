#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

struct student{
    int num;
    int chinese;
    int math;
    int english;
};

bool cmp(student a,student b){
    if (a.chinese + a.math + a.english != b.chinese + b.math + b.english)
        return a.chinese + a.math + a.english > b.chinese + b.math + b.english;
    if (a.chinese != b.chinese) return a.chinese > b.chinese;
    return a.num < b.num;
}

int main(){
    int n;scanf("%d",&n);
    student a[330];
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d", &a[i].chinese, &a[i].math, &a[i].english);
        a[i].num = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= 5; i++){
        printf("%d %d\n", a[i].num, a[i].chinese + a[i].math + a[i].english);
    }
    return 0;
}