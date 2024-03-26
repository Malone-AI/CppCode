#include <iostream>
using namespace std;

/*C++运算符重载-左移运算符重载*/
class Person{
    friend ostream& operator<<(ostream &out,Person p);
private:
    int a,b;
public:
    Person(){};
    Person(int A,int B){
        this->a = A;
        this->b = B;
    }
};
/*左移运算符一般用全局函数重载*/
ostream& operator<<(ostream &out,Person p){
    out << "a = " << p.a << endl << "b = " << p.b;
    return out;
}

int main(){
    Person p1(3,4);
    cout << p1 << endl;
    return 0;
}