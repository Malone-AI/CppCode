#include <iostream>
#include <vector>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid){
    //Target function
    int i,j;
    int mario[2],princess[2];
    int left,up;
    for(i = 0;i < n;i++)
        for(j = 0;j < n;j++){
            if(grid[i][j] == 'm'){
                mario[0] = i;
                mario[1] = j;
            }
            if(grid[i][j] == 'p'){
                princess[0] = i;
                princess[1] = j;
            }
        }
    up = princess[0] - mario[0];
    left = princess[1] - mario[1];
    if(up < 0){
        for(;up < 0;up++)
            cout<<"UP"<<endl;
    }else{
        for(;up > 0;up--)
            cout<<"DOWN"<<endl;
    }

    if(left < 0){
        for(;left < 0;left++)
            cout<<"LEFT"<<endl;
    }else{
        for(;left > 0;left--)
            cout<<"RIGHT"<<endl;
    }
}

int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}