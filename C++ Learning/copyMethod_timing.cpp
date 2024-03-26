#include <iostream>
using namespace std;

//拷贝构造函数的使用时机

class Person{
public:
    int age;

    Person(){
        cout<<"Person的默认构造函数的调用."<<endl;
    }
    Person(int m){
        age=m;
        cout<<"Person的有参构造函数的调用."<<endl;
    }
    Person(const Person &p){
        cout<<"Person的拷贝构造函数的调用."<<endl;
        age=p.age;
    }

    ~Person(){
        cout<<"Person的析构函数的调用."<<endl;
    }
};

//1.使用一个已经创建完毕的对象来初始化新对象时
void test01(){
    Person p1(18);
    Person p2(p1);//括号法
    cout<<"The age of p2 ="<<p2.age<<endl;
}

//2.值传递的方式给函数参数传值
void doWork(Person p){

}

void test02(){
    Person p;
    doWork(p);
}

//3.值方式返回局部对象
Person doWork2(){
    Person p1;
    cout<<(int*)&p1<<endl;
    return p1;
}

void test03(){
    Person p=doWork2();
    cout<<(int*)&p<<endl;
}

int main(){
    //test01();
    //test02();
    test03();
    return 0;
}