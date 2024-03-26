#include <stdio.h>

void ShellSort(int A[],int n);

void ShellSort(int A[],int n){
    int i,j,d;
    for(d = n / 2;d >= 1;d /= 2){
        for(i = d + 1;i <= n;i++){
            if(A[i-d] > A[i]){
                A[0] = A[i];
                for(j = i - d;j > 0 && A[j] > A[0];j -= d)
                    A[j+d] = A[j];
                A[j+d] = A[0];
            }
        }
    }
}

int main(){
    int A[6] = {0,2,5,1,3,6};
    ShellSort(A,5);
    return 0;
}