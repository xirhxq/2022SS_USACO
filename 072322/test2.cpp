#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

#define DEG2RAD (acos(-1.0) / 180)


struct Point{
    double x, y, z;
};

string output_str(Point x){
    char s[50];
    sprintf(s, "(%.2lf, %.2lf, %.2lf)", x.x, x.y, x.z);
    string res(s);
    return res;
}

Point scissor_point(double theta, double unit_l, double unit_h, double scissor_height = 50.0, int id = 1){
    Point res;
    int part_id = (id > 7) ? (id - 7) : id;
    res.x = part_id * unit_l;
    res.y = (id % 2) ? unit_h : -unit_h;
    res.z = scissor_height;
    printf("res: %s\n", output_str(res).c_str());

    theta = (id > 7) ? -abs(theta) : abs(theta);

    Point sci;
    sci.x = res.x * cos(theta) + res.y * sin(theta) - 1500;
    sci.y = -res.x * sin(theta) + res.y * cos(theta);
    sci.z = res.z;
    return sci;
}


int main(){
    vector<Point> vec;
    for (int i = 1; i <= 1; i++){
        vec.push_back(scissor_point(30 * DEG2RAD, 400, 400, 50, i));
        printf("%d: %s\n", i, output_str(vec[i - 1]).c_str());
    }
    return 0;
}