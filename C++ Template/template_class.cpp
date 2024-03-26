#include <iostream>
using namespace std;

//类模板
template<class T>
class Person{
public:
    T mId;
    T mAge;
public:
    Person(T id,T age){
        mId=id;
        mAge=age;
    }

    void show(){
        cout<<"ID:"<<mId<<endl;
        cout<<"age:"<<mAge<<endl;
    }
};

void test01(){
    //类模板必须显示指定类型
    Person<int> p(10,20);
    p.show();
}

int main(){
    test01();
    return 0;
}