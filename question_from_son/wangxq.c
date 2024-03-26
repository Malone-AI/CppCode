#include <stdio.h>
int main(){
    int i,n=1,sum=0;
    for(i=0;n!=0;i++){
        scanf("%d",&n);
        if(n%2!=0){
            sum+=n;
        }
    }
    printf("%d",sum);
    return 0;
}