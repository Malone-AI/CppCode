#include <iostream>
using namespace std;

//函数模板和普通函数的区别

template<class T>
int MyAdd(T &a,T &b){
    cout<<"Template method calling"<<endl;
    return a+b;
}

int MyAdd(int &a,int &b){
    cout<<"Normal method calling"<<endl;
    return a+b;
}

void test02(){
    int a=10;
    int b=20;
    char c='a';
    char d='b';
    //cout<<MyAdd(a,c)<<endl;
    cout<<MyAdd(a,b)<<endl;//调用的是Normal method
    cout<<MyAdd(c,d)<<endl;
    //cout<<MyAdd(c,a)<<endl;//
}

//函数模板可以像普通函数一样重载
template<class T>
void Print(T a){

}

template<class T>
void Print(T a,T b){

}

//C++编译器优先考虑普通函数的调用
//调用时使用模板函数的显式指定类型可以优先模板函数

int main(){
    test02();
    return 0;
}