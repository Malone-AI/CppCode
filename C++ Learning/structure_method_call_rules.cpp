#include <iostream>
using namespace std;

//构造函数的调用规则

//一般情况下,编译器提供至少3个构造函数
//1.默认构造函数(无参,为空实现) 2.默认析构函数  3.默认拷贝构造函数

//1.自己编写了有参构造函数时,编译器不再提供无参构造,但提供拷贝构造
//2.自己编写了拷贝构造函数时,编译器不再提供任意类型构造函数

class Person{
public:
    int age;
    //Person(){
    //    cout<<"无参构造函数的调用"<<endl;
    //}
    Person(int m_age){
        age=m_age;
        cout<<"有参构造函数的调用"<<endl;
    }
    Person(const Person &p){
        age=p.age;
        cout<<"拷贝构造函数的调用"<<endl;
    }
    ~Person(){
        cout<<"析构函数的调用"<<endl;
    }
};

//void test01(){
//    Person p1;
//    p1.age=18;
//    Person p2(p1);
//    cout<<"The age of p2 = "<<p2.age<<endl;
//}

void test02(){
    Person p(18);
    Person p2(p);
    cout<<"The age of p2 = "<<p2.age<<endl;
}

int main(){
    //test01();
    test02();
    return 0;
}