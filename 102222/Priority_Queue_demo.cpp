#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

int main(){
    priority_queue<int, vector<int>, greater<int> > q;
    q.push(1);
    q.push(2);
    cout << "Now at top: " << q.top() << endl;
    q.push(-1);
    cout << "Now at top: " << q.top() << endl;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int> > > p;
    p.push(make_pair(10ll, 1));
    cout << "Now at top: " << p.top().first << " " << p.top().second << endl;
    p.push(make_pair(6ll, 2));
    cout << "Now at top: " << p.top().first << " " << p.top().second << endl;
    p.push(make_pair(20ll, 3));
    cout << "Now at top: " << p.top().first << " " << p.top().second << endl;
    p.push(make_pair(4ll, 4));
    cout << "Now at top: " << p.top().first << " " << p.top().second << endl;

    return 0;
}