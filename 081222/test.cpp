#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct REL_LOC{
    double time, delta_x, delta_y, vel_x, vel_y;
};

int main(){
    REL_LOC first = {435.4, -1129.73, -249.60, 0.07, 0.01};
    REL_LOC last = {435.86, -1132.50, -244.86, 0.07, 0.01};
    double delta_x_vsl = last.delta_x - first.delta_x + (last.vel_x + first.vel_x) / 2.0 * (last.time - first.time);
    double delta_y_vsl = last.delta_y - first.delta_y + (last.vel_y + first.vel_y) / 2.0 * (last.time - first.time);
    delta_x_vsl = last.delta_x - first.delta_x ;
    delta_y_vsl = last.delta_y - first.delta_y ;
    printf("Delta of vsl: (%.2lf, %.2lf)\n", delta_x_vsl, delta_y_vsl);
    printf("Theta output: %.2lf(%.2lf)\n", atan2(delta_y_vsl, delta_x_vsl), atan2(delta_y_vsl, delta_x_vsl) * 180 / acos(-1.0));

    cout << "\033c" << flush;

    cout << "aaa";

}