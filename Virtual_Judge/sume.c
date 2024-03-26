#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    int A[N];
    int i,j,tmp;
    for(i = 0;i < N;i++){
        A[i] = 0;
    }
    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            scanf("%d",&tmp);
            A[j] += tmp;
        }
    }
    tmp = 0;
    for(i = 0;i < N;i++){
        tmp += A[i];
    }
    tmp /= (2 * N - 2);
    for(i = 0;i < N;i++){
        A[i] = ( A[i] - tmp ) / (N - 2);
        printf("%d ",A[i]);
    }
}