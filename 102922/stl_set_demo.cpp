#include <iostream>
#include <set>

using namespace std;

int main(){
//    set<int> s;
    multiset<int> s;
    s.insert(-1);
    s.insert(10);
    s.insert(2);

    bool flag;
    if (s.find(5) != s.end()){
        flag = true;
    }
    else {
        flag = false;
    }
    cout << flag << endl;

    for (auto it = s.begin(); it != s.end(); it++){
        cout << "value: " << (*it) << endl;
    }

    s.erase(2);
    s.insert(1);

    for (auto a: s){
        cout << "value: " << a << endl;
    }

    s.insert(2);

    for (auto a: s){
        cout << "value: " << a << endl;
    }

    cout << "max value: " << *s.rbegin() << endl;

}