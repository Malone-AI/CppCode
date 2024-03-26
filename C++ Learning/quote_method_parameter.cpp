#include <iostream>
using namespace std;

//交换两个值的函数

//1.值传递
void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}

//2.指针传递
void swap01(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//3.引用传递
void swap02(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

int main(){
    int a=3;
    int b=4;
    cout<<"初始时"<<endl;
    cout<<"a = "<<a<<" b = "<<b<<endl;

    swap(a,b);
    cout<<"值传递函数"<<endl;
    cout<<"a = "<<a<<" b = "<<b<<endl;
    
    swap01(&a,&b);
    cout<<"指针传递函数"<<endl;
    cout<<"a = "<<a<<" b = "<<b<<endl;

    swap02(a,b);
    cout<<"引用传递函数"<<endl;
    cout<<"a = "<<a<<" b = "<<b<<endl;
}