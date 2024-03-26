#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#if 0
void MySwap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void MySwap(double &a,double &b){
    double temp=a;
    a=b;
    b=temp;
}
#endif

template<class T>//template<typename T>两种写法均可,这一行只管紧挨着它下面的一个函数,多个参数   template<class T1,class T2,...>
void MySwap(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}

void test01(){
    int a=10;
    int b=20;
    //1.自动类型推导
    cout<<" a = "<<a<<" b = "<<b<<endl;
    MySwap(a,b);//编译器根据你传入的值进行自动类型转换
    cout<<"交换后:"<<endl;
    cout<<" a = "<<a<<" b = "<<b<<endl;

    cout<<endl;

    double da=1.13;
    double db=3.14;
    cout<<" da = "<<da<<" db = "<<db<<endl;
    MySwap(da,db);
    cout<<"交换后:"<<endl;
    cout<<" da = "<<da<<" db = "<<db<<endl;

}

void test02(){
    //2.显式的指定类型
    int a=14;
    int b=13;
    cout<<" a = "<<a<<" b = "<<b<<endl;
    MySwap<int>(a,b);
    cout<<"交换后:"<<endl;
    cout<<" a = "<<a<<" b = "<<b<<endl;
}

int main(){
    test01();
    cout<<endl;
    test02();
    return 0;
}