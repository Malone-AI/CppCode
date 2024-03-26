#include <iostream>
using namespace std;

//空指针访问成员函数    但是要注意有没有用this指针
//空指针 即指向对象的指针为空时,可以调用对象的成员函数,但是不能访问成员变量
class Person{
public:
    int age;
    void showClassName(){
        cout<<"This is Person class"<<endl;
    }

    void showPersonAge(){
        //为了防止代码崩掉,增加这一判断条件
        if(this==nullptr){
            return ;
        }
        cout<<"age = "<<age<<endl;//age相当于this->age
    }
};

void test01(){
    Person *p=nullptr;
    p->showClassName();//不报错
    p->showPersonAge();//报错,因为传入的指针为空
}

int main(){
    test01();
    system("pause");
    return 0;
}