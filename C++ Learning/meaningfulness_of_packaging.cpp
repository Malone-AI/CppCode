#include <iostream>
using namespace std;

const int PI=3.14;

//设计一个圆类,求圆的周长
class Circle{
public:
    int r;

    double perimeter(){
        return 2*PI*r;
    }
};

int main(){
    Circle c1;
    c1.r=10;
    cout<<"圆的周长 = "<<c1.perimeter()<<endl;
    return 0;
}