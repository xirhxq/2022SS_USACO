//
// Created by xirhxq on 2022/4/3.
//

#include<iostream>
#include<cmath>

using namespace std;

struct person {
    int id, score;
} p[5005];

bool cmp(person a, person b) {
    if (a.score != b.score) return a.score > b.score;
    else return a.id < b.id;
}

int main() {
    int n, m;
    cin >> n >> m;
    int s = floor(m * 1.5);
    for (int i = 0; i < n; i++) {
        cin >> p[i].id >> p[i].score;
    }
    sort(p, p + n, cmp);
    int scoreline = p[s - 1].score;
    for (int i = s; i < n; i++) {
        if (p[i].score == scoreline) s++;
        else break;
    }
    cout << scoreline << " " << s << endl;
    for (int i = 0; i < s; i++) {
        cout << p[i].id << " " << p[i].score << endl;
    }
    return 0;
}