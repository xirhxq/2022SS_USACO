//
// Created by xirhxq on 2022/4/16.
//

#include <iostream>
using namespace std;

void disp(int x){
    if (x == 0){
        cout << "0";
        return;
    }
    bool flag = false;
    for (int i = 14; i >= 0; i--){
        if ( (x >> i) & 1 ) { // 第 i 位上面是 1
            // 需要输出一个 2(i)
            // 7 = 2(2) + 2 + 2(0);
            if (i == 1){
                if (flag) cout << "+";
                cout << "2";
            }
            else{
                if (flag) cout << "+";
                cout << "2(";
                disp(i);
                cout << ")";
            }
            flag = true;
        }
    }
}

int main(){
    int n;
    cin >> n;
    disp(n);
    return 0;
}