#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <utility>
#define maxn 101010
using namespace std;

int n, g;
map<int, int> cow_milk; // cow id -> mile value
set<pair<int, int> > cows; // <milk value, cow id>

vector<pair< int, pair<int, int> > > change;
int x, y, z;

int main(){
    scanf("%d%d", &n, &g);
    for (int i = 1; i <= n; i++){
        scanf("%d%d%d", &x, &y, &z);
        change.push_back({x, {y, z}});
    }
    sort(change.begin(), change.end());

    for (auto c: change){
        printf("Time %d Cow %d Change %d\n", c.first, c.second.first, c.second.second);
    }

    for (auto c: change){
        int id = c.second.first, milk_change = c.second.second;
        if (cow_milk.find(id) != cow_milk.end()){
            // In map
            cows.erase({cow_milk[id], id});
            cow_milk[id] += milk_change;
            cows.insert({cow_milk[id], id});
        }
        else {
            // Not in map
            cow_milk[id] = milk_change;
            cows.insert({cow_milk[id], id});
        }

        // Adjust milk_value

        cout << "-------------\n";
        for (auto m: cow_milk){
            cout << "Cow: " << m.first << " Milk: " << m.second << endl;
        }
        for (auto cow: cows){
            cout << "Value: " << cow.first << " Cow id: " << cow.second << endl;
        }
        cout << "Max value: " << (*cows.rbegin()).first << endl;
        cout << "Max id:" << (*cows.rbegin()).second << endl;
    }
}