#include <iostream>
using namespace std;

//函数重载
//函数重载就像是多音字一样

//需要满足以下条件
//1.同一个作用域下,比如全局作用域
//2.函数名称相同
//3.函数参数类型不同,或者参数前后顺序不同或者参数个数不同

//函数返回值不同不可以重载

void func(){
    cout<<"This is a func."<<endl;
}

void func(int a){
    cout<<"This is a func!"<<endl;
}

int main(){
    func();
    func(10);
    func();
    return 0;
}