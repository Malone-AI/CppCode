#include<iostream>
using namespace std;

/*string的构造*/
void test(){
    /*无参构造*/
    string str = string();
    cout<<str<<endl;

    string str2 = string("Hello world!");
    cout<<str2<<endl;

    const char* array = "Hello world";

    string str3 = string(array);
    cout<<str3<<endl;

    string str4 = string(4,'A');
    cout<<str4<<endl;
}

/*string的赋值*/
void test02(){
    string str;
    str = "Hello world!";
    const char* array2 = "Hello world!";
    string str2 = array2;
    cout<<str<<endl<<str2<<endl;

    str.assign("Malone");
    cout<<str<<endl;

    str.assign(str2);
    cout<<str<<endl;

    str.assign(array2);
    cout<<str<<endl;

    str.assign(4,'a');
    cout<<str<<endl;/*"aaaa"*/

    str.assign("Malone",3);
    cout<<str<<endl;/*"Mal"*/

    str.assign("Malone",3,5);
    cout<<str<<endl;/*"one"*/
}

/*string的存取*/
void test03(){
    string str = "Hello world!";
    cout << str[4] << endl;
    cout << str.at(4) << endl;
    char& c = str[4];
    c = '!';
    cout << str << endl;
    c = 'o';
    /*c_str将C++风格的string转换成C风格的字符串(返回C++的string类中维护的字符数组指针)*/
    cout << (int*)str.c_str() << endl;
    str = "123456789012345";
    cout << (int*)str.c_str() << endl;
    c = 'A';
    cout << str << endl;/*上一行的操作不生效*/
}

/*string的拼接*/
void test04(){
    string str = "Hello";
    string str1 = str + "world!";
    //string str2 = "str" + "world!";
    cout << str1 << endl;

    str += " world!";
    cout << str << endl;

    str.append(" Malone!");
    cout << str << endl;

    str.append("This",2);
    cout << str << endl;

    str.append("This",2,2);
    cout << str << endl;

    str.append(4,' ');
    cout << str << endl;
}

int main(){
    test();
    cout<<"-----------"<<endl;
    test02();
    cout<<"-----------"<<endl;
    test03();
    cout<<"-----------"<<endl;
    test04();
    cout<<"-----------"<<endl;
    return 0;
}