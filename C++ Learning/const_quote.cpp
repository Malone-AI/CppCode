#include <iostream>
using namespace std;

//常量引用
//使用场景,用来修饰形参,防止误操作

void showValue(const int &val){
    //val=1000;//在这里修改,传入的变量的值也会改变,因为引用的本质是指针常量
    cout<<"value = "<<val<<endl;
}

int main(){

    //int &ref=10;引用必须引一块儿合法的内存空间

    //加上const以后编译器自动修改代码,修改为int temp=10;const int &ref=temp;
    //const int &ref=10;
    //ref=20;加入const后只读,不可修改

    int a=100;
    showValue(a);
}