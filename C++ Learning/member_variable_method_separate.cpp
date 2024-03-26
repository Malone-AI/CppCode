#include <iostream>
using namespace std;

//成员变量 和 成员对象 是分开存储的

class Person{
    //空对象的内存为1,有非静态成员时内存为所有非静态成员的内存之和
    //非静态成员变量属于类对象上
    int m_A;
    //静态成员变量不属于类对象上
    static int m_B;

    void func(){
        //非静态成员函数不属于类对象上
    }
    
    static void func02(){
        //静态成员函数不属于类对象上
    }
};

int Person::m_B=0;

void test01(){
    //空对象占用的内存:1
    //C++编译器会给每个对象分配1个字节的空间,是为了区分空对象占内存的位置
    //每个空对象也有一个独一无二的内存
    Person p;
    cout<<"Size of p = "<<sizeof(p)<<endl;
}

void test02(){
    Person p;
    cout<<"Size of p = "<<sizeof(p)<<endl;
}

int main(){
    //test01();
    test02();
    return 0;
}