#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> num = {1,2,3,5,6};
    vector<int>::iterator low = lower_bound(num.begin(),num.end(),4);
    cout << low - num.begin() << endl;
}