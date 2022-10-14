#include<iostream>
#include<queue>
#include<vector>

struct Filter{
    std::vector<double> q;
    int size;

    Filter(int sz_ = 10){
        size = sz_;
        while (!q.empty()) q.erase(q.begin());
    }

    void new_data(double nd_){
        q.push_back(nd_);
        if (q.size() > size) q.erase(q.begin());
    }

    double result(){
        std::vector<double> tmp = q;
        std::sort(tmp.begin(), tmp.end());
        return (tmp[(tmp.size() - 1) / 2] + tmp[tmp.size() / 2]) / 2;
    }

    void output(){
        printf("Now:");
        for (auto i: q){
            printf("\t%lf", i);
        }
        printf("\n");
    }
};

template<typename T>
struct XYZ_Filter{
    Filter x, y, z;
    XYZ_Filter(int sz_ = 10): x(sz_), y(sz_), z(sz_){

    }

    void new_data(T nd_){
        x.new_data(nd_.x);
        y.new_data(nd_.y);
        z.new_data(nd_.z);
    }

    T result(){
        T res;
        res.x = x.result();
        res.y = y.result();
        res.z = z.result();
        return res;
    }

    void output(){
        x.output();
        y.output();
        z.output();
    }
};

struct Point{
    double x, y, z;
    Point(double x_ = 0, double y_ = 0, double z_ = 0): x(x_), y(y_), z(z_){

    }
    void output(){
        printf("A Point @ (%lf, %lf, %lf)\n", x, y, z);
    }
};

int main(){
//    Filter f(5);
//    for (int i = 1; i <= 20; i++){
//        printf("put %d\n", i);
//        f.new_data(i);
//        f.output();
//        printf("filter output: %lf\n", f.result());
//    }

    XYZ_Filter<Point> ff(10);
    for (int i = 1; i <= 2000; i++){
        ff.new_data(Point(i, 2 * i, 3 * i));
        ff.output();
        ff.result().output();
    }
    return 0;
}