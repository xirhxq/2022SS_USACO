#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, string> m;
    m[-1] = "a1";
    m[10] = "b2";
    m[-1] = "c3";
    cout << m[-1] << endl;

    // Find "hello"
    bool flag;
    if (m.find(10) != m.end()){
        flag = true;
    }
    else {
        flag = false;
    }
    cout << flag << endl;

    for (auto it = m.begin(); it != m.end(); it++){
        // *it = <key, value> (pair)
        cout << "key: " << (*it).first << " value: " << (*it).second << endl;
    }

    for (auto a: m){
        cout << "key: " << a.first << " value : " << a.second << endl;
    }

    auto it = m.begin();
    cout << "min key: " << (*it).first << " value: " << (*it).second << endl;

    it = m.end();
    it--;
    cout << "max key: " << (*it).first << " value: " << (*it).second << endl;

    auto itt = m.rbegin();
    cout << "max key: " << (*itt).first << " value: " << (*itt).second << endl;

    itt = m.rend();
    itt--;
    cout << "min key: " << (*itt).first << " value: " << (*itt).second << endl;

}