#include <iostream>
#include <string>
using namespace std;

int division(int a,int b){
    if(b == 0)
        throw 0;
    return a / b;
}

void calculate(int a,int b){
    try{
        cout << division(a,b) << endl;
    }catch(int){
        cout << "除数不能为0!" << endl;
    }
}

int main(){
    calculate(4,2);
    calculate(4,0);
    return 0;
}