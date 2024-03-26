#include <iostream>
using namespace std;

/*C++运算符重载-加号运算符重载*/
class Person{
public:
    int a,b;
    Person(){
        /*默认构造*/
    };
    Person(int A,int B){
        /*有参构造*/
        this->a = A;
        this->b = B;
    }
    //Person operator+(Person &p){
    //    /*成员函数重载*/
    //    Person tmp;
    //    tmp.a = this->a + p.a;
    //    tmp.b = this->b + p.b;
    //    return tmp;
    //}
};

/*全局函数重载*/
Person operator+(Person &p1,Person &p2){
    Person tmp;
    tmp.a = p1.a + p2.a;
    tmp.b = p1.b + p2.b;
    return tmp;
}

int main(){
    Person p1(3,4);
    Person p2(5,6);
    Person p3 = p1 + p2;
    cout << "p3.a = " << p3.a << endl << "p3.b = " << p3.b << endl;
    return 0;
}