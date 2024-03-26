#include <iostream>
using namespace std;

//立方体类型
//1.获取立方体的面积和体积
//2.用全局函数和成员函数判断两个立方体是否相等

class Cube{
public:
    void set_len(int l){
        len=l;
    }
    void set_width(int w){
        width=w;
    }
    void set_height(int h){
        height=h;
    }
    int getLen(){
        return len;
    }
    int getWidth(){
        return width;
    }
    int getHeight(){
        return height;
    }
    int square(){
        return (len*width+len*height+width*height)*2;
    }
    int volumn(){
        return len*width*height;
    }
    bool isSame(Cube &c){
        //成员函数判断是否相等
        return c.getLen()==len&&c.getWidth()==width&&c.getHeight()==height;
    }
private:
    int len;
    int width;
    int height;
};

//全局函数
bool isSame(Cube &c1,Cube &c2){
    return c1.getLen()==c2.getLen()&&c1.getWidth()==c2.getWidth()&&c1.getHeight()==c2.getHeight();
}

int main(){
    Cube c1,c2;
    c1.set_len(3);
    c1.set_width(4);
    c1.set_height(5);
    c2.set_len(3);
    c2.set_width(4);
    c2.set_height(5);
    cout<<"The square of the c1 is "<<c1.square()<<endl;
    cout<<"The square of the c2 is "<<c2.square()<<endl;
    cout<<"The volumn of the c1 is "<<c1.volumn()<<endl;
    cout<<"The volumn of the c2 is "<<c2.volumn()<<endl;
    //成员函数
    if(c1.isSame(c2)){
        cout<<"c1 and c2 is the same."<<endl;
    }
    c2.set_len(8);
    if(!c2.isSame(c1)){
        cout<<"c2 and c1 is different."<<endl;
    }
    if(!isSame(c1,c2)){
        cout<<"c1 and c2 is different."<<endl;
    }
    return 0;
}