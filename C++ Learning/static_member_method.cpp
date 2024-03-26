#include <iostream>
using namespace std;

//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量

class Person{
public:
    //静态成员函数
    static void func(){
        m_A=100;
        //m_B=200;//静态成员函数只能访问静态变量,因为无法区分是哪个对象的m_B
        cout<<"static void func调用"<<endl;
    }
    int m_B;
    //静态成员变量
    static int m_A;

    //静态成员函数也是有访问权限的
private:
    static void func2(){
        cout<<endl;
    }
};

int Person::m_A=0;

void test01(){
    //静态成员函数的访问方式
    //1.通过对象访问
    Person p;
    p.func();
    //2.通过类名访问
    Person::func();
    //Person::func2();//类外访问不到private的静态成员函数
}

int main(){
    test01();
    return 0;
}