#include <iostream>
using namespace std;

//点类
class Point{
private:
    int X;
    int Y;
public:
    void setX(int x){
        X=x;
    }
    void setY(int y){
        Y=y;
    }
    int getX(){
        return X;
    }
    int getY(){
        return Y;
    }
};

//圆类
class Circle{
private:
    int R;
    Point o;
public:
    void setR(int r){
        R=r;
    }
    int getR(){
        return R;
    }
//Circle对象嵌套一个Point对象,不再额外定义这些方法,直接使用Point的方法
//    void setX(int x){
//        o.setX(x);
//    }
//    void setY(int y){
//        o.setY(y);
//    }
//    int getX(){
//        return o.getX();
//    }
//    int getY(){
//        return o.getY();
//    }
    //获取圆心对象
    Point getO(){
        return o;
    }
    void isInCircle(Point &p1){
        //成员函数判断
        int distance2=(o.getX()-p1.getX())*(o.getX()-p1.getX())+(o.getY()-p1.getY())*(o.getY()-p1.getY());
        if(distance2<R*R){
            cout<<"点在圆内"<<endl;
        }else if(distance2==R*R){
            cout<<"点在圆上"<<endl;
        }else{
            cout<<"点在圆外"<<endl;
        }
    }
};

//全局函数
void isInCircle(Circle &c,Point &p){
    Point o=c.getO();
    int distance2=(o.getX()-p.getX())*(o.getX()-p.getX())+(o.getY()-p.getY())*(o.getY()-p.getY());
    if(distance2<c.getR()*c.getR()){
        cout<<"点在圆内"<<endl;
    }else if(distance2==c.getR()*c.getR()){
        cout<<"点在圆上"<<endl;
    }else{
        cout<<"点在圆外"<<endl;
    }
}

int main(){
    Circle c;
    c.setR(3);
    c.getO().setX(0);
    c.getO().setY(0);
    Point p;
    p.setX(0);
    p.setY(3);
    c.isInCircle(p);
    isInCircle(c,p);
    return 0;
}