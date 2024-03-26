#include <iostream>
#include <string.h>
using namespace std;

//类做友元
class Building;
class GoodGay{
public:
    void visit();//参观函数 访问Building中的属性
    Building *building;
    GoodGay();
};

class Building{
    //GoodGay类是该类的好基友，可以访问本类中私有成员
    friend class GoodGay;
public:
    string SittingRoom;//客厅
    Building();
private:
    string BedRoom;//卧室
};

//类外写成员函数
Building::Building(){
    SittingRoom="客厅";
    BedRoom="卧室";
}

GoodGay::GoodGay(){
    building=new Building;
}

void GoodGay::visit(){
    cout<<"好基友类正在访问:"<<building->SittingRoom<<endl;
    cout<<"好基友类正在访问:"<<building->BedRoom<<endl;
}

void test01(){
    GoodGay gg;
    gg.visit();
}

int main(){
    test01();
    return 0;
}