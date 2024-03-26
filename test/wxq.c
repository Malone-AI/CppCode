#include <stdio.h>
int main(){
    int min,q,x;
    float km;
    scanf("%f %d",&km,&min);
    x=min/5*2;
    if(km<=3){
        q=x+10;
    }else if(km>3&&km<=10){
        q=x+10+(km-3)*2+0.5;
    }else{
        q=x+10+2*7+(km-10)*3;
    }
    printf("%d",q);
    return 0;
}