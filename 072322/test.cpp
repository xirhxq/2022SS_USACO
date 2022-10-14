#include<iostream>
#include <vector>
#include <cmath>


void encode_one(std::vector<uint8_t> &v, double data){
    if (data < 0) v.push_back(1);
    else v.push_back(0);
    int d = std::abs(int(data * 100.0));
    for (int j = 3; j >= 0; j--){
        uint8_t tmp = (d >> (j * 8)) & ((1 << 8) - 1);
        v.push_back(tmp);
    }
}

void encode(std::vector<uint8_t> &v, double x, double y, double theta){
    encode_one(v, x);
    encode_one(v, y);
    encode_one(v, theta);
}

double decode_one(std::vector<uint8_t> v, int pos){
    int abs_val = (v[pos + 1] << 24) + (v[pos + 2] << 16) + (v[pos + 3] << 8) + v[pos + 4];
    double res;
    if (v[pos] == 1) res = -1.0 * abs_val / 100.0;
    else res = 1.0 * abs_val / 100.0;
    return res;
}

void decode(std::vector<uint8_t> v, double &x, double &y, double &theta){
    x = decode_one(v, 0);
    y = decode_one(v, 5);
    theta = decode_one(v, 10);
}

int main() {
    // encode
    double X = -1165.24, Y = 350.13, Theta = 1.57;
    std::vector<uint8_t> v;
    encode(v, X, Y, Theta);

    // Encode result output:
    for (int i = 0; i < v.size(); i++){
        printf("%4d", v[i]);
    }printf("\n");

    // decode
    double x_received, y_received, theta_received;
    decode(v, x_received, y_received, theta_received);

    // Decode result output:
    printf("Received x: %.2lf y: %.2lf theta: %.2lf\n", x_received, y_received, theta_received);

    return 0;
}