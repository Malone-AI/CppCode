#include <iostream>
using namespace std;

//引用做函数的返回值

//注意事项

//1.不要返回局部变量的引用,编译器只会队局部变量的引用做一次保留
//int& test01(){
//    int a=10;//局部变量,存在内存四区中的栈区,函数调用结束后自动释放
//    return a;
//}

//2.函数的调用可以作为左值,就是说如果函数的返回值是引用,那么这个函数可以做等号左边的值
int& test02(){
    static int a=10;//静态变量,存放在全局区,程序结束后自动释放
    return a;
}

int main(){
    int &ref=test02();

    //cout<<"ref = "<<ref<<endl;
    //cout<<"ref = "<<ref<<endl;
    //cout<<"ref = "<<ref<<endl;

    cout<<"ref = "<<ref<<endl;
    cout<<"ref = "<<ref<<endl;

    test02()=1000;//test02()返回的是静态变量a的引用,ref又是a的别名,所以这行语句后ref的也变了

    cout<<"ref = "<<ref<<endl;
    cout<<"ref = "<<ref<<endl;

    return 0;
}