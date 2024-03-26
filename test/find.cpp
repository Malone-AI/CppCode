#include <iostream>
using namespace std;

const int N=10010;

int p[N];

int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    int a,b;
    while(m--){
        cin>>a>>b;
        p[find(a)]=find(b);
    }
    return 0;
}