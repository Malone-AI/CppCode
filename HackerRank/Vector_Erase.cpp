#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i,tmp,m;
    vector<int> num;
    cin >> n;
    for(i = 0;i < n;i++){
        cin >> tmp;
        num.push_back(tmp);
    }
    cin >> n;
    num.erase(num.begin() + n );
    cin >> n >> m;
    num.erase(num.begin() + n,num.begin() + m);
    cout << num.size() << endl;
    for(auto &i:num)
        cout << i << " ";
    return 0;
}
