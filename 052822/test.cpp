//
// Created by xirhxq on 2022/5/28.
//

#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>

class A{
public:
    A(){
        x = y = z = 0;
    }

    template<typename T>
    A(const T &t);

public:
    double x, y, z;

//    template<typename T>
//    A& operator= (const T &b);


};

class B{
public:
    double x, y, z;
};

class C{
    double x, y, z;
};

template<typename T1, typename T2>
T1 operator- (const T1 &a, const T2 &b){
    T1 res;
    res.x = a.x - b.x;
    res.y = a.y - b.y;
    res.z = a.z - b.z;
    return res;
}

template<typename T>
A::A(const T &b){
    x = b.x;
    y = b.y;
    z = b.z;
}

int main(){
//    A a1, a2;
//    B b1, b2;
//    a1 - a2;
//    b1 - b2;
//    a1 - b1;
//    b2 - a2;
//    a1 = b2;
//    C c1;
    std::vector<std::string> v;
    std::string s = "vsl_";
    s = s + char('a' + 5) + '_' + char('x' + 2);
    std::cout << s;
//    a1 - c1;
}