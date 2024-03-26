#include <stdio.h>

void InsertSort(int A[],int n){
    /*插入排序*/
    int i ,j;
    for(i = 1;i < n;i++){
        int tmp = A[i];
        for(j = i - 1;j >= 0 && A[j] > tmp;j-- )
            A[j+1] = A[j];
        A[j+1] = tmp;
    }
}

int main(){
    int A[6] = {4,5,2,3,1,6};
    InsertSort(A,6);
    return 0;
}