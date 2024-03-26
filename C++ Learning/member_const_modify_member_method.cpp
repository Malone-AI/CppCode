#include <iostream>
using namespace std;

//const修饰成员函数

//常函数
class Person{
public:
    int age=18;
    mutable int b=520;//特殊变量,即使在常函数中,也可以修改它的值,加关键字mutable
    //this指针的本质 是指针常量->指针的指向是不可以修改的
    //Person * const this//此时是可以修改指针指向的内容
    //为了让指针指向的内容也不可修改改成 const Person * const this
    //在成员函数后面加上const,修饰的是this指向,让指针指向的值也不可修改
    void showPerson()const{
        //age=100;//相当于this->age=100
        //this=nullptr;//this指针不可以修改指针的指向
        b=100;
    }
    void func(){

    }

};

void test01(){
    Person p;
    p.showPerson();
    //常函数只能调用常对象
    p.func();
}

//常对象
void test02(){
    const Person p;//在对象前加上const,变为常对象
    //p.age=100;//age不可修改
    p.b=200;//b加了mutable关键字,是特殊的变量,在常对象下也可以修改

    //常函数只能调用常对象
    //p.func();
    p.showPerson();
}

int main(){
    return 0;
}