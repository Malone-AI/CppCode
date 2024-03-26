#include <iostream>
using namespace std;

//函数重载的注意事项
//1.引用作为重载的条件
void func(int &a){
    cout<<"func(int &a)"<<endl;
}

void func(const int &a){
    cout<<"const func(int &a)"<<endl;
}

//2.函数重载遇到默认参数
//void func(int a,int b=10){
//    cout<<"func(int a=10)"<<endl;
//}

int main(){
    int a=10;
    //func(20);
    //func();
    //return 0;
    func(10);
    func(a);
}