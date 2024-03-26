#include <iostream>
using namespace std;

//深拷贝与浅拷贝
//面试常考!!!!!!!!!!!!!!!!
//总结:如果内存有在堆区开辟的,一定要自己实现拷贝构造函数,防止浅拷贝带来问题
class Person{
public:
    int m_age;
    int *m_height;
    Person(){
        cout<<"Person的默认构造函数调用"<<endl;
    }
    Person(int age,int height){
        m_age=age;
        m_height=new int(height);//new int()创建一个对象并为该对象创建内存空间,并且返回指向该内存的指针，
        cout<<"Person的有参构造函数调用"<<endl;
    }
    //自己实现拷贝构造函数实现深拷贝来解决浅拷贝问题
    Person(const Person &p){
        m_age=p.m_age;
        //m_height=p.m_height;//编译器提供的拷贝构造函数,也就是浅拷贝
        cout<<"Person的拷贝构造函数调用"<<endl;
        //深拷贝
        m_height=new int(*p.m_height);//new int 有参数时开辟的内存存放参数的值,没有参数时内存存放的值为0
    }
    ~Person(){
        //析构代码,将堆区开辟的数据做释放操作
        if(m_height!=NULL){
            delete m_height;
            m_height=NULL;
        }//加上if里中的代码后有一个释放的操作,我们没有写拷贝构造函数,用的是系统写的,但是拷贝的时候会把指针指向的内存也原封不动地拷贝过去,与就是说通过拷贝构造函数p2的m_height与p1的m_height指向了相同的内存的空间;test01()调用的时候是把变量放到栈里面,所以p2先被释放,这个时候会调用析构函数,m_height指向不为空,所以会释放掉m_height指向的空间;然后会释放掉p1,也会调用析构函数,但是此时p1的m_height也不为空,并且它指向的内存与p2释放前m_height的内存相同,p1的析构函数也会对同一块内存做一次释放,也就是重复释放了
        //浅拷贝带来的问题就是堆区的内存重复释放,利用深拷贝解决该问题
        //就是拷贝的时候让p2的m_height指向与p1的m_height不同的内存空间

        cout<<"Person的析构函数调用"<<endl;
    }
};

void test01(){
    Person p1(18,160);
    cout<<"The age of p1 = "<<p1.m_age<<endl<<"The height of p1 = "<<*p1.m_height<<endl;
    Person p2(p1);//虽然我们没有写拷贝构造函数但是编译器帮我们写了,并且是浅拷贝
    cout<<"The age of p2 = "<<p2.m_age<<endl<<"The height of p2 = "<<*p2.m_height<<endl;
}

int main(){
    test01();
    return 0;
}