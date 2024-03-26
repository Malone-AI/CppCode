#include <iostream>
#include <algorithm>
using namespace std;

//继承
class BasePage{
public:
    void header(){
        cout << "...(公共头部)" << endl;
    }
    void footer(){
        cout << "...(公共底部)" << endl;
    }
    void list(){
        cout << "...(公共列表)" << endl;
    }
};

class Java:public BasePage{
public:
    void content(){
        cout << "Java" << endl;
    }
};

class Python:public BasePage{
public:
    void content(){
        cout << "Python" << endl;
    }
};

class Cpp:public BasePage{
public:
    void content(){
        cout << "C++" << endl;
    }
};

int main(){
    Java ja;
    ja.content();
    ja.header();
    ja.footer();
    ja.list();

    Python py;
    py.content();
    py.header();
    py.footer();
    py.list();

    Cpp cpp;
    cpp.content();
    cpp.header();
    cpp.footer();
    cpp.list();

    return 0;
}