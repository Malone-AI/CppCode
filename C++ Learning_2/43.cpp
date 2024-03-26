#include <iostream>
#include <algorithm>
using namespace std;

/*关系运算符重载*/
class Person{
private:
    string name;
    int age;
public:
    Person(string tmp1,int tmp2){
        this->name = tmp1;
        this->age = tmp2;
    }
    bool operator==(const Person &p){
        return this->name == p.name && this->age == p.age;
    }
    bool operator!=(const Person &p){
        return !(this->name == p.name && this->age == p.age);
    }
};

int main(){
    Person p1("Tom",18);
    Person p2("Tom",20);
    if(p1 == p2)
        cout << "p1 == p2" << endl;
    else
        cout << "p1 != p2" << endl;

    if(p1 != p2)
        cout << "p1 != p2" << endl;
    else
        cout << "p1 == p2" << endl;
}