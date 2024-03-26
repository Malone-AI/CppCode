#include <stdio.h>

typedef char datatype;
typedef struct{
    int key;
    datatype data;
}rectype;

void InsertSort(rectype R[],int n);

void InsertSort(rectype R[],int n){
    int i;
    for(i = 2;i <= n;i++){
        if(R[i-1].key > R[i].key){
            R[0] = R[i];/*R[0]是哨兵*/
            int j = i - 1;
            while(R[j].key > R[0].key){
                R[j+1] = R[j];
                j--;
            }
            R[j+1] = R[0];
        }
    }
}

int main(){
    rectype A[7];
    A[1].key = 5;
    A[2].key = 2;
    A[3].key = 1;
    A[4].key = 3;
    A[5].key = 6;
    A[6].key = 4;
    InsertSort(A,6);
    return 0;
}