#include <iostream>
#include <algorithm>
using namespace std;

/*赋值运算符重载*/

class Person{
    friend ostream& operator<<(ostream& cout,const Person &p);
private:
    int *age;
public:
    Person(int tmp){
        /*有参构造*/
        age = new int(tmp);
    }
    ~Person(){
        /*析构函数*/
        if(age != NULL){
            delete age;
            age = NULL;
        }
    }
    // Person operator=(const Person &p){
    Person& operator=(const Person &p){
        /*重载"="运算符以解决浅拷贝问题"*/
        if(this == &p){
            return *this;
        }
        if(age != NULL){
            delete age;
            age = NULL;
        }
        age = new int(*p.age);
        return *this;
    }
};

ostream& operator<<(ostream& cout,const Person &p){
    /*重载Person的cout函数*/
    cout << "Age = " << *p.age ;
    return cout;
}

void test(){
    Person p1(18);
    Person p2(20);
    Person p3(30);
    cout << p1 << endl;
    cout << p2 << endl;
    p2 = p1;
    cout << p2 << endl;
    p1 = p2 = p3;
    cout << p1 << endl << p2 << endl << p3 << endl;
}

int main(){
    test();
    return 0;
}