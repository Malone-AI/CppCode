#include<iostream>
#include<string>
using namespace std;

class Student{
public:
    long long ID;
    string name;
    void setID(){
        cin>>ID;
    }
    void setName(){
        cin>>name;
    }
    void printID(){
        cout<<"学号是"<<ID<<endl;
    }
    void printName(){
        cout<<"姓名是"<<name<<endl;
    }
};

int main(){
    Student s1;
    s1.setName();
    s1.setID();
    s1.printName();
    s1.printID();
}