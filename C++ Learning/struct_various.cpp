#include <iostream>
using namespace std;

//构造函数的分类及调用
//一.分类
//按照参数分类  有参构造 和 无参构造(默认构造)
//按照分类
class Person{
public:
    //构造函数
    Person(){
        cout<<"Person的无参构造函数调用"<<endl;
    }
    
    Person(int a){
        age=a;
        cout<<"Person的有参构造函数调用"<<endl;
    }

    //拷贝构造函数
    Person(const Person &p){
        //把对象p的所有属性复制一份给调用的对象
        age=p.age;
        cout<<"Person的拷贝构造函数调用"<<endl;
    }

    //析构函数
    ~Person(){
        cout<<"Person的析构函数调用"<<endl;
    }
    int age;
};

//调用
void test01(){
    //1.括号法
    //Person p1;//默认构造函数的调用
    //Person p2(10);//有参构造函数调用
    //Person p3(p2);//拷贝构造函数的调用

//    cout<<"p2的年龄:"<<p2.age<<endl;
//    cout<<"p3的年龄:"<<p3.age<<endl;
    //注意事项:
    //调用默认构造函数时不要+()
    //Person p(); 这一行代码会被识别为函数声明

    //2.显示法
    //Person p4;//无参构造
    //Person p5=Person(10);//有参构造
    //Person p6=Person(p5);//拷贝构造

    //Person(10);//匿名对象     特点:当前行执行结束后系统会立即回收掉匿名对象
    //cout<<"aaa"<<endl;    上一行匿名对象的析构函数调用先于该行

    //不要利用拷贝构造函数初始化匿名对象 
    //Person(p6);直接报错:p6重定义  编译器会认为 Person (p6)==Person p6

    //3.隐式转换法
    Person p4=10;   //相当于Person p4=Person(10)    有参构造
    Person p5=p4;   //拷贝构造
}


int main(){
    test01();
    return 0;
}