#include <iostream>
using namespace std;


//构造函数和析构函数

//对象的初始化与清理
//初始化->构造函数,类似于python class的__init__
//清理->析构函数,类似于python class的__del__

//构造函数语法  
//1.没有返回值也不用写void
//2.构造函数名称与类名相同
//3.构造函数可以有参数,因此可以重载
//4.构造函数在对象被创建时会自动调用一次,无需手动调用

//析构函数语法
//1.没有返回值也不用写void
//2.函数名称与类名相同,只是额外在前面加一个'~'
//3.析构函数不可以有参数,因此不能重载
//4.对象在销毁时会自动调用析构函数,无需手动调用

class Person{
public:
    Person(){
        cout<<"Person 的构造函数的调用"<<endl;
    }

    ~Person(){
        cout<<"Person 的析构函数的调用"<<endl;
    }
};

void test01(){
    Person p;//局部变量,函数执行完后自动销毁
}

//构造函数和析构函数都是必须有的实现,但是若我们不提供实现,编译器会自动添加,但是都是空实现

int main(){
    test01();
    Person p;
    system("pause");
}