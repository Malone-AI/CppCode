#include <iostream>
#include <algorithm>
using namespace std;

/*递增运算符重载*/
class MyInteger{
    friend ostream& operator<<(ostream& cout,const MyInteger &p);
private:
    int n;
public:
    MyInteger(){
        n = 0;
    }
    /*前置++重载*/
    MyInteger& operator++(){
        n++;
        return *this;
    }
    /*后置++重载*/
    MyInteger operator++(int){
        MyInteger tmp = *this;
        n++;
        return tmp;
    }
};

//ostream& operator<<(ostream& cout,MyInteger &p){
//ostream& operator<<(ostream& cout,MyInteger p);
ostream& operator<<(ostream& cout,const MyInteger &p){
    cout << p.n ;
    return cout;
}

int main(){
    MyInteger p;
    cout << p << endl;
    cout << ++(++p) << endl;
    cout << p++ << endl;
    cout << p << endl;
    return 0;
}