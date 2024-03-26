#include <iostream>
#include <string.h>
using namespace std;

//友元

//全局函数做友元

//建筑物类
class Building{
    //goodGay全局函数是Building好基友,可以访问Building中私有成员
    friend void goodGay(Building &building);
public:
    string SittingRoom;
    Building(){
        SittingRoom="客厅";
        BedRoom="卧室";
    }
private:
    string BedRoom;
};


//全局函数
void goodGay(Building &building){
    cout<<"好基友的全局函数 正在访问:"<<building.SittingRoom<<endl;
    cout<<"好基友的全局函数 正在访问:"<<building.BedRoom<<endl;
}

void test01(){
    Building building;
    goodGay(building);
}

int main(){

    test01();

    return 0;
}