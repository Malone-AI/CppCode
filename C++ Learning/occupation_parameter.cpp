#include <iostream>
using namespace std;

//函数占位参数

//语法:返回值类型 函数名(数据类型)

//占位参数可以有默认值
//比如void func(int a,int = 10)

void func(int a,int){
    cout<<"This is a func."<<endl;
}

int main(){
    func(10,100);
    return 0;
}