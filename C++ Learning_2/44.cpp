#include <iostream>
#include <algorithm>
using namespace std;

//函数调用运算符"()"重载
//又称为仿函数
class MyAdd{
public:
    int operator()(int n1,int n2){
        return n1 + n2;
    }
};

int main(){
    MyAdd myadd;
    int ret = myadd(13,14);
    cout << ret << endl;
    //匿名函数对象
    cout << MyAdd()(5,20) << endl;
    return 0;
}