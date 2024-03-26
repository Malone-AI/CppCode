#include <iostream>
using namespace std;

//this指针

class Person{
public:
    int age;
    Person(int age){
        //age=age;//无法正确赋值
        //this指针指向的是被调用成员函数所属的成员对象
        this->age=age;
    }
    Person& PersonAddAge(Person &p){
        this->age+=p.age;
        //this指向本对象的指针,*this指向本对象本身
        return *this;
    }
};
//1.解决名称冲突
void test01(){
    Person p1(18);
    cout<<"The age of p1 = "<<p1.age<<endl;
}

//2.返回对象本身用*this
void test02(){
    Person p1(10);
    Person p2(10);
    //链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    cout<<"The age of p2 = "<<p2.age<<endl;
}

int main(){
    //test01();
    test02();
    return 0;
}