#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int find(int x){
    if(vec[x]!=x){
        vec[x]=find(vec[x]);
    }
    return vec[x];
}

int main(){
    int n,k;
    cin>>n>>k;

    for(int i=0;i<=n;i++){
        vec.push_back(i);
    }
    
    int d,x,y;

    int lie=0;

    while(k--){
        cin>>d>>x>>y;
        if(d==1){
            vec[find(x)]=find(y);
        }else if(find(x)!=find(y)){
            lie++;
        }
        if(x>n||y>n){
            lie++;
        }
    }

    cout<<lie<<endl;
}