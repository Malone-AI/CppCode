#include <iostream>
using namespace std;

int func2(int a,int b,int c);
//函数默认参数

//如果我们自己传入参数,就用我们传入的参数;如果我们不传入,就用默认值
//语法 函数返回值 函数名(形参=默认值)

int func(int a,int b=20,int c=30){
    return a+b+c;
}

//注意事项
//1.如果函数的某一个参数有了默认值,那么这个参数之后的参数也必须有默认值

//2.如果函数的声明和函数实现就只能一个有默认参数,主要是为了防止声明和实现的默认参数的默认值不同

int func2(int a,int b=20,int c=30){
    return a+b+c;
}

int main(){
    cout<<func2(10,30)<<endl;
}