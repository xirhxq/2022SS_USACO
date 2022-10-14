//
// Created by xirhxq on 2022/3/19.
//

#include<iostream>

using namespace std;

int data[303][10];

// data[i] data[j]
bool cmp(int i, int j){
    if (data[j][4] != data[j + 1][4]) return data[j][4] < data[j + 1][4];
    if (data[j][1] != data[j + 1][1]) return data[j][1] < data[j + 1][1];
    return data[j][0] > data[j + 1][1];
}

void swap_line(int i, int j){
    for (int k = 0; k <= 4; k++){
        swap(data[i][k], data[j][k]);
    }
}

int main(){
    int n;cin >> n;
    for (int i = 1; i <= n; i++){
        data[i][0] = i;
        data[i][4] = 0;
        for (int j = 1; j <= 3; j++){
            cin >> data[i][j];
            data[i][4] += data[i][j];
        }
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= n - i; j++){
            if (cmp(j, j + 1)){
                swap_line(j, j + 1);
            }
        }
    }
    for (int i = 1; i <= 5; i++){
        cout << data[i][0] << " " << data[i][4] << endl;
    }
    return 0;
}