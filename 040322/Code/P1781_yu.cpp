#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct student {
    int id;
    string s;
}s[25];
bool cmp(student a,student b){
    if (a.s.length()!=b.s.length()) return a.s.length()<b.s.length();
    int l=a.s.length();
    for (int i=0; i<l; i++) {
        if(a.s[i]!=b.s[i])return a.s[i]<b.s[i];
    }
    return a.id<b.id;
}
int main() {
    int num;
    cin>>num;
    string k;
    for (int i=1; i<=num; i++) {
        cin>>k;
        s[i].id=i;
        s[i].s=k;
    }
    sort(s+1,s+num+1,cmp);
    cout<<s[num].id << endl;
    cout<<s[num].s;


    return 0;
}