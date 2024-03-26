#include <iostream>
#include <string>
using namespace std;

//成员属性的私有化
//1、自己控制读写权限
//2、对于写可以检测数据是否有效

class Person{
public:
    void setName(string s){
        name=s;
    }

    string getName(){
        return name;
    }

    int getAge(){
        age=18;
        return age;
    }

    void setLover(string love){
        lover=love;
    }

private:
    string name;
    int age;
    string lover;

};

int main(){
    Person p;
    p.setName("Malone");
    cout<<"Name = "<<p.getName()<<endl;
    cout<<"Age = "<<p.getAge()<<endl;
    p.setLover("CJK");
    return 0;
}