#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#define inf 0x3f3f3f3f
//#define ONLINE_JUDGE
using namespace std;

int n, g, t, id, dv;
vector<pair<int, pair<int, int> > > changes;
map<int, int> milk;
multiset<int> values;
set<pair<int, int> > cows;
map<int, pair<pair<int, int>, int>> max_value;

int main(){
#ifdef ONLINE_JUDGE
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
#endif
    scanf("%d%d", &n, &g);
    while (n--){
        scanf("%d%d%d", &t, &id, &dv);
        changes.push_back({t, {id, dv}});
    }
    sort(changes.begin(), changes.end());
    max_value[0] = {{0, 0}, inf};
    for (auto c: changes){
        int cow_id = c.second.first, milk_change = c.second.second;
#ifndef ONLINE_JUDGE
        printf("---------\n");
        printf("Time %d, Cow #%d, Change %d\n", c.first, c.second.first, c.second.second);
#endif
        if (milk.find(cow_id) == milk.end()){
            milk[cow_id] = milk_change;
            values.insert(milk[cow_id]);
            cows.insert({milk[cow_id], cow_id});
        }
        else {
            values.erase(milk[cow_id]);
            cows.erase({milk[cow_id], cow_id});
            milk[cow_id] = milk[cow_id] + milk_change;
            if (milk[cow_id] != 0){
                values.insert(milk[cow_id]);
                cows.insert({milk[cow_id], cow_id});
            }
        }
        if (!values.empty() && *values.rbegin() > 0){
            max_value[c.first] = {*cows.rbegin(), values.count(*values.rbegin())};
        }
        else {
            max_value[c.first] = {{0, 0}, inf - values.size()};
        }
#ifndef ONLINE_JUDGE
        printf("Milk map:");
        for (auto m: milk){
            printf(" %d(%d)", m.first, m.second);
        }
        printf("\n");
        printf("Milk values:");
        for (auto m: values){
            printf(" %d(%ld)", m, values.count(m));
        }
        printf("\n");
        printf("Max value: ((%d, %d), %d)\n", max_value[c.first].first.first, max_value[c.first].first.second, max_value[c.first].second);
#endif
    }
    int change_cnt = 0;
    int pre_time = (*max_value.begin()).first;
    for (auto v: max_value){
        if (v.first == pre_time) continue;
#ifndef ONLINE_JUDGE
        printf("Now value: (%d, (%d, %d))\n", v.first, v.second.first, v.second.second);
        printf("Pre value: (%d, (%d, %d))\n", pre_time, max_value[pre_time].first, max_value[pre_time].second);
#endif
        if (v.second != max_value[pre_time]) {
            change_cnt++;
            if (v.second.second == 1 && max_value[pre_time].second == 1 && v.second.first.second == max_value[pre_time].first.second){
                change_cnt--;
            }
        }
        pre_time = v.first;
    }
    printf("%d\n", change_cnt);
}