#include <iostream>
using namespace std;

//引用:给变量取别名
//语法  数据类型 &别名=原名

//引用的注意事项
//引用的使用必须初始化,也就是必须说明是谁的别名
//引用初始化后不可再初始化,就是说一旦指定它是谁的别名以后就不能更改为其它变量的别名

int main(){
    int a=520;
    int &b=a;
    b=1314;
    cout<<a<<endl;
    cout<<b<<endl;
    b=59+1;
    cout<<a<<endl;
    cout<<b<<endl;
}